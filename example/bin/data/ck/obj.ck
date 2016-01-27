// make a some points
VR.makeEntity("mesh-1","mesh") @=> VREntity mesh;

// load obj
mesh.eval( "load model/suzanne.obj" );
// draw points
mesh.eval( "draw triangles" );

// add to world
VR.root().addChild( mesh );

// disable lights
VR.allLightsOn();

mesh.sca.setAll(4);

// loop
while( true )
{
    // rotate
    1 +=> mesh.ori.y;
    // synch with display
    VR.displaySync() => now;
}
