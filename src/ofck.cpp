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
#include "ofxChucK.h"

// general includes
#include <stdio.h>
#include <limits.h>

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
CK_DLL_SFUN(vr_object);
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


// defintion
class VREntity
{
public:
    // constructor
    VREntity( t_CKFLOAT fs );

    
private:
    // instance data
    float m_param;
};

OFCKDB::OFCKDB()
{
    initialize_object( &displaySync, &t_event );
    m_eventBuffer = TheChucK::instance()->vm()->create_event_buffer();
}


// query function: chuck calls this when loading the Chugin
// NOTE: developer will need to modify this function to
// add additional functions to this Chugin
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
        
        // add .location
        vrentity_offset_location = QUERY->add_mvar( QUERY, "vec3", "location", FALSE );
        if( vrentity_offset_location == CK_INVALID_OFFSET ) goto error;

        // add .rotation
        vrentity_offset_rotation = QUERY->add_mvar( QUERY, "vec3", "rotation", FALSE );
        if( vrentity_offset_location == CK_INVALID_OFFSET ) goto error;

        // add .location
        vrentity_offset_scaling = QUERY->add_mvar( QUERY, "vec3", "scaling", FALSE );
        if( vrentity_offset_location == CK_INVALID_OFFSET ) goto error;

        // add .location
        vrentity_offset_rgba = QUERY->add_mvar( QUERY, "vec4", "rgba", FALSE );
        if( vrentity_offset_location == CK_INVALID_OFFSET ) goto error;

//        // vec3 VREntity.location()
//        QUERY->add_mfun(QUERY, vrentity_getLocation, "vec3", "location");
//        QUERY->add_mfun(QUERY, vrentity_setLocation, "vec3", "location");
//        QUERY->add_arg(QUERY, "vec3", "loc");
//
//        // vec3 VREntity.rotation()
//        QUERY->add_mfun(QUERY, vrentity_getRotation, "vec3", "rotation");
//        QUERY->add_mfun(QUERY, vrentity_setRotation, "vec3", "rotation");
//        QUERY->add_arg(QUERY, "vec3", "rot");
//        
//        // vec3 VREntity.scaling()
//        QUERY->add_mfun(QUERY, vrentity_getScaling, "vec3", "scaling");
//        QUERY->add_mfun(QUERY, vrentity_setScaling, "vec3", "scaling");
//        QUERY->add_arg(QUERY, "vec3", "sca");
//        
//        // vec3 VREntity.rgb()
//        QUERY->add_mfun(QUERY, vrentity_getRGB, "vec3", "rgb");
//        QUERY->add_mfun(QUERY, vrentity_setRGB, "vec3", "rgb");
//        QUERY->add_arg(QUERY, "vec3", "col");
//        
//        // vec4 VREntity.rgb()
//        QUERY->add_mfun(QUERY, vrentity_getRGBA, "vec4", "rgba");
//        QUERY->add_mfun(QUERY, vrentity_setRGBA, "vec4", "rgba");
//        QUERY->add_arg(QUERY, "vec4", "rgba");
    }
    // end the class definition
    QUERY->end_class(QUERY);

    // begin the class definition
    QUERY->begin_class(QUERY, "VR", "Object");
    {
//        // VRObject VR.object(name) // retrive objects
//        QUERY->add_sfun(QUERY, vr_object, "VRObject", "object");
//        // name of object to retrieve
//        QUERY->add_arg(QUERY, "string", "name");

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


CK_DLL_CTOR(vrentity_ctor)
{
    // nothing for now
}

CK_DLL_DTOR(vrentity_dtor)
{
    // nothing for now
}

//CK_DLL_SFUN(vrentity_getLocation)
//{
//}
//
//CK_DLL_SFUN(vrentity_setLocation);
//CK_DLL_SFUN(vrentity_getRotation);
//CK_DLL_SFUN(vrentity_setRotation);
//CK_DLL_SFUN(vrentity_getScaling);
//CK_DLL_SFUN(vrentity_setScaling);
//CK_DLL_SFUN(vrentity_getRGB);
//CK_DLL_SFUN(vrentity_setRGB);
//CK_DLL_SFUN(vrentity_getRGBA);
//CK_DLL_SFUN(vrentity_setRGBA);
//CK_DLL_SFUN(vrentity_addEntity);
//CK_DLL_SFUN(vrentity_removeEntity);


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
