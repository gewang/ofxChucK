#include "ofMain.h"
#include "ofApp.h"
#include "ofGLProgrammableRenderer.h"

//========================================================================
int main()
{
    ovr_InitializeRenderingShim();
    ofSetCurrentRenderer(ofGLProgrammableRenderer::TYPE);
    
    ofSetupOpenGL(1200, 800, OF_WINDOW);
    ofRunApp( new ofApp()) ; // start the app
}
