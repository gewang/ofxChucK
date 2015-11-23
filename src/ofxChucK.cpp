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
    return m_system->clientInitialize( srate, bufferSize, numChannels, argc, argv );
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
