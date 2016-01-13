// ensure load of texture
// VR.loadImage("texture:flare-1", "flare-tng-1.png");

// get root
VR.root() @=> VREntity root;

for( int i; i < 100; i ++ )
{
  // make entity
  VR.makeEntity("f-"+i, "flare" ) @=> VREntity f;
  // set the texture
  f.setString( "texture", "texture:flare-1");
  // set color
  Math.random2f(0,1) => f.rgba.r;
  Math.random2f(0,1) => f.rgba.g;
  Math.random2f(0,1) => f.rgba.b;
  1 => f.rgba.a;
  // set scale
  f.sca.setAll(Math.random2f(.5,2));
  // random location
  Math.random2f(-5,5) => f.loc.x;
  Math.random2f(-5,5) => f.loc.y;
  Math.random2f(-5,5) => f.loc.z;
  
  // add to scene
  root.addChild( f );
}

// use microphone input
adc => FullRect r => OnePole lowpass => blackhole;
// set lowpass filter pole
.99 => lowpass.pole;

// infinite time loop
while( true )
{
    // get multiplier
    lowpass.last()*4 => float v;
    for( int i; i < 100; i ++ )
    {
        // make entity
        VR.getEntity("f-"+i ) @=> VREntity f;
        // set color
        Math.random2f(0,v) => f.rgba.r;
        Math.random2f(0,v) => f.rgba.g;
        Math.random2f(0,v) => f.rgba.b;
    }
    
    // advance time until next graphics draw
    VR.displaySync() => now;
}
