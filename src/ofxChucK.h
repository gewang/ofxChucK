//------------------------------------------------------------------------------
// name: ofxChucK.h
// desc: implementation ofxChucK, an openframeworks addon to unleash the
//       fury of the ChucK programming language onto OpenFrameworks...
//
// @author  Tim O'Brien
// @author  Kitty Shi
// @author  Madeline Huberth
// @author  Ge Wang
//
// @date    Fall 2015
//------------------------------------------------------------------------------
#ifndef __OFX_CHUCK_H__
#define __OFX_CHUCK_H__


#include <string>
#include "ofck.h"
#include "ofck-entities.h"


// forward reference
class Chuck_System;
class Chuck_VM;
class Chuck_Compiler;




//------------------------------------------------------------------------------
// name: class TheChucK
// desc: openframeworks chuck object
//------------------------------------------------------------------------------
class TheChucK
{
public:
    // initialize chuck system
    bool initialize( int srate, int bufferSize, int channelsIn, int channelsOut,
                     int argc, const char ** argv );
    // compile a file
    bool compileFile( const std::string & path, const std::string & args = "" );
    // compile code directly
    bool compileCode( const std::string & code, const std::string & args = "" );
    // get ChucK VM (dangerous)
    Chuck_VM * vm();
    // get ChucK compiler (dangerous)
    Chuck_Compiler * compiler();
    // get the oFCK database
    OFCKDB * db();
    
public:
    // audio input
    void onInput( float * input, int numFrames );
    // audio output
    void onOutput( float * output, int numFrames );
    
public:
    // trigger display sync
    void displaySync();

public:
    // this is a singleton class (second instance would break everything)
    static TheChucK * instance();

private:
    TheChucK();
    ~TheChucK();
    
    // singletone instance
    static TheChucK * ourInstance;

protected:
    // chuck system stuff
    Chuck_System * m_system;

    // input buffer
    float * inputBuffer;
    // channel
    int m_channelsIn;
    int m_channelsOut;
};




#endif




//VirChucK Reality
//VCKR
//
//Chutual Reality
//CKVR
//
//ChVRcK
//VirChuR
//VReCK
