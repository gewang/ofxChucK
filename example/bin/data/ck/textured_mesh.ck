// empty mesh
VR.makeEntity("mesh-1","mesh") @=> VREntity mesh;

// form a part of a cube with tex coords
mesh.eval( "vertex 1 1 1" );
mesh.eval( "uv 0 0" );
mesh.eval( "color 1 1 1" );

mesh.eval( "vertex 1 -1 1" );
mesh.eval( "uv 0 1" );
mesh.eval( "color 1 1 1" );

mesh.eval( "vertex -1 1 1" );
mesh.eval( "uv 1 0" );
mesh.eval( "color 1 1 1" );

mesh.eval( "vertex -1 -1 1" );
mesh.eval( "uv 1 1" );
mesh.eval( "color 1 1 1" );

mesh.eval( "vertex -1 -1 -1" );
mesh.eval( "uv 0 1" );
mesh.eval( "color 1 1 0" );

mesh.eval( "vertex 1 -1 -1" );
mesh.eval( "uv 1 0" );
mesh.eval( "color 1 0 0" );

mesh.eval( "vertex -1 1 -1" );
mesh.eval( "uv 0 0" );
mesh.eval( "color 0 1 0" );

mesh.eval( "vertex 1 1 -1" );
mesh.eval( "uv 0 1" );
mesh.eval( "color 0 0 1" );

mesh.eval( "texture texture:flare-1" );

// draw as a trianglestrip
mesh.eval( "draw trianglestrip" );

mesh.sca.set( 3, 3, 3 );

// add to world
VR.root().addChild( mesh );

// disable lights
VR.allLightsOff();

// loop
while( true )
{
    // rotate
    1 +=> mesh.ori.y;
    0.1 +=> mesh.ori.x;
    // synch with display
    VR.displaySync() => now;
}
