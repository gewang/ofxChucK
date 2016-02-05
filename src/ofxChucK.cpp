//------------------------------------------------------------------------------
// name: ofxChucK.h
// desc: header file for ofxChucK, an openframeworks addon to unleash the
//       fury of the ChucK programming language onto OpenFrameworks...
//
// @author: Tim O'Brien
// @author: Kitty Shi
// @author: Madeline Huberth
// @author: Ge Wang
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
bool TheChucK::initialize( int srate, int bufferSize, int channelsIn,
                           int channelsOut, int argc, const char ** argv )
{
    // bigger of two
    int biggerChannel = ::max( channelsIn, channelsOut );
    // allocate
    inputBuffer = new float[bufferSize*biggerChannel];
    // remember
    m_channelsIn = channelsIn;
    m_channelsOut = channelsOut;

    // initialize!
    t_CKBOOL val = m_system->clientInitialize(
        srate, bufferSize, channelsIn, channelsOut, argc, argv );

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
    // we need to double up the backslashes
    // so ChucK does not get confused by the
    // drive-colon prefix in Windows filenames
    std::string safePath(ofToDataPath(path));
    size_t matchPosition = -2;

    // probably the most concise way to do find-and-replace in CPP without imports or C++11
    while( (matchPosition = safePath.find("\\", matchPosition + 2)) != std::string::npos )
        safePath.replace( matchPosition, 1, "\\\\" ); // four backslashes is really two

    // compile
    return m_system->compileFile( safePath, args );
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
// name: compiler()
// desc: get compiler
//------------------------------------------------------------------------------
Chuck_Compiler * TheChucK::compiler()
{
    // compile
    return m_system->compiler();
}




//------------------------------------------------------------------------------
// name: db()
// desc: get OFCK database
//------------------------------------------------------------------------------
OFCKDB * TheChucK::db()
{
    // HACK: using singleton
    return OFCKDB::instance();
}




//------------------------------------------------------------------------------
// name: onInput()
// desc: audio input
//------------------------------------------------------------------------------
void TheChucK::onInput( float * input, int numFrames )
{
    // copy
    memcpy( inputBuffer, input, numFrames*m_channelsIn*sizeof(float) );
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
    m_channelsIn = 0;
    m_channelsOut = 0;
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




//------------------------------------------------------------------------------
// name: displaySync()
// desc: trigger a display sync from oF; triggering ChucK event
//------------------------------------------------------------------------------
void TheChucK::displaySync()
{
    // get the DB
    OFCKDB * db = OFCKDB::instance();
    // broadcast on the event
    db->displaySync.queue_broadcast( db->m_eventBuffer );
    // flush eval queue (defered eval commands here to minimize locking)
    db->flushEval();
}
