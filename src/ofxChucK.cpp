//------------------------------------------------------------------------------
// name: ofxChucK.h
// desc: header file for ofxChucK, an openframeworks addon to unleash the
//       fury of the ChucK programming language onto OpenFrameworks...
//
// author: Tim O'Brien
// author: Kitty Shi
// author: Madeline Huberth
// author: Ge Wang
//
// @date    Fall 2015
//------------------------------------------------------------------------------
#include "ofxChucK.h"
#include "chuck_system.h"
#include "ofck.h"


// static instantiation
TheChucK * TheChucK::ourInstance = NULL;




//------------------------------------------------------------------------------
// name: initialize()
// desc: initialize chuck system
//------------------------------------------------------------------------------
bool TheChucK::initialize( int srate, int bufferSize, int numChannels,
                           int argc, const char ** argv )
{
    // allocate
    inputBuffer = new float[bufferSize*numChannels];
    // remember
    m_numChannels = numChannels;
    
    // initialize!
    t_CKBOOL val = m_system->clientInitialize(
        srate, bufferSize, numChannels, argc, argv );
    
    // binding
    m_system->bind( ofck_query, "OF" );
    
    // done
    return val;
}




//------------------------------------------------------------------------------
// name: compileFile()
// desc: compile a file
//------------------------------------------------------------------------------
bool TheChucK::compileFile( const std::string & path, const std::string & args )
{
    // compile
    return m_system->compileFile( path, args );
}




//------------------------------------------------------------------------------
// name: compileCode()
// desc: compile code
//------------------------------------------------------------------------------
bool TheChucK::compileCode( const std::string & path, const std::string & args )
{
    // compile
    return FALSE;
}




//------------------------------------------------------------------------------
// name: vm()
// desc: get VM
//------------------------------------------------------------------------------
Chuck_VM * TheChucK::vm()
{
    // compile
    return m_system->vm();
}




//------------------------------------------------------------------------------
// name: onInput()
// desc: audio input
//------------------------------------------------------------------------------
void TheChucK::onInput( float * input, int numFrames )
{
    // copy
    memcpy( inputBuffer, input, numFrames*m_numChannels*sizeof(float) );
}




//------------------------------------------------------------------------------
// name: onOutput()
// desc: audio output
//------------------------------------------------------------------------------
void TheChucK::onOutput( float * output, int numFrames )
{
    // run with input and output
    m_system->run( inputBuffer, output, numFrames );
}




//------------------------------------------------------------------------------
// name: getInstance()
// desc: this is a singleton class (second instance would break everything)
//------------------------------------------------------------------------------
TheChucK * TheChucK::instance()
{
    // check
    if( ourInstance == NULL )
    {
        // instantiate!
        ourInstance = new TheChucK;
    }
    
    return ourInstance;
}




//------------------------------------------------------------------------------
// name: TheChucK()
// desc: constructor
//------------------------------------------------------------------------------
TheChucK::TheChucK()
{
    // instantiate
    m_system = new Chuck_System;
    inputBuffer = NULL;
    m_numChannels = 0;
}




//------------------------------------------------------------------------------
// name: ~TheChucK()
// desc: destructor
//------------------------------------------------------------------------------
TheChucK::~TheChucK()
{
    // done
    delete m_system;
    // zero out
    m_system = NULL;
}



// set float
float TheChucK::setFloat( const std::string & key, float value )
{
    // get the DB
    OFCKDB * db = OFCKDB::instance();
    // insert
    db->string2float[key] = value;

}

// get float
float TheChucK::getFloat( const std::string & key )
{
    // get the DB
    OFCKDB * db = OFCKDB::instance();
    // lookup
    if( db->string2float.find( key ) == db->string2float.end() )
        return 0;
    else
        return db->string2float[key];
}

void TheChucK::displaySync()
{
    // get the DB
    OFCKDB * db = OFCKDB::instance();
    // broadcast on the event
    db->displaySync.queue_broadcast( db->m_eventBuffer );
}
