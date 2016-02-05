//------------------------------------------------------------------------------
// name: ofck.h
// desc: openframeworks <=> ChucK bridge; ChucK-side bindings
//
// @author  Ge Wang
// @author  Tim O'Brien
// @author  Kitty Shi
// @author  Madeline Huberth
//
// @date    Fall 2015
//------------------------------------------------------------------------------
#ifndef __OF_CK_H__
#define __OF_CK_H__


#include "chuck_dl.h"
#include "util_thread.h"
#include "x-buffer.h"
#include "x-vector3d.h"
#include "ofMain.h"
#include <deque>


// the query function for ofck
DLL_QUERY ofck_query( Chuck_DL_Query * QUERY );




//------------------------------------------------------------------------------
// nane: class VREntity
// desc: base entity class
//------------------------------------------------------------------------------
class VREntity
{
public:
    // constructor
    VREntity();
    // destructor
    ~VREntity();

public:
    // add child
    void addChild( VREntity * child );
    // remove child
    void removeChild( VREntity * child );

public:
    // sync data with chuck
    void syncFromChucK();
    // sync data to chuck
    void syncToChucK();
    // get chuck-side object
    Chuck_Object * chuckObject() { return m_chuckObject; }
    // allocate the chuck object
    bool initChucKSideObject();

public:
    // update
    virtual void update( double delta );
    // render
    virtual void render();

public:
    // late-binding commands
    virtual bool eval( const std::string & command ) { return false; }
    virtual bool eval( const std::string & op, const std::string & args )
    { eval( op + " " + args ); }

public:
    // update all, cascading to children
    void updateAll( double delta );
    // render all, cascading to children
    void renderAll();
    
public:
    // location
    Vector3D loc;
    // orientation
    Vector3D ori;
    // scaling
    Vector3D sca;
    // color
    Vector3D col;
    // alpha value
    float alpha;

protected:
    // applies translation, rotation, etc
    void applyTransforms();
    // pop
    void popTransforms();

protected:
    // child nodes in the scene graph
    std::vector<VREntity *> children;
    
public:
    // key-value map
    std::map<std::string, std::string> settings;
    // key-value map
    std::map<std::string, float> settingf;
    // associate a string value with a key
    std::string setString( const std::string & key, const std::string & value );
    // get a vec3 value associated with a key
    std::string getString( const std::string & key );
    // associate a float value with a key
    float setFloat( const std::string & key, float value );
    // get a vec3 value associated with a key
    float getFloat( const std::string & key );
    
public:
    // data sync (0 == from chuck; 1 == to chuck)
    void setSyncMode( bool which );
    
protected:
    // which way to sync
    bool m_shouldISyncFromChucK;
    bool m_shouldISyncToChucK;

protected:
    // how chuck sees this entity (chuck type: VREntity)
    Chuck_Object * m_chuckObject;
};




//------------------------------------------------------------------------------
// name: struct EvalCommand
// desc: information to execute/defer an entity eval command
//------------------------------------------------------------------------------
struct EvalCommand
{
    // the entity doing the eval
    VREntity * entity;
    // the command
    std::string command;
    
    // constructor
    EvalCommand( VREntity * e = NULL, const std::string & str = "" )
    { entity = e; command = str; }
};




//------------------------------------------------------------------------------
// name: class ofckdb
// desc: ofck database
//------------------------------------------------------------------------------
class OFCKDB
{
public:
    // constructor
    OFCKDB();

public:
    // associate a int value with a key
    t_CKINT setInt( const std::string & key, t_CKINT value );
    // get a int value associated with a key
    t_CKINT getInt( const std::string & key );
    // associate a float value with a key
    t_CKFLOAT setFloat( const std::string & key, t_CKFLOAT value );
    // get a float value associated with a key
    t_CKFLOAT getFloat( const std::string & key );
    // associate a vec3 value with a key
    t_CKVEC3 setVec3( const std::string & key, t_CKVEC3 value );
    // get a vec3 value associated with a key
    t_CKVEC3 getVec3( const std::string & key );
    // associate a vec4 value with a key
    t_CKVEC4 setVec4( const std::string & key, t_CKVEC4 value );
    // get a vec3 value associated with a key
    t_CKVEC4 getVec4( const std::string & key );
    // associate a string value with a key
    std::string setString( const std::string & key, const std::string & value );
    // get a vec3 value associated with a key
    std::string getString( const std::string & key );
    // associate an VREntity with a key
    VREntity * setObject( const std::string & key, VREntity * e );
    // get an object associated with a key
    VREntity * getObject( const std::string & key );
    // associate an image with a key
    ofImage * setImage( const std::string & key, ofImage * image );
    // load image and associate it with a key
    ofImage * loadImage( const std::string & key, const std::string & name, bool replace = true );
    // get an image associated with a key
    ofImage * getImage( const std::string & key );
    // set camera associated with a key
    ofCamera * setCamera( const std::string & key, ofCamera * cam );
    // get a camera associated with a key
    ofCamera * getCamera( const std::string & key );
    // set light associated with a key
    ofLight * setLight( const std::string & key, ofLight * light );
    // get a light associated with a key
    ofLight * getLight( const std::string & key );
    
public:
    // enqueue eval command to be executed later
    void deferEval( VREntity * e, const std::string & line );
    // flush eval queue
    void flushEval();

public:
    // instance
    static OFCKDB * instance() {
        // check
        if( ourInstance == NULL ) { ourInstance = new OFCKDB; }
        return ourInstance;
    }

public:
    // static instance
    static OFCKDB * ourInstance;

public:
    // string to int map
    std::map<std::string, t_CKINT> string2int;
    // string to float map
    std::map<std::string, t_CKFLOAT> string2float;
    // string to float map
    std::map<std::string, t_CKVEC3> string2vec3;
    // string to float map
    std::map<std::string, t_CKVEC4> string2vec4;
    // string to string map
    std::map<std::string, std::string> string2string;
    // string to entity map
    std::map<std::string, VREntity *> string2entity;
    // string to image map
    std::map<std::string, ofImage *> string2image;
    // string to camera map
    std::map<std::string, ofCamera *> string2camera;
    // string to light map
    std::map<std::string, ofLight *> string2light;

    // display sync event is broadcast right before each new graphics frame
    Chuck_Event displaySync;
    // event buffer for queue broadcat
    CBufferSimple * m_eventBuffer;

public:
    // command queue
    // std::deque<EvalCommand> m_evalQueue;
    XCircleBuffer<EvalCommand> m_evalQueue;
};




//------------------------------------------------------------------------------
// name: class VR
// desc: top-level VR routines
//------------------------------------------------------------------------------
class VR
{
public:
    // constructor
    VR();
    // destructor
    virtual ~VR();

public:
    // get the scene root
    VREntity * root();
    // get head
    VREntity * head();

public:
    // set field of view
    float setFOV( float value );
    // get field of view
    float getFOV();
    
public:
    // all lights on
    void allLightsOn() { m_allLightsOn = true; }
    // all lights off
    void allLightsOff() { m_allLightsOn = false; }
    // get state
    bool lightSwitch() const { return m_allLightsOn; }

public:
    // acquire chuck lock
    void lock() { m_lock.acquire(); }
    // release chuck lock
    void release() { m_lock.release(); }
    
public:
    // singleton
    static VR * instance() {
        // allocate if needed
        if( ourInstance == NULL ) {
            ourInstance = new VR();
            OFCKDB::instance()->setObject( "root", ourInstance->m_root );
        }
        
        return ourInstance;
    }
    
public:
    // static instance
    static VR * ourInstance;

public:
    // scene graph root
    VREntity * m_root;
    // head as entity
    VREntity * m_head;

public:
    // all lights on or off
    bool m_allLightsOn;
    
protected:
    // chuck mutex
    XMutex m_lock;
};




#endif
