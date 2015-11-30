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

// example of getter/setter
CK_DLL_MFUN(ofck_setParam);
CK_DLL_MFUN(ofck_getParam);

// this is a special offset reserved for Chugin internal data
t_CKINT ofck_data_offset = 0;


// class definition for internal Chugin data
// (note: this isn't strictly necessary, but serves as example
// of one recommended approach)
class ofck
{
public:
    // constructor
    ofck( t_CKFLOAT fs)
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
    QUERY->setname(QUERY, "OF");
    
    // begin the class definition
    // can change the second argument to extend a different ChucK class
    QUERY->begin_class(QUERY, "OF", "Object");
    
    // register the constructor (probably no need to change)
    QUERY->add_ctor(QUERY, ofck_ctor);
    // register the destructor (probably no need to change)
    QUERY->add_dtor(QUERY, ofck_dtor);

    // NOTE: if this is to be a UGen with more than 1 channel,
    // e.g., a multichannel UGen -- will need to use add_ugen_funcf()
    // and declare a tickf function using CK_DLL_TICKF
    
    // example of adding setter method
    QUERY->add_mfun(QUERY, ofck_setParam, "float", "param");
    // example of adding argument to the above method
    QUERY->add_arg(QUERY, "float", "arg");
    
    // example of adding getter method
    QUERY->add_mfun(QUERY, ofck_getParam, "float", "param");
    
    // this reserves a variable in the ChucK internal class to store
    // referene to the c++ class we defined above
    ofck_data_offset = QUERY->add_mvar(QUERY, "int", "@o_data", false);
    
    // end the class definition
    // IMPORTANT: this MUST be called!
    QUERY->end_class(QUERY);
    
    // wasn't that a breeze?
    return TRUE;
}


// implementation for the constructor
CK_DLL_CTOR(ofck_ctor)
{
    // get the offset where we'll store our internal c++ class pointer
    OBJ_MEMBER_INT(SELF, ofck_data_offset) = 0;
    
    // instantiate our internal c++ class representation
    ofck * o_obj = new ofck(API->vm->get_srate());
    
    // store the pointer in the ChucK object member
    OBJ_MEMBER_INT(SELF, ofck_data_offset) = (t_CKINT) o_obj;
}


// implementation for the destructor
CK_DLL_DTOR(ofck_dtor)
{
    // get our c++ class pointer
    ofck * o_obj = (ofck *) OBJ_MEMBER_INT(SELF, ofck_data_offset);
    // check it
    if( o_obj )
    {
        // clean up
        delete o_obj;
        OBJ_MEMBER_INT(SELF, ofck_data_offset) = 0;
        o_obj = NULL;
    }
}


// example implementation for setter
CK_DLL_MFUN(ofck_setParam)
{
    // get our c++ class pointer
    ofck * o_obj = (ofck *) OBJ_MEMBER_INT(SELF, ofck_data_offset);
    // set the return value
    RETURN->v_float = o_obj->setParam(GET_NEXT_FLOAT(ARGS));
}


// example implementation for getter
CK_DLL_MFUN(ofck_getParam)
{
    // get our c++ class pointer
    ofck * o_obj = (ofck *) OBJ_MEMBER_INT(SELF, ofck_data_offset);
    // set the return value
    RETURN->v_float = o_obj->getParam();
}
