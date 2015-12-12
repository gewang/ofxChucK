#include "ofApp.h"




//------------------------------------------------------------------------------
// name: VRDotEntity()
// desc: constructor
//------------------------------------------------------------------------------
VRDotEntity::VRDotEntity()
: sphere( 100, 10 )
{}




//------------------------------------------------------------------------------
// name: render()
// desc: draw the thing
//------------------------------------------------------------------------------
void VRDotEntity::render()
{
    // ofSetColor( 255 );
    sphere.draw();
}

//VirChucK Reality
//VCKR
//
//Chutual Reality
//CKVR
//
//ChVRcK
//VirChuR
//VReCK




//--------------------------------------------------------------
void ofApp::setup()
{
    ofSetVerticalSync( true );
    ofBackground(54, 54, 54);
 
    // get singleton
    chuck = TheChucK::instance();
    // arguments
    const char * argv[] = { "the", "-v0" };

    // initialize (SHOULD HAPPEN BEFORE AUDIO STREAM STARTS)
    chuck->initialize( MY_SRATE, MY_BUFFERSIZE, MY_CHANNELS, 2, argv );

    m_dot = new VRDotEntity();
    chuck->setEntity( "dot", m_dot );
    m_dot->col.setAll(255);
    m_dot->alpha = 255;
    
    // compile and run another file
    chuck->compileFile( "/Users/ge/research/oF/of_v0.9.0_osx_release/addons/ofxChucK/example/ck/thedot.ck", "" );

    // compile and run another file
    // chuck->compileFile( "/Users/ge/research/oF/of_v0.9.0_osx_release/addons/ofxChucK/example/ck/c.ck", "" );
    
    // setup the sound stream...
    soundStream.setup( this,
                       MY_CHANNELS,     // output
                       0,               // input
                       MY_SRATE,        // sample rate
                       MY_BUFFERSIZE,   // buffer size
                       MY_NUMBUFFERS ); // num buffer
    
    // set location
    w = 250;
    h = 200;

    // set pixel format
    m_colorPixels.allocate( w,h,OF_PIXELS_RGB );
    // allocate texture
    m_texColor.allocate( m_colorPixels );

    
    // color pixels, use x and y to control red and green
    for (int y = 0; y < h; y++){
        for (int x = 0; x < w; x++){
            m_colorPixels.setColor(x,y,ofColor(x,y,0));
        }
    }
    
    // set up camera
    m_camera.setupPerspective( false, 90, .1, 300 );
    // set up sphere
    // m_sphere = new ofSpherePrimitive( 100, 50 );
    // m_sphere->setRadius( 100 );
    
    m_light = new ofLight();
    m_light->setDiffuseColor( ofColor(100, 255, 100) );
    m_light->enable();
    m_light->setGlobalPosition( 100, 100, 100 );
    
}

//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels)
{
    assert( bufferSize == MY_BUFFERSIZE );
    assert( nChannels == MY_CHANNELS );
    chuck->onInput( input, bufferSize );
}


//--------------------------------------------------------------
void ofApp::audioOut(float * output, int bufferSize, int nChannels)
{
    assert( bufferSize == MY_BUFFERSIZE );
    assert( nChannels == MY_CHANNELS );
    // chuck
    chuck->onOutput( output, bufferSize );
}


//--------------------------------------------------------------
void ofApp::update()
{
    // set background
    ofBackground( 0, 0, 0 );

    // get x and y from chuck
    float x = chuck->getFloat("color-x");
    float y = chuck->getFloat("color-y");
    
    // scerr << "x: " << x << " y: " << y << endl;

    float pct = (float)x / (float)ofGetWidth();
    for (int y = 0; y < h; y++){
        for (int x = 0; x < w; x++){
            m_colorPixels.setColor(x,y,ofColor(x,y,pct*255));
        }
    }
    // finally, load those pixels into the texture
    m_texColor.loadData(m_colorPixels);
    
    // m_dot->loc.set( ofGetWindowWidth()/2, ofGetWindowHeight()/2, 0 );
    m_dot->updateAll(1.0/60);
    // cerr << ofGetWindowWidth()/2 << " " << ofGetWindowHeight()/2 << endl;
    // cerr << m_dot->loc.x << " " << m_dot->loc.y << " " << m_dot->loc.z << endl;
    // cerr << m_dot->col.x << " " << m_dot->col.y << " " << m_dot->col.z << endl;
    // cerr << " " << m_dot->alpha << endl;
    
    // trigger displaySync to chuck
    chuck->displaySync();
}

//--------------------------------------------------------------
void ofApp::draw()
{
    m_camera.begin();
    m_light->enable();
    //texGray.draw(100,100,w,h);
    // m_texColor.draw(350,300,w,h);
    
    // ofTranslate( ofGetWindowWidth()/2, ofGetWindowHeight()/2, 0 );
    // m_sphere->draw();
    m_dot->renderAll();
    m_light->disable();
    m_camera.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y )
{
    chuck->setFloat( "mouse-x", x );
    chuck->setFloat( "mouse-y", y );
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
