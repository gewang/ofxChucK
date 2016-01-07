#pragma once

#include "ofMain.h"
#include "ofxChucK.h"
#include "ofxOculusDK2.h"


#define MY_SRATE      44100
#define MY_CHANNELS   2
#define MY_BUFFERSIZE 256
#define MY_NUMBUFFERS 4


//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
class ofApp : public ofBaseApp
{
public:
    // audio callback functions
    void audioIn(float * input, int bufferSize, int nChannels);
    void audioOut(float * output, int bufferSize, int nChannels);

public:
    void setup();
    void update();
    void draw();
    
    void drawScene();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);

    
    ofxOculusDK2		oculusRift;
    
    ofEasyCam cam;
    bool showOverlay;
    
    ofShader bshader;
    
    ofVec3f cursor2D;
    ofVec3f cursor3D;
    
    ofVec3f cursorRift;
    ofVec3f demoRift;
    
    ofVec3f cursorGaze;
    
    
public:
    // sound stream
    ofSoundStream soundStream;
    
    // the ChucK
    TheChucK * chuck;
    
public:
    // color buffer
    ofPixels m_colorPixels;
    // the texture color
    ofTexture m_texColor;
    // width and height
    int w, h;
    
    
};
