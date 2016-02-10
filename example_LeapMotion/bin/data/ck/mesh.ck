// make a some points
VR.makeEntity("mesh-1","mesh") @=> VREntity mesh;

// init
repeat( 100000 )
{
    vec3 v1;
    
    Math.random2f(-5,5) => v1.x;
    Math.random2f(-5,5) => v1.y;
    Math.random2f(-5,5) => v1.z;

    // add vertex    
    mesh.eval( "vertex", v1 );
    mesh.eval( "color 1 1 1" );
}
// draw points
mesh.eval( "draw points" );

// add to world
VR.root().addChild( mesh );

// disable lights
VR.allLightsOff();

// loop
while( true )
{
    // rotate
    1 +=> mesh.ori.y;
    // synch with display
    VR.displaySync() => now;
}
