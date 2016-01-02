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
    // update
    void update( double dt );
    // render
    void render();
};




#endif
