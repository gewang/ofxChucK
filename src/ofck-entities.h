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




//------------------------------------------------------------------------------
// name: classVRMeshEntity
// desc: mesh
//
// EVAL commands:
//   "vertex x y z"
//   "color r g b a"
//   "uv u v"
//   "normal x y z"
//   "texture name"
//   "draw points|lines|linestrip|triangles|trianglestrips|quads|quadstrips"
//   "mode wireframe|fill]"
//   "generate [shape]"
//        "box width height depth"
//        "cone radius height"
//        "cylinder radius height"
//        "icosahedron radius"
//        "
//   "toggle color on|off"
//   "axis on|off"
//------------------------------------------------------------------------------
class VRMeshEntity : public VREntity
{
public:
    // constructor
    VRMeshEntity();
    // render
    virtual void render();
    // command: add
    virtual bool eval( const std::string & command );
    
public:
    // vertices
    std::vector<Vector3D> m_vertices;
};




//------------------------------------------------------------------------------
// name: classVRLinesEntity
// desc: lines; EVAL: "add x1 y1 z1 x2 y2 z2" to add
//------------------------------------------------------------------------------
class VRLinesEntity : public VREntity
{
public:
    // constructor
    VRLinesEntity();
    // render
    virtual void render();
    // command: add
    virtual bool eval( const std::string & command );

public:
    // pairs of vertices
    std::vector<Vector3D> m_vertices;
};




//------------------------------------------------------------------------------
// name: class VRDotEntity
// desc: dot entity
//------------------------------------------------------------------------------
class VRDotEntity : public VREntity
{
public:
    // constructor
    VRDotEntity();
    // render
    virtual void render();

public:
    ofSpherePrimitive sphere;
};




#endif
