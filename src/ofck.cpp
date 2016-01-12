//------------------------------------------------------------------------------
// name: ofck.cpp
// desc: openframeworks <=> ChucK bridge
//
// @author  Ge Wang
// @author  Tim O'Brien
// @author  Kitty Shi
// @author  Madeline Huberth
//
// @date    Fall 2015
//------------------------------------------------------------------------------
#include "ofck.h"
#include "chuck_dl.h"
#include "chuck_def.h"
#include "chuck_type.h"
#include "chuck_instr.h"
#include "chuck_vm.h"
#include "chuck_compile.h"
#include "ofxChucK.h"
#include "ofck-entities.h"

// general includes
#include <stdio.h>
#include <limits.h>
using namespace std;

// static instantiation
OFCKDB * OFCKDB::ourInstance = NULL;

// VREntity
CK_DLL_CTOR(vrentity_ctor);
CK_DLL_DTOR(vrentity_dtor);
CK_DLL_MFUN(vrentity_getLocation);
CK_DLL_MFUN(vrentity_setLocation);
CK_DLL_MFUN(vrentity_getRotation);
CK_DLL_MFUN(vrentity_setRotation);
CK_DLL_MFUN(vrentity_getScaling);
CK_DLL_MFUN(vrentity_setScaling);
CK_DLL_MFUN(vrentity_getRGB);
CK_DLL_MFUN(vrentity_setRGB);
CK_DLL_MFUN(vrentity_getRGBA);
CK_DLL_MFUN(vrentity_setRGBA);
CK_DLL_MFUN(vrentity_addChild);
CK_DLL_MFUN(vrentity_removeEntity);
CK_DLL_MFUN(vrentity_setString);
CK_DLL_MFUN(vrentity_getString);

// VR
CK_DLL_SFUN(vr_getEntity);
CK_DLL_SFUN(vr_setInt);
CK_DLL_SFUN(vr_getInt);
CK_DLL_SFUN(vr_setFloat);
CK_DLL_SFUN(vr_getFloat);
CK_DLL_SFUN(vr_setString);
CK_DLL_SFUN(vr_getString);
CK_DLL_SFUN(vr_setVec3);
CK_DLL_SFUN(vr_getVec3);
CK_DLL_SFUN(vr_setVec4);
CK_DLL_SFUN(vr_getVec4);
CK_DLL_SFUN(vr_setFOV);
CK_DLL_SFUN(vr_getFOV);
CK_DLL_SFUN(vr_displaySync);
CK_DLL_SFUN(vr_loadImage);
CK_DLL_SFUN(vr_makeEntity);


// internal data
t_CKINT vrentity_offset_cpointer = 0;
t_CKINT vrentity_offset_location = 0;
t_CKINT vrentity_offset_rotation = 0;
t_CKINT vrentity_offset_scaling = 0;
t_CKINT vrentity_offset_rgba = 0;

// hold vr entity type
static Chuck_Type * the_vrentity_type = NULL;




//------------------------------------------------------------------------------
// name: ofck_query()
// desc: query function -- chuck calls this when loading the Chugin
//------------------------------------------------------------------------------
DLL_QUERY ofck_query( Chuck_DL_Query * QUERY )
{
    // hmm, don't change this...
    QUERY->setname(QUERY, "VR");

    // begin the class definition
    QUERY->begin_class(QUERY, "VREntity", "Object");
    {
        // constructor
        QUERY->add_ctor(QUERY, vrentity_ctor);
        // destructor
        QUERY->add_dtor(QUERY, vrentity_dtor);
        
        // add .loc
        vrentity_offset_location = QUERY->add_mvar( QUERY, "vec3", "loc", FALSE );
        if( vrentity_offset_location == CK_INVALID_OFFSET ) goto error;

        // add .ori
        vrentity_offset_rotation = QUERY->add_mvar( QUERY, "vec3", "ori", FALSE );
        if( vrentity_offset_rotation == CK_INVALID_OFFSET ) goto error;

        // add .sca
        vrentity_offset_scaling = QUERY->add_mvar( QUERY, "vec3", "sca", FALSE );
        if( vrentity_offset_scaling == CK_INVALID_OFFSET ) goto error;

        // add .rgba
        vrentity_offset_rgba = QUERY->add_mvar( QUERY, "vec4", "rgba", FALSE );
        if( vrentity_offset_rgba == CK_INVALID_OFFSET ) goto error;

        // add .addChild
        QUERY->add_mfun(QUERY, vrentity_addChild, "void", "addChild" );
        // VREntity
        QUERY->add_arg(QUERY, "VREntity", "e" );

        // string VREntity.setString(key,value) // set
        QUERY->add_mfun(QUERY, vrentity_setString, "string", "setString");
        // name of object to retrieve
        QUERY->add_arg(QUERY, "string", "key");
        // name of object to retrieve
        QUERY->add_arg(QUERY, "string", "value");
        
        // string VR.getString(key,value) // set
        QUERY->add_mfun(QUERY, vrentity_getString, "string", "getString");
        // name of object to retrieve
        QUERY->add_arg(QUERY, "string", "key");
    }
    // end the class definition
    QUERY->end_class(QUERY);
    
    // begin the class definition
    QUERY->begin_class(QUERY, "VR", "Object");
    {
        // VRObject VR.object(name) // retrieve objects
        QUERY->add_sfun(QUERY, vr_getEntity, "VREntity", "getEntity");
        // name of object to retrieve
        QUERY->add_arg(QUERY, "string", "name");

        // int VR.setInt(key,value) // set
        QUERY->add_sfun(QUERY, vr_setInt, "int", "setInt");
        // name of object to retrieve
        QUERY->add_arg(QUERY, "string", "key");
        // name of object to retrieve
        QUERY->add_arg(QUERY, "int", "value");

        // float VR.setFloat(key,value) // set
        QUERY->add_sfun(QUERY, vr_getInt, "int", "getInt");
        // name of object to retrieve
        QUERY->add_arg(QUERY, "string", "key");

        // float VR.setFloat(key,value) // set
        QUERY->add_sfun(QUERY, vr_setFloat, "float", "setFloat");
        // name of object to retrieve
        QUERY->add_arg(QUERY, "string", "key");
        // name of object to retrieve
        QUERY->add_arg(QUERY, "float", "value");

        // float VR.getFloat(key,value) // set
        QUERY->add_sfun(QUERY, vr_getFloat, "float", "getFloat");
        // name of object to retrieve
        QUERY->add_arg(QUERY, "string", "key");
        
        // string VR.setString(key,value) // set
        QUERY->add_sfun(QUERY, vr_setString, "string", "setString");
        // name of object to retrieve
        QUERY->add_arg(QUERY, "string", "key");
        // name of object to retrieve
        QUERY->add_arg(QUERY, "string", "value");
        
        // string VR.getString(key,value) // set
        QUERY->add_sfun(QUERY, vr_getString, "string", "getString");
        // name of object to retrieve
        QUERY->add_arg(QUERY, "string", "key");

        // vec3 VR.setVec3(key,value) // set
        QUERY->add_sfun(QUERY, vr_setVec3, "vec3", "setVec3");
        // name of object to retrieve
        QUERY->add_arg(QUERY, "string", "key");
        // name of object to retrieve
        QUERY->add_arg(QUERY, "vec3", "value");
        
        // vec3 VR.getVec3(key,value) // set
        QUERY->add_sfun(QUERY, vr_getString, "vec3", "getVec3");
        // name of object to retrieve
        QUERY->add_arg(QUERY, "string", "key");

        // vec4 VR.setVec4(key,value) // set
        QUERY->add_sfun(QUERY, vr_setVec4, "vec4", "setVec4");
        // name of object to retrieve
        QUERY->add_arg(QUERY, "string", "key");
        // name of object to retrieve
        QUERY->add_arg(QUERY, "vec4", "value");
        
        // vec4 VR.getVec4(key,value) // set
        QUERY->add_sfun(QUERY, vr_getVec4, "vec4", "getVec4");
        // name of object to retrieve
        QUERY->add_arg(QUERY, "string", "key");
        
        // int VR.loadImage(key,filename) // load
        QUERY->add_sfun(QUERY, vr_loadImage, "int", "loadImage");
        // key of image to map
        QUERY->add_arg(QUERY, "string", "key");
        // filename of image to load
        QUERY->add_arg(QUERY, "string", "filename");

        // VREntity VR.makeEntity( type, name ) // event for display
        QUERY->add_sfun(QUERY, vr_makeEntity, "VREntity", "makeEntity");
        // key of image to map
        QUERY->add_arg(QUERY, "string", "key");
        // filename of image to load
        QUERY->add_arg(QUERY, "string", "type");

        // float VR.fov()
        QUERY->add_sfun(QUERY, vr_setFOV, "float", "fov");
        // name of object to retrieve
        QUERY->add_arg(QUERY, "float", "value");
        
        // float VR.fov()
        QUERY->add_sfun(QUERY, vr_getFOV, "float", "fov");

        // Event VR.displaySync // event for display
        QUERY->add_sfun(QUERY, vr_displaySync, "Event", "displaySync");

    }
    // end the class definition
    QUERY->end_class(QUERY);

    // wasn't that a breeze?
    return TRUE;
    
error:
    QUERY->end_class(QUERY);
    
    // done
    return FALSE;
}




//------------------------------------------------------------------------------
// VREntity chuck bindings
//------------------------------------------------------------------------------
CK_DLL_CTOR( vrentity_ctor )
{
    // nothing for now
}

CK_DLL_DTOR( vrentity_dtor )
{
    // nothing for now
}

CK_DLL_MFUN(vrentity_addChild)
{
    // get entity
    Chuck_Object * object = GET_NEXT_OBJECT(ARGS);
    // get the c VREntity pointer
    VREntity * me = (VREntity *)OBJ_MEMBER_INT(SELF,vrentity_offset_cpointer);
    // get the entity to add
    VREntity * rhs = (VREntity *)OBJ_MEMBER_INT(object,vrentity_offset_cpointer);
    // add it
    me->addChild( rhs );
}

//CK_DLL_MFUN(vrentity_removeChild);

CK_DLL_MFUN( vrentity_setString )
{
    std::string key = GET_NEXT_STRING(ARGS)->str;
    Chuck_String * value = GET_NEXT_STRING(ARGS);
    
    // get the c VREntity pointer
    VREntity * e = (VREntity *)OBJ_MEMBER_INT(SELF,vrentity_offset_cpointer);
    // set the string
    e->setString( key, value->str );
    // return the value
    RETURN->v_string = value;
}

CK_DLL_MFUN( vrentity_getString )
{
    // get the argument
    std::string key = GET_NEXT_STRING(ARGS)->str;
    // get the c VREntity pointer
    VREntity * e = (VREntity *)OBJ_MEMBER_INT(SELF,vrentity_offset_cpointer);
    // chuck string TODO: verify memory
    Chuck_String * str = (Chuck_String *)instantiate_and_initialize_object( &t_string, NULL );
    // set the string value
    str->str = e->getString(key);
    // return the value
    RETURN->v_string = str;
}


//------------------------------------------------------------------------------
// VRCamera chuck bindings
//------------------------------------------------------------------------------
CK_DLL_CTOR( vrcamera_ctor )
{
    // nothing for now
}

CK_DLL_DTOR( vrcamera_dtor )
{
    // nothing for now
}

CK_DLL_MFUN( vrcamera_fov )
{
    t_CKFLOAT value = GET_NEXT_FLOAT(ARGS);
}

CK_DLL_MFUN( vrcamera_lookAt )
{
    t_CKVEC3 value = GET_NEXT_VEC3(ARGS);
}

CK_DLL_MFUN( vrcamera_up )
{
    t_CKVEC3 value = GET_NEXT_VEC3(ARGS);
}

CK_DLL_SFUN( vr_getEntity )
{
    // get the argument
    std::string key = GET_NEXT_STRING(ARGS)->str;
    // get the DB
    OFCKDB * db = OFCKDB::instance();
    // look for the key in the DB
    VREntity * e = db->getObject(key);
    // check it
    if( !e ) { RETURN->v_object = 0; } else
    {
        // if necessary, instantiate chuck-side object
        if( e->chuckObject() == NULL ) { e->initChucKSideObject(); }
        // return the value
        RETURN->v_object = e->chuckObject();
    }
}

CK_DLL_SFUN( vr_setFloat )
{
    std::string key = GET_NEXT_STRING(ARGS)->str;
    t_CKFLOAT value = GET_NEXT_FLOAT(ARGS);
    // get the DB
    OFCKDB * db = OFCKDB::instance();
    // insert the key value pair, possibly overwriting
    RETURN->v_float = db->setFloat(key,value);
}

CK_DLL_SFUN( vr_getFloat )
{
    // get the argument
    std::string key = GET_NEXT_STRING(ARGS)->str;
    // get the DB
    OFCKDB * db = OFCKDB::instance();
    // look for the key in the DB
    RETURN->v_float = db->getFloat(key);
}

CK_DLL_SFUN( vr_setInt )
{
    std::string key = GET_NEXT_STRING(ARGS)->str;
    t_CKINT value = GET_NEXT_INT(ARGS);
    // get the DB
    OFCKDB * db = OFCKDB::instance();
    // insert the key value pair, possibly overwriting
    RETURN->v_int = db->setInt(key,value);
}

CK_DLL_SFUN( vr_getInt )
{
    // get the argument
    std::string key = GET_NEXT_STRING(ARGS)->str;
    // get the DB
    OFCKDB * db = OFCKDB::instance();
    // look for the key in the DB
    RETURN->v_int = db->getInt(key);
}

CK_DLL_SFUN( vr_setVec3 )
{
    std::string key = GET_NEXT_STRING(ARGS)->str;
    t_CKVEC3 value = GET_NEXT_VEC3(ARGS);
    // get the DB
    OFCKDB * db = OFCKDB::instance();
    // insert the key value pair, possibly overwriting
    RETURN->v_vec3 = db->setVec3(key,value);
}

CK_DLL_SFUN( vr_getVec3 )
{
    // get the argument
    std::string key = GET_NEXT_STRING(ARGS)->str;
    // get the DB
    OFCKDB * db = OFCKDB::instance();
    // look for the key in the DB
    RETURN->v_vec3 = db->getVec3(key);
}

CK_DLL_SFUN( vr_setVec4 )
{
    std::string key = GET_NEXT_STRING(ARGS)->str;
    t_CKVEC4 value = GET_NEXT_VEC4(ARGS);
    // get the DB
    OFCKDB * db = OFCKDB::instance();
    // insert the key value pair, possibly overwriting
    RETURN->v_vec4 = db->setVec4(key,value);
}

CK_DLL_SFUN( vr_getVec4 )
{
    // get the argument
    std::string key = GET_NEXT_STRING(ARGS)->str;
    // get the DB
    OFCKDB * db = OFCKDB::instance();
    // look for the key in the DB
    RETURN->v_vec4 = db->getVec4(key);
}

CK_DLL_SFUN( vr_loadImage )
{
    std::string key = GET_NEXT_STRING(ARGS)->str;
    std::string filename = GET_NEXT_STRING(ARGS)->str;
    // get the DB
    OFCKDB * db = OFCKDB::instance();
    // insert the key value pair, possibly overwriting
    RETURN->v_int = (db->loadImage(key, filename, false) != NULL);
}

CK_DLL_SFUN( vr_makeEntity )
{
    std::string key = GET_NEXT_STRING(ARGS)->str;
    std::string type = GET_NEXT_STRING(ARGS)->str;
    // make the entity
    VREntity * e = VREntityFactory::makeEntity(type);
    // check it
    if( !e ) { RETURN->v_object = 0; } else
    {
        // if necessary, instantiate chuck-side object
        if( e->chuckObject() == NULL ) { e->initChucKSideObject(); }
        // add to DB
        OFCKDB::instance()->setObject( key, e );
        // return the value
        RETURN->v_object = e->chuckObject();
    }
}

// float VR.fov( float )
CK_DLL_SFUN( vr_setFOV )
{
}

// float VR.fov()
CK_DLL_SFUN( vr_getFOV )
{
}

CK_DLL_SFUN( vr_setString )
{
    std::string key = GET_NEXT_STRING(ARGS)->str;
    Chuck_String * value = GET_NEXT_STRING(ARGS);
    
    // get the DB
    OFCKDB * db = OFCKDB::instance();
    // insert the key value pair, possibly overwriting
    db->string2string[key] = value->str;
    // return the value
    RETURN->v_string = value;
}

CK_DLL_SFUN( vr_getString )
{
    // get the argument
    std::string key = GET_NEXT_STRING(ARGS)->str;
    // get the DB
    OFCKDB * db = OFCKDB::instance();
    // chuck string TODO: verify memory
    Chuck_String * str = (Chuck_String *)instantiate_and_initialize_object( &t_string, NULL );
    // set the string value
    str->str = db->getString(key);
    // return the value
    RETURN->v_string = str;
}

CK_DLL_SFUN( vr_displaySync )
{
    // get the DB
    OFCKDB * db = OFCKDB::instance();
    // return the event
    RETURN->v_object = &(db->displaySync);
}




//------------------------------------------------------------------------------
// name: OFCKDB()
// desc: constructor
//------------------------------------------------------------------------------
OFCKDB::OFCKDB()
{
    initialize_object( &displaySync, &t_event );
    m_eventBuffer = TheChucK::instance()->vm()->create_event_buffer();
}




//------------------------------------------------------------------------------
// name: setInt()
// desc: associate a int value with a key
//------------------------------------------------------------------------------
t_CKINT OFCKDB::setInt( const std::string & key, t_CKINT value )
{
    // associate
    string2int[key] = value;
    // return
    return value;
}




//------------------------------------------------------------------------------
// name: getInt()
// desc: get a int value associated with a key
//------------------------------------------------------------------------------
t_CKINT OFCKDB::getInt( const std::string & key )
{
    // look for the key in the DB
    if( string2int.find(key) == string2int.end() )
    {
        // not found
        return 0;
    }

    // return the value
    return string2int[key];
}




//------------------------------------------------------------------------------
// name: setFloat()
// desc: associate a float value with a key
//------------------------------------------------------------------------------
t_CKFLOAT OFCKDB::setFloat( const std::string & key, t_CKFLOAT value )
{
    // associate
    string2float[key] = value;
    // return
    return value;
}




//------------------------------------------------------------------------------
// name: getFloat()
// desc: get a float value associated with a key
//------------------------------------------------------------------------------
t_CKFLOAT OFCKDB::getFloat( const std::string & key )
{
    // look for the key in the DB
    if( string2float.find(key) == string2float.end() )
    {
        // not found
        return 0;
    }
    
    // return the value
    return string2float[key];
}




//------------------------------------------------------------------------------
// name: setVec3()
// desc: associate a vec3 value with a key
//------------------------------------------------------------------------------
t_CKVEC3 OFCKDB::setVec3( const std::string & key, t_CKVEC3 value )
{
    // associate
    string2vec3[key] = value;
    // return
    return value;
}




//------------------------------------------------------------------------------
// name: getVec3()
// desc: get a vec3 value associated with a key
//------------------------------------------------------------------------------
t_CKVEC3 OFCKDB::getVec3( const std::string & key )
{
    // look for the key in the DB
    if( string2vec3.find(key) == string2vec3.end() )
    {
        // local instance
        t_CKVEC3 r;
        // zero out
        r.x = r.y = r.z = 0;
        // not found
        return r;
    }
    
    // return the value
    return string2vec3[key];
}




//------------------------------------------------------------------------------
// name: setVec4()
// desc: associate a vec4 value with a key
//------------------------------------------------------------------------------
t_CKVEC4 OFCKDB::setVec4( const std::string & key, t_CKVEC4 value )
{
    // associate
    string2vec4[key] = value;
    // return
    return value;
}




//------------------------------------------------------------------------------
// name: getVec4()
// desc: get a vec3 value associated with a key
//------------------------------------------------------------------------------
t_CKVEC4 OFCKDB::getVec4( const std::string & key )
{
    // look for the key in the DB
    if( string2vec4.find(key) == string2vec4.end() )
    {
        // local copy
        t_CKVEC4 r;
        // zero out
        r.x = r.y = r.z = r.w = 0;
        // not found
        return r;
    }
    
    // return the value
    return string2vec4[key];
}




//------------------------------------------------------------------------------
// name: setString()
// desc: associate a string value with a key
//------------------------------------------------------------------------------
std::string OFCKDB::setString( const std::string & key, const std::string & value )
{
    // associate
    string2string[key] = value;
    // return
    return value;
}




//------------------------------------------------------------------------------
// name: getString()
// desc: get a vec3 value associated with a key
//------------------------------------------------------------------------------
std::string OFCKDB::getString( const std::string & key )
{
    // look for the key in the DB
    if( string2string.find(key) == string2string.end() )
    {
        // not found
        return "";
    }
    
    // return the value
    return string2string[key];
}




//------------------------------------------------------------------------------
// name: setObject()
// desc: map object by name
//------------------------------------------------------------------------------
VREntity * OFCKDB::setObject( const string & key, VREntity * e )
{
    // associate
    string2entity[key] = e;
    // return
    return e;
}




//------------------------------------------------------------------------------
// name: getObject()
// desc: get an object associated with a key
//------------------------------------------------------------------------------
VREntity * OFCKDB::getObject( const std::string & key )
{
    // look for the key in the DB
    if( string2entity.find(key) == string2entity.end() )
    {
        // not found
        return NULL;
    }
    
    // return the value
    return string2entity[key];
}




//------------------------------------------------------------------------------
// name: setImage()
// desc: map image by name
//------------------------------------------------------------------------------
ofImage * OFCKDB::setImage( const string & key, ofImage * image )
{
    // TODO: clean up existing image, if there is one

    // associate it
    string2image[key] = image;
    // return
    return image;
}




//------------------------------------------------------------------------------
// name: loadImage()
// desc: map image by name
//------------------------------------------------------------------------------
ofImage * OFCKDB::loadImage( const string & key, const string & name, bool replace )
{
    // look for the key in the DB
    if( !replace && string2image.find(key) != string2image.end() )
    {
        // not found
        return string2image[key];
    }
    
    // instantiate image
    ofImage * image = new ofImage();
    // load image
    if( !image->loadImage( name ) )
    {
        // log
        cerr << "[ofck]: cannot load image: '" << name << "'" << endl;
        // clean up
        goto error;
    }

    // associate image
    return setImage( key, image );

error:
    // delete
    delete image;
    // done
    return NULL;
}




//------------------------------------------------------------------------------
// name: getImage()
// desc: get an image associated with a key
//------------------------------------------------------------------------------
ofImage * OFCKDB::getImage( const std::string & key )
{
    // look for the key in the DB
    if( string2image.find(key) == string2image.end() )
    {
        // not found
        return NULL;
    }
    
    // return the value
    return string2image[key];
}




//------------------------------------------------------------------------------
// name: setCamera()
// desc: set camera
//------------------------------------------------------------------------------
ofCamera * OFCKDB::setCamera( const string & key, ofCamera * cam )
{
    // map
    string2camera[key] = cam;
    
    // return
    return cam;
}




//------------------------------------------------------------------------------
// name: getCamera()
// desc: get camera associated with a key
//------------------------------------------------------------------------------
ofCamera * OFCKDB::getCamera( const std::string & key )
{
    // look for the key in the DB
    if( string2camera.find(key) == string2camera.end() )
    {
        // not found
        return NULL;
    }
    
    // return the value
    return string2camera[key];
}




//------------------------------------------------------------------------------
// name: VREntity()
// desc: constructor
//------------------------------------------------------------------------------
VREntity::VREntity()
{
    alpha = 255;
    col.setAll(255);
    sca.setAll(1);
    m_chuckObject = NULL;
}




//------------------------------------------------------------------------------
// name: ~VREntity()
// desc: destructor
//------------------------------------------------------------------------------
VREntity::~VREntity()
{
    // do nothing for now
}




//------------------------------------------------------------------------------
// name: addChild()
// desc: add child
//------------------------------------------------------------------------------
void VREntity::addChild( VREntity * entity )
{
    children.push_back( entity );
}




//------------------------------------------------------------------------------
// name: syncFromChucK()
// desc: sync chuck-side data to OF
//------------------------------------------------------------------------------
void VREntity::syncFromChucK()
{
    // check
    if( !m_chuckObject )
        return;

    // get them from check
    t_CKVEC3 LOC = OBJ_MEMBER_VEC3(m_chuckObject, vrentity_offset_location);
    t_CKVEC3 ORI = OBJ_MEMBER_VEC3(m_chuckObject, vrentity_offset_rotation);
    t_CKVEC3 SCA = OBJ_MEMBER_VEC3(m_chuckObject, vrentity_offset_scaling);
    t_CKVEC4 RGBA = OBJ_MEMBER_VEC4(m_chuckObject, vrentity_offset_rgba);

    // copy
    this->loc.set( LOC.x, LOC.y, LOC.z );
    this->ori.set( ORI.x, ORI.y, ORI.z );
    this->sca.set( SCA.x, SCA.y, SCA.z );
    this->col.set( RGBA.x*255, RGBA.y*255, RGBA.z*255 );
    this->alpha = RGBA.w*255;
}




//------------------------------------------------------------------------------
// name: initChucKSideObject()
// desc: init chuck side object
//------------------------------------------------------------------------------
bool VREntity::initChucKSideObject()
{
    assert( m_chuckObject == NULL );
    
    // chuck-side object
    m_chuckObject = new Chuck_Object;
    // HACK:
    the_vrentity_type = Chuck_Env::instance()->curr->lookup_type( "VREntity", TRUE );
    initialize_object( m_chuckObject, the_vrentity_type );

    // initialize c-side pointer: TODO: possible 64-bit issue depend on int
    OBJ_MEMBER_INT(m_chuckObject,vrentity_offset_cpointer) = (t_CKINT)this;
    // initialize location
    OBJ_MEMBER_VEC3(m_chuckObject,vrentity_offset_location).x = this->loc.x;
    OBJ_MEMBER_VEC3(m_chuckObject,vrentity_offset_location).y = this->loc.y;
    OBJ_MEMBER_VEC3(m_chuckObject,vrentity_offset_location).z = this->loc.z;

    // initialize orientation
    OBJ_MEMBER_VEC3(m_chuckObject,vrentity_offset_rotation).x = this->ori.x;
    OBJ_MEMBER_VEC3(m_chuckObject,vrentity_offset_rotation).y = this->ori.y;
    OBJ_MEMBER_VEC3(m_chuckObject,vrentity_offset_rotation).z = this->ori.z;

    // initialize scaling
    OBJ_MEMBER_VEC3(m_chuckObject,vrentity_offset_scaling).x = this->sca.x;
    OBJ_MEMBER_VEC3(m_chuckObject,vrentity_offset_scaling).y = this->sca.y;
    OBJ_MEMBER_VEC3(m_chuckObject,vrentity_offset_scaling).z = this->sca.z;

    // initialize color
    OBJ_MEMBER_VEC4(m_chuckObject,vrentity_offset_rgba).x = this->col.x / 255;
    OBJ_MEMBER_VEC4(m_chuckObject,vrentity_offset_rgba).y = this->col.y / 255;
    OBJ_MEMBER_VEC4(m_chuckObject,vrentity_offset_rgba).z = this->col.z / 255;
    OBJ_MEMBER_VEC4(m_chuckObject,vrentity_offset_rgba).w = this->alpha / 255;

    // done
    return true;
}




//------------------------------------------------------------------------------
// name: update()
// desc: update
//------------------------------------------------------------------------------
void VREntity::update( double delta )
{ }




//------------------------------------------------------------------------------
// name: render()
// desc: render
//------------------------------------------------------------------------------
void VREntity::render()
{ }




//------------------------------------------------------------------------------
// name: updateAll()
// desc: update all, cascading to children
//------------------------------------------------------------------------------
void VREntity::updateAll( double delta )
{
    // synch from chuck
    this->syncFromChucK();
    
    // update self
    this->update( delta );
    
    // update children
    for( vector<VREntity *>::iterator itr = children.begin();
        itr != children.end(); itr++ )
    {
        (*itr)->updateAll( delta );
    }
}




//------------------------------------------------------------------------------
// name: renderAll()
// desc: render all, cascading to children
//------------------------------------------------------------------------------
void VREntity::renderAll()
{
    // apply transforms
    applyTransforms();
    
    // render self
    this->render();
    
    // draw children
    for( vector<VREntity *>::iterator itr = children.begin();
        itr != children.end(); itr++ )
    {
        (*itr)->renderAll();
    }
    
    // pop
    popTransforms();
}




//------------------------------------------------------------------------------
// name: applyTransforms()
// desc: apply transforms
//------------------------------------------------------------------------------
void VREntity::applyTransforms()
{
    // push
    ofPushMatrix();
    // translate
    ofTranslate( loc.x, loc.y, loc.z );
    // rotate
    ofRotate( ori.z, 0.0f, 0.0f, 1.0f );
    ofRotate( ori.y, 0.0f, 1.0f, 0.0f );
    ofRotate( ori.x, 1.0f, 0.0f, 0.0f );
    // scale
    ofScale( sca.x, sca.y, sca.z );
    // color
    ofSetColor( col.x, col.y, col.z, alpha );
}




//------------------------------------------------------------------------------
// name: popTransforms()
// desc: restore transforms
//------------------------------------------------------------------------------
void VREntity::popTransforms()
{
    ofPopMatrix();
}




//------------------------------------------------------------------------------
// name: setString()
// desc: associate a string value with a key
//------------------------------------------------------------------------------
std::string VREntity::setString( const std::string & key, const std::string & value )
{
    // associate
    settings[key] = value;
    // return
    return value;
}




//------------------------------------------------------------------------------
// name: getString()
// desc: get a vec3 value associated with a key
//------------------------------------------------------------------------------
std::string VREntity::getString( const std::string & key )
{
    // look for the key in the DB
    if( settings.find(key) == settings.end() )
    {
        // not found
        return "";
    }
    
    // return the value
    return settings[key];
}
