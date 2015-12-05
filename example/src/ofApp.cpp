#include "ofApp.h"

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
    
    // compile and run another file
    chuck->compileFile( "/Users/ge/research/oF/of_v0.9.0_osx_release/addons/ofxChucK/example/ck/the.ck", "" );

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
    
    // trigger displaySync to chuck
    chuck->displaySync();
}

//--------------------------------------------------------------
void ofApp::draw()
{
    //texGray.draw(100,100,w,h);
    m_texColor.draw(350,300,w,h);
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
