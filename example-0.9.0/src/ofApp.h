#pragma once

#include "ofMain.h"
#include "ofxChucK.h"

#define MY_SRATE      44100
#define MY_CHANNELS   2
#define MY_BUFFERSIZE 128
#define MY_NUMBUFFERS 4




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
    // sound stream
    ofSoundStream soundStream;

    // the ChucK
    TheChucK * chuck;
    
public:
    // the camera
    ofCamera m_camera;
    // a light
    ofLight * m_light;
};
