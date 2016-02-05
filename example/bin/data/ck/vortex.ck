// number of elements
12 => int NUM_COLUMNS;
// # of layers of each column
8 => int NUM_LAYERS;
// radius
2 => float RADIUS;

// array
VREntity lights[0];
// parent
VR.makeEntity("vortex", "node" ) @=> VREntity vortex;

%(RADIUS, 0) => polar p;

// for each
for( int i; i < NUM_COLUMNS; i++ )
{
    // construct some lights
    VR.makeEntity("column"+i, "light") @=> VREntity e;
    // set their textures
    e.eval( "texture texture:flare-4" );

    // tall rotating red one
    e.eval( "rotate .5" );
    e.eval( "num " + NUM_LAYERS );
    50 => e.sca.y;
    2 => e.sca.x;
    
    // degree
    2*pi / NUM_COLUMNS * i => p.phase;
    // rectangular
    p$complex => complex c;
    e.loc.set( c.re, 0, c.im );
    
    // add
    vortex.addChild( e );
    lights << e;
}

// set color
lights[0].rgba.set(1,.5,0,1);
lights[1].rgba.set(1,.3,0,1);
lights[2].rgba.set(1,0,0,1);
lights[3].rgba.set(1,0,.5,1);
lights[4].rgba.set(1,0,1,1);
lights[5].rgba.set(.5,0,1,1);
lights[6].rgba.set(0,0,1,1);
lights[7].rgba.set(0,1,.5,1);
lights[8].rgba.set(0,1,0,1);
lights[9].rgba.set(.5,1,0,1);
lights[10].rgba.set(1,1,0,1);
lights[11].rgba.set(1,.7,0,1);

for( int i; i < NUM_COLUMNS; i++ )
{
    .3 => lights[i].rgba.a;
}

// add to scene
VR.root().addChild( vortex );

// disable lights
VR.allLightsOff();

// move it closer
8 => vortex.loc.z;
// rotate
90 => vortex.ori.x;

// loop
while( true )
{
    // rotate it
    .5 +=> vortex.ori.y;
    
    // synch with display
    VR.displaySync() => now;
}
