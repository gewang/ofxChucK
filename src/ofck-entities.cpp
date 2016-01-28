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
    else if( type == "text" ) { e = new VRTextEntity(); }
    else if( type == "lines" ) { e = new VRLinesEntity(); }
    else if( type == "circle" ) { }
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
    // default
    m_fill = true;
}




//------------------------------------------------------------------------------
// render
//------------------------------------------------------------------------------
void VRMeshEntity::render()
{
    bool drawTexture = (m_texture != NULL);
    if (drawTexture) {
        m_texture->getTextureReference().bind();
    }
    
    if( m_fill )
    {
        m_mesh.draw();
    }
    else
    {
        m_mesh.drawWireframe();
    }
    
    if (drawTexture) {
        m_texture->getTextureReference().unbind();
    }
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
        // TODO: should clearing also clear the texture? then:
        // m_texture = NULL;
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
    else if( command == "mode" )
    {
        // get from stream
        if( !(istr >> str) )
        {
            // error
            cerr << "[VRMeshEntity]: MODE missing parameter..." << endl;
            // done
            return false;
        }
        
        m_fill = (str != "wireframe");
    }
    else if( command == "load" )
    {
        // get from stream
        if( !(istr >> str) )
        {
            // error
            cerr << "[VRMeshEntity]: LOAD missing parameter..." << endl;
            // done
            return false;
        }

        // load this
        loadOBJ( str );
    }
}




//-----------------------------------------------------------------------------
// name: loadOBJ()
// desc: load OBJ file
//-----------------------------------------------------------------------------
bool VRMeshEntity::loadOBJ( const std::string & path )
{
    // out vectors
    vector<ofVec3f> verts;
    vector<ofVec3f> normals;
    vector<ofVec2f> uvs;
    
    // load it
    bool r = loadOBJFile( path, verts, normals, uvs );
    // check it
    if( !r ) return false;
    
    // clear
    m_mesh.clear();
    
    // iterate
    for( int i = 0; i < verts.size(); i++ )
    {
        // add vertex
        m_mesh.addVertex( verts[i] );
        // set normal state
        m_mesh.addNormal( normals[i] );
        // set uv
        m_mesh.addTexCoord( uvs[i] );
    }
    
    // done
    return true;
}




//-----------------------------------------------------------------------------
// name: loadOBJ()
// desc: obj loader
// http://www.opengl-tutorial.org/beginners-tutorials/tutorial-7-model-loading/
//-----------------------------------------------------------------------------
// (from tutorial)
// Very, VERY simple OBJ loader.
// Here is a short list of features a real function would provide :
// - Binary files. Reading a model should be just a few memcpy's away, not parsing a file at runtime. In short : OBJ is not very great.
// - Animations & bones (includes bones weights)
// - Multiple UVs
// - All attributes should be optional, not "forced"
// - More stable. Change a line in the OBJ file and it crashes.
// - More secure. Change another line and you can inject code.
// - Loading from memory, stream, etc
//-----------------------------------------------------------------------------
bool VRMeshEntity::loadOBJFile(
    const string & path,
    vector<ofVec3f> & out_vertices,
    vector<ofVec3f> & out_normals,
    vector<ofVec2f> & out_uvs )
{
    // log
    cerr << "[ofxChucK]: loading OBJ file: " << path << endl;
    
    // some vectors
    std::vector<unsigned int> vertexIndices, uvIndices, normalIndices;
    std::vector<ofVec3f> temp_vertices;
    std::vector<ofVec3f> temp_normals;
    std::vector<ofVec2f> temp_uvs;
    
    // clear
    out_vertices.clear();
    out_normals.clear();
    out_uvs.clear();
    
    // open file
    FILE * file = fopen( ofToDataPath(path).c_str(), "r" );
    // check
    if( file == NULL )
    {
        // log
        cerr << "[ofxChucK]: cannot open OBJ file..." << endl;
        // done
        return false;
    }
    
    // start reading
    while( true )
    {
        // c string
        char lineHeader[128];
        // read the first word of the line
        int res = fscanf( file, "%s", lineHeader );
        // end of file, break
        if( res == EOF ) break;
        
        // parse header
        if( strcmp( lineHeader, "v" ) == 0 )
        {
            // vertex
            ofVec3f vertex;
            // read x, y, z
            fscanf( file, "%f %f %f\n", &vertex.x, &vertex.y, &vertex.z );
            // append
            temp_vertices.push_back( vertex );
        }
        else if( strcmp( lineHeader, "vt" ) == 0 )
        {
            // texture coordinate
            ofVec2f uv;
            // read u, v
            fscanf( file, "%f %f\n", &uv.x, &uv.y );
            // invert (DDS); remove for TGA/BMP loaders
            uv.y = -uv.y;
            // append
            temp_uvs.push_back(uv);
        }
        else if( strcmp( lineHeader, "vn" ) == 0 )
        {
            // normal
            ofVec3f normal;
            // read x, y, z
            fscanf( file, "%f %f %f\n", &normal.x, &normal.y, &normal.z );
            // append
            temp_normals.push_back(normal);
        }
        else if( strcmp( lineHeader, "f" ) == 0 )
        {
            // vertices
            std::string vertex1, vertex2, vertex3;
            unsigned int vertexIndex[3], uvIndex[3], normalIndex[3];
            // read it
            int matches = fscanf(file, "%d/%d/%d %d/%d/%d %d/%d/%d\n",
                                 &vertexIndex[0], &uvIndex[0], &normalIndex[0],
                                 &vertexIndex[1], &uvIndex[1], &normalIndex[1],
                                 &vertexIndex[2], &uvIndex[2], &normalIndex[2] );
            // check matches
            if( matches != 9 )
            {
                // log
                cerr << "[ofxChucK]: cannot parse on 'f'" << endl;
                // done
                return false;
            }
            
            // push it
            vertexIndices.push_back( vertexIndex[0] );
            vertexIndices.push_back( vertexIndex[1] );
            vertexIndices.push_back( vertexIndex[2] );
            uvIndices    .push_back( uvIndex[0] );
            uvIndices    .push_back( uvIndex[1] );
            uvIndices    .push_back( uvIndex[2] );
            normalIndices.push_back( normalIndex[0] );
            normalIndices.push_back( normalIndex[1] );
            normalIndices.push_back( normalIndex[2] );
        }
        else if( lineHeader[0] == '#' )
        {
            // read rest of line
            char buffer[1024];
            fgets( buffer, 1024, file);
        }
        else
        {
            // log
            cerr << "[ofxChucK]: unrecognized line header: " << lineHeader << endl;
            return false;
        }
    }
    
    // for each vertex of each triangle
    for( unsigned int i = 0; i < vertexIndices.size(); i++ )
    {
        // get the indices of its attributes
        unsigned int vertexIndex = vertexIndices[i];
        unsigned int normalIndex = normalIndices[i];
        unsigned int uvIndex = uvIndices[i];
        
        // get the attributes thanks to the index
        ofVec3f vertex = temp_vertices[ vertexIndex-1 ];
        ofVec3f normal = temp_normals[ normalIndex-1 ];
        ofVec2f uv = temp_uvs[ uvIndex-1 ];
        
        // put the attributes in buffers
        out_vertices.push_back(vertex);
        out_normals.push_back(normal);
        out_uvs.push_back(uv);
    }
    
    return true;
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
    
    // add the four corners to our mesh
    m_mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    
    // prepare to set color
    ofColor color;
    color.set(col.x, col.y, col.z);

    // rect width / 2
    float rw = 0.5;
    // rect height / 2: use aspect ratio of 1:1 until we get an image
    float rh = rw;

    // point 0 (tex coords are normalized for use with OculusDK2)
    m_mesh.addVertex(ofPoint(-rw, -rh));
    m_mesh.addTexCoord(ofPoint(0, 1));
    m_mesh.addColor(color);
    
    // point 1
    m_mesh.addVertex(ofPoint(rw, -rh));
    m_mesh.addTexCoord(ofPoint(0, 0));
    m_mesh.addColor(color);
    
    // point 2
    m_mesh.addVertex(ofPoint(-rw, rh));
    m_mesh.addTexCoord(ofPoint(1, 1));
    m_mesh.addColor(color);
    
    // point 3
    m_mesh.addVertex(ofPoint(rw, rh));
    m_mesh.addTexCoord(ofPoint(1, 0));
    m_mesh.addColor(color);
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
    
    updateMeshPoints();
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
    
    if (m_imageRef) {
        updateMeshPoints();
    }
}




//------------------------------------------------------------------------------
// name: updateMeshPoints()
// desc: update the mesh points with the new aspect ratio
//------------------------------------------------------------------------------
void VRFlare::updateMeshPoints()
{
    // rect width / 2
    float rw = 0.5;
    // rect height / 2: use aspect ratio of image
    float rh = rw * m_imageRef->getHeight() / m_imageRef->getWidth();
    
    m_mesh.setVertex(0, ofPoint( -rw, -rh ));
    m_mesh.setVertex(1, ofPoint( -rw,  rh ));
    m_mesh.setVertex(2, ofPoint(  rw, -rh ));
    m_mesh.setVertex(3, ofPoint(  rw,  rh ));
}




//------------------------------------------------------------------------------
// name: update()
// desc: update the flare state
//------------------------------------------------------------------------------
void VRFlare::update( double dt )
{
    // look up and set image ref
    setImage( getString("texture") );

    // reset color
    ofColor color;
    color.set(col.x, col.y, col.z, alpha);
    // UPDATE TODO: in OF 0.9.0, this can be updated to setColorForIndices()
    for( int i = 0; i < 4; i++ )
    {
        m_mesh.setColor(i, color);
    }
}




//------------------------------------------------------------------------------
// name: render()
// desc: render the flare
//------------------------------------------------------------------------------
void VRFlare::render()
{
    // check
    if( !m_imageRef ) return;

    // disable depth
    ofDisableDepthTest();
    // blending
    ofEnableBlendMode( m_blendMode );
    
    // bind texture and draw
    m_imageRef->getTextureReference().bind();
    m_mesh.draw();
    m_imageRef->getTextureReference().unbind();

    // blending
    ofEnableBlendMode( OF_BLENDMODE_ALPHA );
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