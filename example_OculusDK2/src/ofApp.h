#pragma once

#include "ofMain.h"
#include "ofxChucK.h"
#include "ofxOculusDK2.h"


#define MY_SRATE        44100
#define MY_CHANNELS_IN  0
#define MY_CHANNELS_OUT 2
#define MY_BUFFERSIZE   1024
#define MY_NUMBUFFERS   4


//------------------------------------------------------------------------------
// name: class ofApp
// desc: the app
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

public:
    // Oculus DK2 stuff
    ofxOculusDK2 oculusRift;
    
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
    // the VR
    VR * vr;
    // display string
    std::string m_message;
    
public:
    // the camera
    ofCamera m_camera;
    // a light
    ofLight * m_light;
    // font
    ofTrueTypeFont	arial;
};
