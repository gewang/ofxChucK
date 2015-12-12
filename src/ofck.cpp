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
#include "ofMain.h"

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
CK_DLL_MFUN(vrentity_addEntity);
CK_DLL_MFUN(vrentity_removeEntity);

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
CK_DLL_SFUN(vr_displaySync);


// internal data
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
        if( vrentity_offset_location == CK_INVALID_OFFSET ) goto error;

        // add .sca
        vrentity_offset_scaling = QUERY->add_mvar( QUERY, "vec3", "sca", FALSE );
        if( vrentity_offset_location == CK_INVALID_OFFSET ) goto error;

        // add .rgba
        vrentity_offset_rgba = QUERY->add_mvar( QUERY, "vec4", "rgba", FALSE );
        if( vrentity_offset_location == CK_INVALID_OFFSET ) goto error;
    }
    // end the class definition
    QUERY->end_class(QUERY);
    
    // begin the class definition
    QUERY->begin_class(QUERY, "VR", "Object");
    {
        // VRObject VR.object(name) // retrive objects
        QUERY->add_sfun(QUERY, vr_getEntity, "VREntity", "getEntity");
        // name of object to retrieve
        QUERY->add_arg(QUERY, "string", "name");

//        // int VR.setInt(key,value) // set
//        QUERY->add_sfun(QUERY, vr_setInt, "int", "setInt");
//        // name of object to retrieve
//        QUERY->add_arg(QUERY, "string", "key");
//        // name of object to retrieve
//        QUERY->add_arg(QUERY, "int", "value");
//
//        // float VR.setFloat(key,value) // set
//        QUERY->add_sfun(QUERY, vr_getInt, "int", "getInt");
//        // name of object to retrieve
//        QUERY->add_arg(QUERY, "string", "key");

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
        
//        // float VR.setString(key,value) // set
//        QUERY->add_sfun(QUERY, vr_setFloat, "string", "setString");
//        // name of object to retrieve
//        QUERY->add_arg(QUERY, "string", "key");
//        // name of object to retrieve
//        QUERY->add_arg(QUERY, "string", "value");
//        
//        // string VR.getString(key,value) // set
//        QUERY->add_sfun(QUERY, vr_getString, "string", "getString");
//        // name of object to retrieve
//        QUERY->add_arg(QUERY, "string", "key");
//
//        // vec3 VR.setVec3(key,value) // set
//        QUERY->add_sfun(QUERY, vr_setVec3, "vec3", "setVec3");
//        // name of object to retrieve
//        QUERY->add_arg(QUERY, "string", "key");
//        // name of object to retrieve
//        QUERY->add_arg(QUERY, "vec3", "value");
//        
//        // vec3 VR.getVec3(key,value) // set
//        QUERY->add_sfun(QUERY, vr_getString, "vec3", "getVec3");
//        // name of object to retrieve
//        QUERY->add_arg(QUERY, "string", "key");
//
//        // vec4 VR.setVec4(key,value) // set
//        QUERY->add_sfun(QUERY, vr_setVec4, "vec4", "setVec4");
//        // name of object to retrieve
//        QUERY->add_arg(QUERY, "string", "key");
//        // name of object to retrieve
//        QUERY->add_arg(QUERY, "vec4", "value");
//        
//        // vec4 VR.getVec4(key,value) // set
//        QUERY->add_sfun(QUERY, vr_getString, "vec4", "getVec4");
//        // name of object to retrieve
//        QUERY->add_arg(QUERY, "string", "key");
        
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
CK_DLL_CTOR(vrentity_ctor)
{
    // nothing for now
}

CK_DLL_DTOR(vrentity_dtor)
{
    // nothing for now
}

//CK_DLL_SFUN(vrentity_addEntity);
//CK_DLL_SFUN(vrentity_removeEntity);

CK_DLL_SFUN( vr_getEntity)
{
    // get the argument
    std::string key = GET_NEXT_STRING(ARGS)->str;
    // get the DB
    OFCKDB * db = OFCKDB::instance();
    // look for the key in the DB
    if( db->string2entity.find(key) == db->string2entity.end() )
    {
        // not found
        RETURN->v_object = 0;
    }
    else
    {
        if( db->string2entity[key]->chuckObject() == NULL )
        {
            db->string2entity[key]->initChucKSideObject();
        }
        // return the value
        RETURN->v_object = db->string2entity[key]->chuckObject();
    }
}

CK_DLL_SFUN( vr_setFloat)
{
    std::string key = GET_NEXT_STRING(ARGS)->str;
    t_CKFLOAT value = GET_NEXT_FLOAT(ARGS);
    
    // get the DB
    OFCKDB * db = OFCKDB::instance();
    // insert the key value pair, possibly overwriting
    db->string2float[key] = value;
    // return the value
    RETURN->v_float = value;
}

CK_DLL_SFUN( vr_getFloat)
{
    // get the argument
    std::string key = GET_NEXT_STRING(ARGS)->str;
    // get the DB
    OFCKDB * db = OFCKDB::instance();
    // look for the key in the DB
    if( db->string2float.find(key) == db->string2float.end() )
    {
        // not found
        RETURN->v_float = 0;
    }
    else
    {
        // return the value
        RETURN->v_float = db->string2float[key];
    }
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
// name: setObject()
// desc: map object by name
//------------------------------------------------------------------------------
VREntity * OFCKDB::setObject( const string & key, VREntity * e )
{
    string2entity[key] = e;
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
    this->col.set( RGBA.x, RGBA.y, RGBA.z );
    this->alpha = RGBA.w;
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
    the_vrentity_type = Chuck_Env::instance()->curr->lookup_type( "VREntity", TRUE );
    initialize_object( m_chuckObject, the_vrentity_type );

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
    OBJ_MEMBER_VEC4(m_chuckObject,vrentity_offset_rgba).x = this->col.x;
    OBJ_MEMBER_VEC4(m_chuckObject,vrentity_offset_rgba).y = this->col.y;
    OBJ_MEMBER_VEC4(m_chuckObject,vrentity_offset_rgba).z = this->col.z;
    OBJ_MEMBER_VEC4(m_chuckObject,vrentity_offset_rgba).w = this->alpha;

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
