
for(int i; i < 100; i++)
{
    // make
    VR.makeEntity("text"+i, "text") @=> VREntity text;
    // load
    text.eval( "load", "font/Computerfont.ttf 64" );
    // set it
    text.eval( "set", "Hello." );
    // color
    text.rgba.set(.25,1,.25,1);
    // position
    Math.random2f(-5,5) => text.loc.x;
    Math.random2f(-5,5) => text.loc.y;
    Math.random2f(-16,8) => text.loc.z;
    // scale
    text.sca.setAll(.5);
    // add
    VR.root().addChild( text );
}

// disable lights
VR.allLightsOff();

// loop
while( true )
{
    // iterate
    for( int i; i < 100; i++ )
    {
        // rotate
        1 +=> VR.getEntity("text"+i).ori.y;
    }
    // sync
    VR.displaySync() => now;
}