// make a some points
VR.makeEntity("mesh-1","mesh") @=> VREntity mesh;

// init
repeat( 200 )
{
    vec3 v1;
    Math.random2f(-5,5) => v1.x;
    Math.random2f(-5,5) => v1.y;
    Math.random2f(-5,5) => v1.z;
    mesh.eval( "vertex", v1 );

    Math.random2f(.8,1) => v1.x;
    Math.random2f(.8,1) => v1.y;
    Math.random2f(.8,1) => v1.z;
    mesh.eval( "color", v1 );
}

// draw points
mesh.eval( "generate sphere 3 20" );

// add to world
VR.root().addChild( mesh );

// disable lights
VR.allLightsOn();

3 => mesh.loc.z;


// patch
adc => Gain g => OnePole p => blackhole;
// square the input
adc => g;
// multiply
3 => g.op;

// set pole position
0.99 => p.pole;

fun void rotate()
{
    while( true )
    {
        1 +=> mesh.ori.y;
        VR.displaySync() => now;
    }
}

spork ~ rotate();

// loop on
while( true )
{
    if( p.last() > 0.1 )
    {
        // draw as wireframe
        mesh.eval( "mode wireframe" );
        200::ms => now;
    }
    else
    {
        mesh.eval( "mode fill" );
    }

    // synch with display
    VR.displaySync() => now;
}
