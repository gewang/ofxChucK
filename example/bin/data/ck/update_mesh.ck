// do it twice
for( int i; i < 2; i++) {
    // empty mesh
    VR.makeEntity("mesh"+i,"mesh") @=> VREntity mesh;
    
    // form a rectangle with midpoints
    
    // bottom is red
    mesh.eval( "vertex 0 0 0" );
    mesh.eval( "uv 0 0" );
    mesh.eval( "color 1 0 0" );
    
    mesh.eval( "vertex 1 0 0" );
    mesh.eval( "uv 1 0" );
    mesh.eval( "color 1 0 0" );
    
    // midpoints are orange
    mesh.eval( "vertex 0 0.5 0" );
    mesh.eval( "uv 0 0.5" );
    mesh.eval( "color 1 0.5 0" );
    
    mesh.eval( "vertex 1 0.5 0" );
    mesh.eval( "uv 1 0.5" );
    mesh.eval( "color 1 0.5 0" );
    
    // top is yellow
    mesh.eval( "vertex 0 1 0" );
    mesh.eval( "uv 0 1" );
    mesh.eval( "color 1 0.8 0" );
    
    mesh.eval( "vertex 1 1 0" );
    mesh.eval( "uv 1 1" );
    mesh.eval( "color 1 0.8 0" );
    
    // draw as a trianglestrip
    mesh.eval( "draw trianglestrip" );
    
    // make it taller
    mesh.sca.set( 1, 10, 1 );
    -5 => mesh.loc.y;
    
    // add to world
    VR.root().addChild( mesh );
}

VR.getEntity( "mesh0" ) @=> VREntity mesh1;
VR.getEntity( "mesh1" ) @=> VREntity mesh2;

// texture the left mesh
mesh1.eval( "texture texture:flare-1" );

// space them apart
-2 => mesh1.loc.x;
1 => mesh2.loc.x; 

// oscillator for the midpoints
SinOsc wiggler => blackhole;
2 => wiggler.freq;
0.15 => wiggler.gain;

// disable lights
VR.allLightsOff();

// loop
while( true )
{
    // wiggle
    wiggler.last() => float wiggleAmount;
    
    // compute new midpoints
    vec3 left;
    vec3 right;
    0 + wiggleAmount => left.x;
    1 + wiggleAmount => right.x;
    // const values
    0.5 => left.y => right.y;
    0 => left.z => right.z;
    
    // go for it, 4 different ways
    mesh1.eval( "update vertex 2", left );
    mesh1.eval( "update vertex 3 ", right );
    mesh2.eval( "update vertex 2 " + left.x + " 0.5 0" );
    mesh2.eval( "update vertex 3 " + 
        right.x + " " + right.y + " " + right.z );
    
    // go for it again (make it pinkish!)
    mesh2.eval( "update color 0 1 0 " + Std.rand2f(0, 1) );
    mesh2.eval( "update color 1 1 0 " + Std.rand2f(0, 1) );
    
    // go for it again (make it transparent!)
    mesh2.eval( "update color 4 1 0.8 0 " + Std.rand2f(0, 1) );
    mesh2.eval( "update color 5 1 0.8 0 " + Std.rand2f(0, 1) );
    
    // go for it one more time
    // (notice how texture coordinates can go "outside the image")
    mesh1.eval( "update uv 4 0 " + Std.rand2f(1, 1.1) );
    mesh1.eval( "update uv 5 1 " + Std.rand2f(1, 1.1) );
    
    // synch with display
    VR.displaySync() => now;
}
