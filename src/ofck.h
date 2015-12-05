//------------------------------------------------------------------------------
// name: ofck.h
// desc: openframeworks <=> ChucK bridge; ChucK-side bindings
//
// @author  Ge Wang
// @author  Tim O'Brien
// @author  Kitty Shi
// @author  Madeline Huberth
//
// @date    Fall 2015
//------------------------------------------------------------------------------
#ifndef __OF_CK_H__
#define __OF_CK_H__


#include "chuck_dl.h"


// the query function for ofck
DLL_QUERY ofck_query( Chuck_DL_Query * QUERY );


class OFCKDB
{
public:
    OFCKDB();

public:
    // associating a float value with a key
    t_CKFLOAT setFloat( const std::string & key, t_CKFLOAT value );
    // get a float value associated with a key
    t_CKFLOAT getFloat( const std::string & key );
    
public:
    static OFCKDB * instance()
    {
        // check
        if( ourInstance == NULL )
        {
            ourInstance = new OFCKDB;
        }
        
        return ourInstance;
    }

public:
    static OFCKDB * ourInstance;

public:
    std::map<std::string, float> string2float;

    // display sync event is broadcast right before each new graphics frame
    Chuck_Event displaySync;
    // event buffer for queue broadcat
    CBufferSimple * m_eventBuffer;
};


#endif
