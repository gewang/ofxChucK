// construct some lights
VR.makeEntity("light1", "light") @=> VREntity light;

// set their textures
light.eval( "texture texture:flare-3" );

// tall rotating red one
light.eval( "rotate 1" );
light.eval( "num 5" );
light.rgba.set(1,1,0,.5);
10 => light.sca.setAll;

// add to scene
VR.root().addChild( light );

// disable lights
VR.allLightsOff();

// loop
while( true )
{
    // do nothing because lights are incredible
    
    // synch with display
    VR.displaySync() => now;
}
