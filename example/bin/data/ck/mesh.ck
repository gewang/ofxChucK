// make a some points
VR.makeEntity("mesh-1","mesh") @=> VREntity mesh;
// make a sphere
VR.makeEntity("mesh-2","mesh") @=> VREntity sphere;

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

// init
sphere.eval( "generate sphere 2 12" );

// add to world
VR.root().addChild( mesh );
VR.root().addChild( sphere );

// disable lights
VR.allLightsOn();

// loop
while( true )
{
    // rotate
    1 +=> mesh.ori.y;
    // synch with display
    VR.displaySync() => now;
}
