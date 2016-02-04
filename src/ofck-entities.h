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
    // the mesh
    ofMesh m_mesh;
    // the texture
    ofImage * m_texture;
    // how to draw
    bool m_fill;
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
class VRLightEntity : public VREntity
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
    // the lights
    vector< VRFlare > lights;
    // how many
    int numSources;
    // rotational speed
    float rotateSpeed;
    // texture key
    string textureKey;
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
