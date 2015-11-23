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

// forward reference
class Chuck_System;




//------------------------------------------------------------------------------
// name: class ChucKtainer
// desc: shared data/object store between OF and ChucK
//------------------------------------------------------------------------------
class ChucKtainer
{
public:
    // constructor
    ChucKtainer();
    // destructor
    ~ChucKtainer();

public:
    // add a node by name
    void add( const std::string & key, ofNode * node );
    // remove a node by name
    bool remove( const std::string & key );
    // add a node by name
    ofNode * lookup( const std::string & key );
};




//------------------------------------------------------------------------------
// name: class TheChucK
// desc: openframeworks chuck object
//------------------------------------------------------------------------------
class TheChucK
{
public:
    // initialize chuck system
    bool initialize( int srate, int bufferSize, int numChannels,
                     int argc, const char ** argv );
    // compile a file
    bool compileFile( const std::string & path, const std::string & args );
    // compile code directly
    bool compileCode( const std::string & code, const std::string & args );
    
public:
    // audio input
    void onInput( float * input, int numFrames );
    // audio output
    void onOutput( float * output, int numFrames );

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
    int m_numChannels;
};




#endif
