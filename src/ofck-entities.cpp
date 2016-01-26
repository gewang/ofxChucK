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
#include <algorithm>
#include <string>
#include <sstream>
using namespace std;




//------------------------------------------------------------------------------
// name: lowerCase()
// desc: lower case a string
//------------------------------------------------------------------------------
string lowerCase( const string & s )
{
    // copy
    string str = s;
    // to lower each letter via iteration
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    // return
    return str;
}




//------------------------------------------------------------------------------
// name: trimStr()
// desc: trim whitespace from beginning and end of string
//------------------------------------------------------------------------------
string trimStr( const string & str )
{
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last-first+1));
}




//------------------------------------------------------------------------------
// name: makeEntity()
// desc: instantiate entity of certain type
//------------------------------------------------------------------------------
VREntity * VREntityFactory::makeEntity( const std::string & type )
{
    // lower case it
    string s = lowerCase( type );
    // check/remove prefix
    if( s.length() > 2 && s[0] == 'v' && s[1] == 'r' )
    {
        // remove prefix
        s = s.substr(2);
    }

    // the pointer to return
    VREntity * e = NULL;

    // check type
    if( type == "flare" ) { e = new VRFlare(); }
    else if( type == "mesh" ) { e = new VRMeshEntity(); }
    else if( type == "points" ) { e = new VRMeshEntity(); }
    else if( type == "lines" ) { e = new VRLinesEntity(); }
    else if( type == "linestrip" ) { }
    else if( type == "triangles" ) { }
    else if( type == "trianglestrip" ) { }
    else if( type == "circle" ) { }
    else if( type == "text" ) { e = new VRTextEntity(); }
    else if( type == "ugen" ) { }
    else if( type == "dot" ) { e = new VRDotEntity(); }
    
    // log
    if( !e )
    {
        // warning
        cerr << "[VREntityFactory]: unknown type: '" << type << "'..." << endl;
    }
    
    // done
    return e;
}




//------------------------------------------------------------------------------
// constructor
//------------------------------------------------------------------------------
VRMeshEntity::VRMeshEntity()
{
    // set draw
    eval( "draw lines" );
}




//------------------------------------------------------------------------------
// render
//------------------------------------------------------------------------------
void VRMeshEntity::render()
{
    m_mesh.draw();
}




//------------------------------------------------------------------------------
// command: add
//------------------------------------------------------------------------------
bool VRMeshEntity::eval( const std::string & theLine )
{
    string line = lowerCase( theLine );
    
    // word
    string token;
    // string stream
    istringstream istr( line );
    // the command
    string command;
    // get it
    istr >> command;
    
    // sanity check
    if( command == "" )
    {
        // empty command
        cerr << "[VRMeshEntity]: empty EVAL command!" << endl;
        // done
        return false;
    };

    // the number
    float x, y, z;
    // string
    string str;

    // check
    if( command == "vertex" )
    {
        // loop
        if( istr >> x >> y >> z )
        {
            // push as float
            m_mesh.addVertex( ofVec3f(x,y,z) );
        }
    }
    if( command == "clear" )
    {
        // clear
        m_mesh.clear();
    }
    else if( command == "color" )
    {
        // loop
        if( istr >> x >> y >> z )
        {
            // push as float
            m_mesh.addColor( ofFloatColor(x,y,z) );
        }
    }
    else if( command == "normal" )
    {
        // loop
        if( istr >> x >> y >> z )
        {
            // push as float
            m_mesh.addNormal( ofVec3f(x,y,z) );
        }
    }
    else if( command == "uv" )
    {
        // loop
        if( istr >> x >> y )
        {
            // push as float
            m_mesh.addTexCoord( ofVec2f(x,y) );
        }
    }
    else if( command == "texture" )
    {
        // loop
        if( istr >> str )
        {
            // get instance
            OFCKDB * db = OFCKDB::instance();
            // get the image
            m_texture = db->getImage( str );
        }
    }
    else if( command == "draw" )
    {
        // loop
        if( istr >> str )
        {
            // check
            if( str == "points" )
                m_mesh.setMode( OF_PRIMITIVE_POINTS );
            else if( str == "lines" )
                m_mesh.setMode( OF_PRIMITIVE_LINES );
            else if( str == "linestrip" )
                m_mesh.setMode( OF_PRIMITIVE_LINE_STRIP );
            else if( str == "lineloop" )
                m_mesh.setMode( OF_PRIMITIVE_LINE_LOOP );
            else if( str == "triangles" )
                m_mesh.setMode( OF_PRIMITIVE_TRIANGLES );
            else if( str == "trianglestrip" )
                m_mesh.setMode( OF_PRIMITIVE_TRIANGLE_STRIP );
            else if( str == "trianglefan" )
                m_mesh.setMode( OF_PRIMITIVE_TRIANGLE_FAN );
            else
            {
                // error
                cerr << "[VRMeshEntity]: invalid DRAW type: '" << str << "'" << endl;
                // done
                return false;
            }
        }
    }
    else if( command == "generate" )
    {
        // get from stream
        if( istr >> str )
        {
            // check
            if( str == "sphere" )
            {
                float radius = 0;
                int res = 12;
                // get them
                if( !(istr >> radius) )
                {
                    // error
                    cerr << "[VRMeshEntity]: GENERATE SPHERE missing radius..." << endl;
                    // done
                    return false;
                }
                // get them
                if( !(istr >> res) )
                {
                    // set default
                    res = 12;
                }
                // set it
                m_mesh = ofMesh::sphere( radius, res );
            }
        }
    }
}




//------------------------------------------------------------------------------
// constructor
//------------------------------------------------------------------------------
VRTextEntity::VRTextEntity()
{
    // default
    m_sizeToLoad = 64;
}




//------------------------------------------------------------------------------
// render
//------------------------------------------------------------------------------
void VRTextEntity::update( double dt )
{
    // check
    if( m_fontToLoad != "" )
    {
        // load it
        m_font.loadFont( m_fontToLoad, m_sizeToLoad );
        // clear
        m_fontToLoad = "";
    }
}




//------------------------------------------------------------------------------
// render
//------------------------------------------------------------------------------
void VRTextEntity::render()
{
    // disable depth
    ofDisableDepthTest();
    // the size
    int size = m_font.getSize();
    // check
    if( size > 0 )
    {
        // scale down
        ofScale(1.0/size, 1.0/size, 1.0/size);
        // draw it
        m_font.drawString( m_text, 0, 0 );
    }
}




//------------------------------------------------------------------------------
// command: add
//------------------------------------------------------------------------------
bool VRTextEntity::eval( const std::string & theLine )
{
    // line
    string line = lowerCase( theLine );
    
    // token
    string token;
    // string stream
    istringstream istr(line);
    // the command
    string command;
    // get it
    istr >> command;
    
    // sanity check
    if( command == "" ) return false;
    
    // check
    if( command == "load" )
    {
        // read
        if( !(istr >> m_fontToLoad) )
        {
            // error
            cerr << "[VRTextEntity]: LOAD not enough arguments..." << endl;
            // done
            return false;
        }
        // read
        if( !(istr >> m_sizeToLoad) )
        {
            m_sizeToLoad = 64;
        }
    }
    else if( command == "set" )
    {
        // argument
        string text;
        // get rest of string
        getline( istr, text );
        // trim it
        trimStr( text );
        // read
        if( text == "" )
        {
            // error
            cerr << "[VRTextEntity]: SET not enough arguments..." << endl;
            // done
            return false;
        }
        // load it
        m_text = text;
    }
    
    return true;
}




//------------------------------------------------------------------------------
// constructor
//------------------------------------------------------------------------------
VRLinesEntity::VRLinesEntity()
{
    // do nothing
}




//------------------------------------------------------------------------------
// render
//------------------------------------------------------------------------------
void VRLinesEntity::render()
{
    // actual size
    int N = m_vertices.size() / 2 * 2;
    // loop over lines
    for( int i = 0; i < N; i+=2 )
    {
        // render
        ofLine( m_vertices[i].x, m_vertices[i].y, m_vertices[i].z,
                m_vertices[i+1].x, m_vertices[i+1].x, m_vertices[i+1].x );
    }
}




//------------------------------------------------------------------------------
// command: add
//------------------------------------------------------------------------------
bool VRLinesEntity::eval( const std::string & theLine )
{
    string line = lowerCase( theLine );

    // word
    string token;
    // string stream
    istringstream istr( line );
    // the command
    string command;
    // get it
    istr >> command;
    
    // sanity check
    if( command == "" )
    {
        // empty command
        cerr << "[VRLinesEntity]: empty EVAL command!" << endl;
        // done
        return false;
    };

    // check
    if( command == "add" ) // add point
    {
        // the number
        float x1, y1, z1, x2, y2, z2;
        
        // loop
        if( istr >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 )
        {
            // push as float
            m_vertices.push_back( Vector3D(x1,y1,z1) );
            m_vertices.push_back( Vector3D(x2,y2,z2) );
        }
    }
}




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
    // look up and set image ref
    setImage( getString("texture") );
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

    // disable depth
    ofDisableDepthTest();
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




//------------------------------------------------------------------------------
// name: VRDotEntity()
// desc: constructor
//------------------------------------------------------------------------------
VRDotEntity::VRDotEntity()
: sphere( 1, 10 )
{}




//------------------------------------------------------------------------------
// name: render()
// desc: draw the thing
//------------------------------------------------------------------------------
void VRDotEntity::render()
{
    // ofSetColor( 255 );
    sphere.draw();
}