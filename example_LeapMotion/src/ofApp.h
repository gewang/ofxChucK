#pragma once

#include "ofMain.h"
#include "ofxChucK.h"
#include "ofxLeapMotion2.h"

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
// The usual OpenFrameworks stuff
public:
    void setup();
	void update();
	void draw();

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
    // Audio callback functions
    void audioIn(float * input, int bufferSize, int nChannels);
    void audioOut(float * output, int bufferSize, int nChannels);
    
    ofSoundStream soundStream; // sound stream
    TheChucK * chuck;          // the ChucK
    VR * vr;                   // the VR
    std::string m_message;     // display string
    
    
// Other graphical stuff
public:
    ofCamera m_camera;     // the camera
    ofLight * m_light;     // a light
    ofTrueTypeFont	arial; // font
    iSlew3D bg;            // background, tied to root node color

// Leap Motion stuff
public:
    ofxLeapMotion ofxLeap;
    vector <ofxLeapMotionSimpleHand> simpleHands;

};
