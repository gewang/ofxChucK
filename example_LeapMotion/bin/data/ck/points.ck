// make a some lines
VR.makeEntity("points-1","points") @=> VREntity points;

// init
repeat( 2000 )
{
    vec3 v1;
    
    Math.random2f(-5,5) => v1.x;
    Math.random2f(-5,5) => v1.y;
    Math.random2f(-5,5) => v1.z;

    // points.eval( "add x1 y1 z1 x2 y2 z2" );
    points.eval( "add", v1 );
}

// add to world
VR.root().addChild( points );

// disable lights
VR.allLightsOff();

// rotate
float lr;

while( true )
{
    // rotate
    1 +=> lr => points.ori.y;
    // synch with display
    VR.displaySync() => now;
}
