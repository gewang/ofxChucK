#include "ofApp.h"

#include <stdio.h>
#include <math.h>
#include <cmath>




//------------------------------------------------------------------------------
// name: setup()
// desc: set up the app
//------------------------------------------------------------------------------
void ofApp::setup()
{
    ofSetLogLevel( OF_LOG_FATAL_ERROR );
    ofEnableDepthTest();
    ofSetVerticalSync( false );

    // CHUCK STUFF -------------------------------------------------------------
    
    // get singleton
    chuck = TheChucK::instance();
    // arguments
    const char * argv[] = { "the", "-v0" };
    
    // initialize (SHOULD HAPPEN BEFORE AUDIO STREAM STARTS)
    chuck->initialize( MY_SRATE, MY_BUFFERSIZE, MY_CHANNELS_IN, MY_CHANNELS_OUT, 2, argv );
    
    // set pointer
    vr = VR::instance();
    
    // set up light
    m_light = new ofLight();
    m_light->setDiffuseColor( ofColor(100, 255, 100) );
    m_light->setGlobalPosition( 100, 100, 100 );
    m_light->enable();
    
    // success code
    bool r = false;
    // compile and run file
    //r = chuck->compileFile( "ck/dot-circle.ck" );
    //r = chuck->compileFile( "ck/solar.ck" );
    r = chuck->compileFile( "ck/lines.ck" );
    // r = chuck->compileFile( "ck/text.ck" );
    //r = chuck->compileFile( "ck/flares.ck" ); // need audio input
    //r = chuck->compileFile( "ck/points.ck" );
    // r = chuck->compileFile( "ck/head.ck" );
    // r = chuck->compileFile( "ck/mesh.ck" );
    r = chuck->compileFile( "ck/leap.ck" );
    
    // Spatialization Chubgraph test (chuck these two together)
    //r = chuck->compileFile( "ck/3d/BPanner.ck" );
    //r = chuck->compileFile( "ck/3dsound.ck" );
    
    // r = chuck->compileFile( "ck/turenas.ck" );
    
    
    // check
    if( !r )
    {
        // set error
        m_message = "ERROR compiling ChucK code\n(check console for details...)";
    }
    
    // setup the sound stream...
    soundStream.setup( this,
                      MY_CHANNELS_OUT, // output
                      MY_CHANNELS_IN,  // input
                      MY_SRATE,        // sample rate
                      MY_BUFFERSIZE,   // buffer size
                      MY_NUMBUFFERS ); // num buffer
    
    // LEAP STUFF ------------------------------------------------------------
    ofxLeap.open();
    
    // TEXTURE STUFF ---------------------------------------------------------
    //
    // ofBox uses texture coordinates from 0-1, so you can load whatever
    // sized images you want and still use them to texture your box
    // but we have to explicitly normalize our tex coords here
    ofEnableNormalizedTexCoords();
    
    // load image
    OFCKDB::instance()->loadImage("texture:flare-1", "flare-tng-1.png");
    OFCKDB::instance()->loadImage("texture:flare-2", "flare-tng-2.png");
    OFCKDB::instance()->loadImage("texture:flare-3", "flare-tng-3.png");
    OFCKDB::instance()->loadImage("texture:flare-4", "flare-tng-4.png");
    OFCKDB::instance()->loadImage("texture:flare-5", "flare-tng-5.png");
    
    // FONT STUFF ------------------------------------------------------------
    arial.loadFont(ofToDataPath("font/Arial.ttf"), 14, true, true);
    arial.setLineHeight(18.0f);
    arial.setLetterSpacing(1.037);
}




//------------------------------------------------------------------------------
// name: update()
// desc: update the system
//------------------------------------------------------------------------------
void ofApp::update()
{
    // get root
    VREntity * r = VR::instance()->root();
    bg.update(Vector3D(r->col.x, r->col.y, r->col.z), 10);
    bg.interp(1/60.0f);

    // Update leap data
    simpleHands = ofxLeap.getSimpleHands();
    ofxLeap.markFrameAsOld(); // Done with this leap frame
    

    // DEBUG print hand positions
    if (simpleHands.size() != 0){
        for (int i=0; i<simpleHands.size(); i++){
            printf("Hand %d pos: %.2f %.2f %.2f\n",
                   i,
                   simpleHands[i].handPos.x,
                   simpleHands[i].handPos.y,
                   simpleHands[i].handPos.z
                   );
        }
    }
    // END DEBUG
    
    // synchronize so we can update VR instance
    VR::instance()->lock();

    
    // get leap
    VREntity * leap = vr->leap();
    
    // if leap saw a hand...
    if (simpleHands.size() != 0)
    {
        // set position
        leap->loc.x = simpleHands[0].handPos.x;
        leap->loc.y = simpleHands[0].handPos.y;
        leap->loc.z = simpleHands[0].handPos.z;
    }
    else
    {
        // set positions to 0
        leap->loc.x = 0;
        leap->loc.y = 0;
        leap->loc.z = 0;
    }

    // update it
    vr->root()->updateAll(1/60.0f);
    // update leap
    vr->leap()->updateAll(1/60.0f);
    
    // trigger displaySync to chuck
    chuck->displaySync();
    
    // finish sychronization
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
    
    // synchronize
    VR::instance()->lock();
    //--------------------------------------------------------------------------
    // draw ChucK-controlled elements
    //--------------------------------------------------------------------------
    // enable depth test
    ofEnableDepthTest();
    
    // Camera params
    m_camera.setFov( 90 );                             // set fov
    m_camera.setNearClip( .1 );                        // set near clipping plane
    m_camera.setPosition( ofVec3f(0,0,10) );           // set position
    m_camera.lookAt( ofVec3f(0,0,0), ofVec3f(0,1,0) ); // look at
    
    // Start camera
    m_camera.begin();

    // Render light
    if( VR::instance()->lightSwitch() ) ofEnableLighting();
    else ofDisableLighting();
    
    // Update it!
    vr->root()->renderAll();
    
    // Stop rendering light
    ofDisableLighting();
    
    // Sychronize
    VR::instance()->release();
}


//------------------------------------------------------------------------------
// name: audioIn()
// desc: audio input callback
//------------------------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels)
{
    assert( bufferSize == MY_BUFFERSIZE  );
    assert( nChannels  == MY_CHANNELS_IN );
    chuck->onInput( input, bufferSize );
}


//------------------------------------------------------------------------------
// name: audioOut()
// desc: audio output callback
//------------------------------------------------------------------------------
void ofApp::audioOut(float * output, int bufferSize, int nChannels)
{
    assert( bufferSize == MY_BUFFERSIZE   );
    assert( nChannels  == MY_CHANNELS_OUT );
    // chuck
    chuck->onOutput( output, bufferSize );
}


//------------------------------------------------------------------------------
// name: keyPressed()
// desc: on key pressed
//------------------------------------------------------------------------------
void ofApp::keyPressed(int key)
{
    if( key == 'f' )
    {
        // gotta toggle full screen for it to be right
        ofToggleFullscreen();
    }
    if(key == 'a'){
        cout << "FPS " << ofGetFrameRate() << " TARGET " << ofGetTargetFrameRate() << endl;
    }
    if(key == 'h'){
        ofHideCursor();
    }
    if(key == 'H'){
        ofShowCursor();
    }
}


//------------------------------------------------------------------------------
// name: keyReleased()
// desc: on key released
//------------------------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//------------------------------------------------------------------------------
// name: mouseMoved()
// desc: on mouse moved
//------------------------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{
    chuck->db()->setFloat( "mouse-x", x );
    chuck->db()->setFloat( "mouse-y", y );
}

//------------------------------------------------------------------------------
// name: mouseDragged()
// desc: on mouse dragged
//------------------------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//------------------------------------------------------------------------------
// name: mousePressed()
// desc: on mouse pressed
//------------------------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//------------------------------------------------------------------------------
// name: mouseReleased()
// desc: on mouse released
//------------------------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//------------------------------------------------------------------------------
// name: mouseEntered()
// desc: on mouse entered
//------------------------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//------------------------------------------------------------------------------
// name: mouseExited()
// desc: on mouse exited
//------------------------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//------------------------------------------------------------------------------
// name: windowResized()
// desc: on window resized
//------------------------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    // log
    cerr << "window resized w: " << w << " h: " << h << endl;
}

//------------------------------------------------------------------------------
// name: gotMessage()
// desc: on receive of message
//------------------------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//------------------------------------------------------------------------------
// name: dragEvent()
// desc: on drag event
//------------------------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
