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
    OFCKDB::instance()->loadImage("texture:flare-2", "flare-tng-2.png");
    OFCKDB::instance()->loadImage("texture:flare-3", "flare-tng-3.png");
    OFCKDB::instance()->loadImage("texture:flare-4", "flare-tng-4.png");
    OFCKDB::instance()->loadImage("texture:flare-5", "flare-tng-5.png");

    // set pointer
    vr = VR::instance();
    
    // set up light
    m_light = new ofLight();
    m_light->setDiffuseColor( ofColor(100, 255, 100) );
    m_light->setGlobalPosition( 1000, 1000, 1000 );
    m_light->enable();

    // success code
    bool r = false;
    // compile and run file
    // r = chuck->compileFile( "ck/solar.ck" );
    // r = chuck->compileFile( "ck/lines.ck" );
    // r = chuck->compileFile( "ck/text.ck" );
    // r = chuck->compileFile( "ck/flares.ck" ); // need audio input
    // r = chuck->compileFile( "ck/points.ck" );
    // r = chuck->compileFile( "ck/mesh.ck" );
    // r = chuck->compileFile( "ck/wire.ck" );
    // r = chuck->compileFile( "ck/obj.ck" );
    // r = chuck->compileFile( "ck/textured_mesh.ck" );
    // r = chuck->compileFile( "ck/update_mesh.ck" );
    // r = chuck->compileFile( "ck/lights-1.ck" );
    // r = chuck->compileFile( "ck/lights-3.ck" );
    // r = chuck->compileFile( "ck/lights-trail.ck" );
    // r = chuck->compileFile( "ck/vortex.ck" );
    r = chuck->compileFile( "ck/turenas-2.ck" );
    //r = chuck->compileFile( "ck/trails.ck" );

    // check
    if( !r )
    {
        // set error
        m_message = "ERROR compiling ChucK code\n(check console for details...)";
    }
    
    // use normalized tex coords to match up with VR setup
    ofEnableNormalizedTexCoords();

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

    // lock
    VR::instance()->lock();
    // update it
    vr->root()->updateAll(1/60.0f);

    // trigger displaySync to chuck
    chuck->displaySync();
    // release lock
    VR::instance()->release();
}




//------------------------------------------------------------------------------
// name: draw()
// desc: draw the scene
//------------------------------------------------------------------------------
void ofApp::draw()
{
    // check
    if( m_message != "" )
    {
        // draw it
        ofDrawBitmapString( m_message, 30, 30, 0 );
    }

    // lock
    VR::instance()->lock();
    // enable depth test
    ofEnableDepthTest();
    
    // set fov
    m_camera.setFov( 90 );
    // set near clipping plane
    m_camera.setNearClip( .1 );
    // set position
    m_camera.setPosition( ofVec3f(0,0,10) );
    // look at
    m_camera.lookAt( ofVec3f(0,0,0), ofVec3f(0,1,0) );

    // start camera
    m_camera.begin();
    // render light
    if( VR::instance()->lightSwitch() ) ofEnableLighting();
    else ofDisableLighting();
    
    // update it
    vr->root()->renderAll();

    // stop rendering light
    ofDisableLighting();
    
    // done with camera
    m_camera.end();
    // release lock
    VR::instance()->release();
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
