SinOsc x => blackhole;
SinOsc y => blackhole;

1 => x.freq;
1.5 => y.freq;

// construct some lights
VR.makeEntity("light1", "light") @=> VREntity light;
// trail (should to same root as the entity it's trailing)
VR.makeEntity("trail1", "trail") @=> VREntity trail;

-2 => light.loc.y;

// set texture
light.eval( "texture texture:flare-1" );
// set trail length
trail.eval( "length 200" );
trail.eval( "draw linestrip" );

// tall rotating red one
light.eval( "rotate 1" );
light.eval( "num 5" );
light.rgba.set(.25,1,.25,.5);
1 => light.sca.setAll;

// color
trail.rgba.set(.25,1,.25,.5);
.5 => trail.rgba.a;

// add to scene
VR.root().addChild( light );
VR.root().addChild( trail );

// disable lights
VR.allLightsOff();

// loop
while( true )
{
    6 * x.last() => light.loc.x;
    6 * y.last() => light.loc.y;
    // add vertex
    trail.eval( "add", light.loc );
    
    // synch with display
    VR.displaySync() => now;
}
