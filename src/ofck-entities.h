//------------------------------------------------------------------------------
// name: ofck-entities.h
// desc: graphics objects
//
// @author  Ge Wang
// @author  Tim O'Brien
// @author  Kitty Shi
// @author  Madeline Huberth
//
// @date    Winter 2015
//------------------------------------------------------------------------------
#ifndef __OF_CK_ENTITIES_H__
#define __OF_CK_ENTITIES_H__

#include "ofck.h"
#include "ofMain.h"




//------------------------------------------------------------------------------
// name: class VREntityFactory
// desc: entity instantiator
//------------------------------------------------------------------------------
class VREntityFactory
{
public:
    // make entity
    static VREntity * makeEntity( const std::string & type );
};




//------------------------------------------------------------------------------
// name: class VRFlare
// desc: a single additive blended thing
//------------------------------------------------------------------------------
class VRFlare : public VREntity
{
public:
    // constructor
    VRFlare();
    // destructor
    ~VRFlare();
    
public:
    // set image for drawing
    void setImage( ofImage * imageRef );
    // set image for drawing by name (via OFCKDB)
    void setImage( const std::string & key );

public:
    // update
    void update( double dt );
    // render
    void render();

protected:
    // reference to image
    ofImage * m_imageRef;
    // blend mode
    ofBlendMode m_blendMode;
};




#endif
