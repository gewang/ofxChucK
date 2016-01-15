
// make a some lines
VR.makeEntity("lines-1","lines") @=> VREntity lines;

// init
repeat( 2000 )
{
    // lines.eval( "add 0 0 0 1 1 0" );
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
    lines.eval( "add", v1, v2 );
}

// add to world
VR.root().addChild( lines );

// disable lights
VR.allLightsOff();

// rotate
float lr;

while( true )
{
    // rotate
    1 +=> lr => lines.ori.y;
    // synch with display
    VR.displaySync() => now;
}