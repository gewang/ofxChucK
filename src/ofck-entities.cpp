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
    else if( type == "points" ) { }
    else if( type == "lines" ) { e = new VRLinesEntity(); }
    else if( type == "linestrip" ) { }
    else if( type == "triangles" ) { }
    else if( type == "trianglestrip" ) { }
    else if( type == "circle" ) { }
    else if( type == "text" ) { }
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
        while( istr >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 )
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