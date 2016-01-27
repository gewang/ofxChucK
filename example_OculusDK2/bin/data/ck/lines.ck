// make a some lines
VR.makeEntity("lines-1","lines") @=> VREntity lines;

// init
repeat( 2000 )
{
    vec3 v1;
    vec3 v2;
    
    Math.random2f(-5,5) => v1.x;
    Math.random2f(-5,5) => v1.y;
    Math.random2f(-5,5) => v1.z;
    //v1.normalize();
    Math.random2f(-5,5) => v2.x;
    Math.random2f(-5,5) => v2.y;
    Math.random2f(-5,5) => v2.z;  
    //v2.normalize();
    2 *=> v1;
    2 *=> v2;

    // lines.eval( "add x1 y1 z1 x2 y2 z2" );
    lines.eval( "add", v1, v2 );
}

// add to world
VR.root().addChild( lines );

// disable lights
VR.allLightsOff();

// time loop
while( true )
{
    // rotate
    1 +=> lines.ori.y;
    // synch with display
    VR.displaySync() => now;
}