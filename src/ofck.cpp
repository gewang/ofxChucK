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

// general includes
#include <stdio.h>
#include <limits.h>

// declaration of chugin constructor
CK_DLL_CTOR(ofck_ctor);
// declaration of chugin desctructor
CK_DLL_DTOR(ofck_dtor);

// VREntity
CK_DLL_SFUN(vrentity_getLocation);
CK_DLL_SFUN(vrentity_setLocation);
CK_DLL_SFUN(vrentity_getRotation);
CK_DLL_SFUN(vrentity_setRotation);
CK_DLL_SFUN(vrentity_getScaling);
CK_DLL_SFUN(vrentity_setScaling);
CK_DLL_SFUN(vrentity_getRGB);
CK_DLL_SFUN(vrentity_setRGB);
CK_DLL_SFUN(vrentity_getRGBA);
CK_DLL_SFUN(vrentity_setRGBA);
CK_DLL_SFUN(vrentity_addEntity);
CK_DLL_SFUN(vrentity_removeEntity);

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


// this is a special offset reserved for Chugin internal data
t_CKINT ofck_data_offset = 0;


// defintion
class VREntity
{
public:
    // constructor
    VREntity( t_CKFLOAT fs)
    {
        m_param = 0;
    }

    // set parameter example
    float setParam( t_CKFLOAT p )
    {
        m_param = p;
        return p;
    }
    
    // get parameter example
    float getParam() { return m_param; }
    
private:
    // instance data
    float m_param;
};


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
        // vec3 VREntity.location()
        QUERY->add_sfun(QUERY, vrentity_getLocation, "vec3", "location");
        QUERY->add_sfun(QUERY, vrentity_setLocation, "vec3", "location");
        QUERY->add_arg(QUERY, "vec3", "loc");

        // vec3 VREntity.rotation()
        QUERY->add_sfun(QUERY, vrentity_getRotation, "vec3", "rotation");
        QUERY->add_sfun(QUERY, vrentity_setRotation, "vec3", "rotation");
        QUERY->add_arg(QUERY, "vec3", "rot");
        
        // vec3 VREntity.scaling()
        QUERY->add_sfun(QUERY, vrentity_getScaling, "vec3", "scaling");
        QUERY->add_sfun(QUERY, vrentity_setScaling, "vec3", "scaling");
        QUERY->add_arg(QUERY, "vec3", "sca");
        
        // vec3 VREntity.rgb()
        QUERY->add_sfun(QUERY, vrentity_getRGB, "vec3", "rgb");
        QUERY->add_sfun(QUERY, vrentity_setRGB, "vec3", "rgb");
        QUERY->add_arg(QUERY, "vec3", "col");
        
        // vec4 VREntity.rgb()
        QUERY->add_sfun(QUERY, vrentity_getRGBA, "vec4", "rgba");
        QUERY->add_sfun(QUERY, vrentity_setRGBA, "vec4", "rgba");
        QUERY->add_arg(QUERY, "vec4", "rgba");
    }
    // end the class definition
    QUERY->end_class(QUERY);

    // begin the class definition
    QUERY->begin_class(QUERY, "VR", "Object");
    {
        // VRObject VR.object(name) // retrive objects
        QUERY->add_sfun(QUERY, vr_object, "VRObject", "object");
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
        QUERY->add_arg(QUERY, "int", "value");

        // float VR.getFloat(key,value) // set
        QUERY->add_sfun(QUERY, vr_getFloat, "float", "getFloat");
        // name of object to retrieve
        QUERY->add_arg(QUERY, "string", "key");
        
        // float VR.setString(key,value) // set
        QUERY->add_sfun(QUERY, vr_setFloat, "string", "setString");
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
        QUERY->add_sfun(QUERY, vr_getString, "vec4", "getVec4");
        // name of object to retrieve
        QUERY->add_arg(QUERY, "string", "key");
        
        // Event VR.displaySync // event for display
        QUERY->add_sfun(QUERY, vr_object, "Event", "displaySync");
    }
    // end the class definition
    QUERY->end_class(QUERY);
    
    // wasn't that a breeze?
    return TRUE;
}


CK_DLL_SFUN(vrentity_getLocation)
{
}

CK_DLL_SFUN(vrentity_setLocation);
CK_DLL_SFUN(vrentity_getRotation);
CK_DLL_SFUN(vrentity_setRotation);
CK_DLL_SFUN(vrentity_getScaling);
CK_DLL_SFUN(vrentity_setScaling);
CK_DLL_SFUN(vrentity_getRGB);
CK_DLL_SFUN(vrentity_setRGB);
CK_DLL_SFUN(vrentity_getRGBA);
CK_DLL_SFUN(vrentity_setRGBA);
CK_DLL_SFUN(vrentity_addEntity);
CK_DLL_SFUN(vrentity_removeEntity);

