#include "ofApp.h"




//------------------------------------------------------------------------------
// name: setup()
// desc: set up the app
//------------------------------------------------------------------------------
void ofApp::setup()
{
    ofSetVerticalSync( true );
    ofBackground(0, 0, 0);

    // get singleton
    chuck = TheChucK::instance();
    // arguments
    const char * argv[] = { "the", "-v0" };
    
    // initialize (SHOULD HAPPEN BEFORE AUDIO STREAM STARTS)
    chuck->initialize( MY_SRATE, MY_BUFFERSIZE, MY_CHANNELS_IN, MY_CHANNELS_OUT, 2, argv );

    // load image
    OFCKDB::instance()->loadImage("texture:flare-1", "flare-tng-1.png");

    // set pointer
    vr = VR::instance();
    
    // set up light
    m_light = new ofLight();
    m_light->setDiffuseColor( ofColor(100, 255, 100) );
    m_light->enable();
    m_light->setGlobalPosition( 1000, 1000, 1000 );

    // compile and run another file
    chuck->compileFile( "ck/solar.ck" );
    // chuck->compileFile( "ck/flares.ck" ); // need audio input
    // chuck->compileFile( "ck/dot-circle.ck" );

    // setup the sound stream...
    soundStream.setup( this,
                       MY_CHANNELS_OUT, // output
                       MY_CHANNELS_IN,  // input
                       MY_SRATE,        // sample rate
                       MY_BUFFERSIZE,   // buffer size
                       MY_NUMBUFFERS ); // num buffer
}




//------------------------------------------------------------------------------
// name: audioIn()
// desc: audio input callback
//------------------------------------------------------------------------------
void ofApp::audioIn( float * input, int bufferSize, int nChannels )
{
    assert( bufferSize == MY_BUFFERSIZE );
    assert( nChannels == MY_CHANNELS_IN );
    chuck->onInput( input, bufferSize );
}




//------------------------------------------------------------------------------
// name: audioOut()
// desc: audio output callback
//------------------------------------------------------------------------------
void ofApp::audioOut( float * output, int bufferSize, int nChannels )
{
    assert( bufferSize == MY_BUFFERSIZE );
    assert( nChannels == MY_CHANNELS_OUT );
    // chuck
    chuck->onOutput( output, bufferSize );
}




//------------------------------------------------------------------------------
// name: update()
// desc: update the system
//------------------------------------------------------------------------------
void ofApp::update()
{
    // set background
    ofBackground( 1, 1, 1 );
    
    // update it
    vr->root()->updateAll(1/60.0f);

    // trigger displaySync to chuck
    chuck->displaySync();
}




//------------------------------------------------------------------------------
// name: draw()
// desc: draw the scene
//------------------------------------------------------------------------------
void ofApp::draw()
{
    // enable depth test
    ofEnableDepthTest();
    // set fov
    m_camera.setFov( 90 );
    // set position
    m_camera.setPosition( ofVec3f(0,0,10) );
    // look at
    m_camera.lookAt( ofVec3f(0,0,0), ofVec3f(0,1,0) );

    // start camera
    m_camera.begin();
    // render light
    m_light->enable();
    
    // update it
    vr->root()->renderAll();

    // undo light
    m_light->disable();
    
    // done with camera
    m_camera.end();
}




//------------------------------------------------------------------------------
// name: keyPressed()
// desc: on key pressed
//------------------------------------------------------------------------------
void ofApp::keyPressed( int key )
{
}




//------------------------------------------------------------------------------
// name: keyRelease()
// desc: on key released
//------------------------------------------------------------------------------
void ofApp::keyReleased( int key )
{
}




//------------------------------------------------------------------------------
// name: mouseMoved()
// desc: on mouse moved
//------------------------------------------------------------------------------
void ofApp::mouseMoved( int x, int y )
{
    chuck->db()->setFloat( "mouse-x", x );
    chuck->db()->setFloat( "mouse-y", y );
}




//------------------------------------------------------------------------------
// name: mouseDragged()
// desc: on mouse dragged
//------------------------------------------------------------------------------
void ofApp::mouseDragged( int x, int y, int button )
{
}




//------------------------------------------------------------------------------
// name: mousePressed()
// desc: on mouse pressed
//------------------------------------------------------------------------------
void ofApp::mousePressed( int x, int y, int button )
{
}




//------------------------------------------------------------------------------
// name: mouseReleased()
// desc: on mouse released
//------------------------------------------------------------------------------
void ofApp::mouseReleased( int x, int y, int button )
{
}




//------------------------------------------------------------------------------
// name: mouseEntered()
// desc: on mouse entered
//------------------------------------------------------------------------------
void ofApp::mouseEntered( int x, int y )
{
}




//------------------------------------------------------------------------------
// name: mouseExited()
// desc: on mouse exited
//------------------------------------------------------------------------------
void ofApp::mouseExited( int x, int y )
{
}




//------------------------------------------------------------------------------
// name: windowResized()
// desc: on window resized
//------------------------------------------------------------------------------
void ofApp::windowResized( int w, int h )
{
    // log
    cerr << "window resized w: " << w << " h: " << h << endl;
}




//------------------------------------------------------------------------------
// name: gotMessage()
// desc: on receive of message
//------------------------------------------------------------------------------
void ofApp::gotMessage( ofMessage msg )
{
}




//------------------------------------------------------------------------------
// name: dragEvent()
// desc: on drag event
//------------------------------------------------------------------------------
void ofApp::dragEvent( ofDragInfo dragInfo )
{
}
