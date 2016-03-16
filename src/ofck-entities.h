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
#include <deque>




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
    // eval
    bool eval( const std::string & line );
    // update
    void update( double dt );
    // render
    void render();

protected:
    // reference to image
    ofImage * m_imageRef;
    // blend mode
    ofBlendMode m_blendMode;
    // mesh to bind to
    ofMesh m_mesh;
    // helper function for updating points in mesh on image change
    void updateMeshPoints();
    
};




//------------------------------------------------------------------------------
// name: classVRMeshEntity
// desc: mesh
//
// EVAL commands:
//   "clear"
//   "vertex x y z"
//   "color r g b"
//   "color r g b a"
//   "uv u v"
//   "normal x y z"
//   "texture name"
//   "mode wireframe|fill]"
//   "draw points|lines|linestrip|triangles|trianglestrips"
//   "generate [shape]"
//        "box width height depth"
//        "cone radius height"
//        "cylinder radius height"
//        "icosahedron radius"
//        "icosphere radius iterations"
//        "plane width height"
//        "sphere radius resolution"
//   "load [OBJ file]"
//   "toggle color on|off"
//   "toggle axis on|off"
//   "update vertex|color|uv|normal index [data]"
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
    // load OBJ file
    bool loadOBJ( const std::string & path );
    
public:
    // load OBJ file
    static bool loadOBJFile(
        const std::string & path,
        std::vector<ofVec3f> & outVertices,
        std::vector<ofVec3f> & outNormals,
        std::vector<ofVec2f> & outUVs );

public:
    // set image for drawing
    void setImage( ofImage * imageRef );
    // set image for drawing by name (via OFCKDB)
    void setImage( const std::string & key );
    
public:
    // the mesh
    ofMesh m_mesh;
    // the texture
    ofImage * m_imageRef;
    // how to draw
    bool m_fill;
    // line width
    float m_lineWidth;
};




//------------------------------------------------------------------------------
// name: class VRLinesEntity
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
// name: class VRTextEntity
// desc: text
//
// EVAL: "set text"
// EVAL: "load TTF"
//------------------------------------------------------------------------------
class VRTextEntity : public VREntity
{
public:
    // constructor
    VRTextEntity();
    // update
    virtual void update( double dt );
    // render
    virtual void render();
    // command: add
    virtual bool eval( const std::string & command );
    
public:
    // the true type font
    ofTrueTypeFont m_font;
    // load on next update
    std::string m_fontToLoad;
    // size to load
    int m_sizeToLoad;
    // text to draw
    std::string m_text;
};




//------------------------------------------------------------------------------
// name: class VRLightEntity
// desc: rotating light source composed of flares
//
// EVAL commands:
//   "num [number of sources]"
//   "rotate [speed]"
//   "texture [texture]"
//------------------------------------------------------------------------------
class VRLightEntity : public VRFlare
{
public:
    // constructor
    VRLightEntity();
    // render
    virtual void render();
    // command: set parameters
    virtual bool eval( const std::string & command );
    // update
    virtual void update( double dt );

public:
    // how many
    int numSources;
    // intrinsic orientation
    Vector3D intrinsicOri;
    // rotational speed
    Vector3D intrinsicRotation;
};




//------------------------------------------------------------------------------
// name: class VRTrailEntity
// desc: trail entity
//
// EVAL commands:
//   "add [latest vertex]
//   "length [number of vertices in trail]"
//   "draw points|linestrip|trianglestrips"
//------------------------------------------------------------------------------
class VRTrailEntity : public VREntity
{
public:
    // constructor
    VRTrailEntity();

public:
    // update
    virtual void update( double dt );
    // render
    virtual void render();
    // command: set parameters
    virtual bool eval( const std::string & command );

public:
    // clear tail points
    void clear();
    // add a new point
    void addVertex( const Vector3D & v3 );
    // resize length of trail
    void setLength( int N );

public:
    // tail points
    std::deque<Vector3D> m_vertices;
    // the mesh
    ofMesh m_mesh;
    // trail length
    int m_length;
    // fill or wireframe
    bool m_fill;
    // line width
    float m_lineWidth;
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
    // eval
    virtual bool eval( const std::string & command );
    
public:
    // set image for drawing
    void setImage( ofImage * imageRef );
    // set image for drawing by name (via OFCKDB)
    void setImage( const std::string & key );

public:
    ofSpherePrimitive sphere;
    // the texture
    ofImage * m_imageRef;
};




//------------------------------------------------------------------------------
// name: class VRBlowStringEntity
// desc: a single additive blended vibrating string
//
// EVAL commands:
//   "speed   [oscillation frequency]"
//   "amount  [oscillation amplitude]"
//   "phase   [oscillation phase]"
//   "texture [texture database handle]"
//------------------------------------------------------------------------------
class VRBlowStringEntity : public VREntity {
public:
    // constructor
    VRBlowStringEntity();
    
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
    // eval: change animation amount
    virtual bool eval( const std::string & command );

protected:
    // helper to constructor
    void formMesh();
    // helper to update()
    void updateMesh();
    // reference to image
    ofTexture * m_imageRef;
    // blend mode
    ofBlendMode m_blendMode;
    // mesh to draw
    ofMesh glowMesh;
    // constants
    const float defaultHeight = 0.5;
    const float defaultWidth = 0.5;
    // animation parameters
    float time;
    float animationAmount;
    float animationSpeed;
    float animationPhase;
};




//------------------------------------------------------------------------------
// name: class VRNickEntity
// desc: a single additive blended vibrating string
// source: ported from https://github.com/nickgang/soundcave
//
// EVAL commands:
//   "rotate x|y [rotation speed]"
//   "toggle split|fill|wireframe|normals|axes"
//------------------------------------------------------------------------------
class VRNickEntity : public VREntity {
public:
    // constructor
    VRNickEntity();
    
public:
    // render
    void render();
    // eval: change animation amount
    virtual bool eval( const std::string & command );

protected:
    // main object
    ofIcoSpherePrimitive sphere;
    // material
    ofMaterial material;
    // mesh surface
    vector<ofMeshFace> triangles;
    // animation parameters
    float time;
    float rotateSpeedX;
    float rotateSpeedY;
    bool drawSplit;
    bool drawFill;
    bool drawWireframe;
    bool drawNormals;
    bool drawAxes;
    
};


#endif
