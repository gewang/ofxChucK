//------------------------------------------------------------------------------
// name: ofck-entities.cpp
// desc: graphics objects
//
// @author  Ge Wang
// @author  Tim O'Brien
// @author  Kitty Shi
// @author  Madeline Huberth
//
// @date    Winter 2015
//------------------------------------------------------------------------------
#include "ofck-entities.h"
using namespace std;




//------------------------------------------------------------------------------
// name: VRFlare()
// desc: constructor
//------------------------------------------------------------------------------
VRFlare::VRFlare()
{
    // zero out
    m_imageRef = NULL;
    // default is additive
    m_blendMode = OF_BLENDMODE_ADD;
}




//------------------------------------------------------------------------------
// name: ~VRFlare()
// desc: destructor
//------------------------------------------------------------------------------
VRFlare::~VRFlare()
{
    // do nothing for now
}




//------------------------------------------------------------------------------
// name: setImage()
// desc: set image for drawing
//------------------------------------------------------------------------------
void VRFlare::setImage( ofImage * imageRef )
{
    // set the image
    m_imageRef = imageRef;
}




//------------------------------------------------------------------------------
// name: setImage()
// desc: set image for drawing
//------------------------------------------------------------------------------
void VRFlare::setImage( const string & key )
{
    // get instance
    OFCKDB * db = OFCKDB::instance();
    // get the image
    m_imageRef = db->getImage( key );
}




//------------------------------------------------------------------------------
// name: update()
// desc: update the flare state
//------------------------------------------------------------------------------
void VRFlare::update( double dt )
{
    // nothing for now
}




//------------------------------------------------------------------------------
// name: render()
// desc: render the flare
//------------------------------------------------------------------------------
void VRFlare::render()
{
    // check
    if( !m_imageRef ) return;
    // width of image
    float width = m_imageRef->getWidth();

    // blending
    ofEnableBlendMode( m_blendMode );
    // center
    ofSetRectMode( OF_RECTMODE_CENTER );
    
    // normalize
    ofScale( 1.0f/width, 1.0/width );
    // draw the image
    m_imageRef->draw( 0, 0 );
    // disable
    ofDisableBlendMode();
}
