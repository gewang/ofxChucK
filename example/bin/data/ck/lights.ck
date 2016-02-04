// construct some lights
VR.makeEntity("light1", "light") @=> VREntity light1;
VR.makeEntity("light2", "light") @=> VREntity light2;
VR.makeEntity("light3", "light") @=> VREntity light3;

// set their textures
light1.eval( "texture texture:flare-1" );
light2.eval( "texture texture:flare-3" );
light3.eval( "texture texture:flare-4" );

// space them apart
-3 => light1.loc.x;
3 => light3.loc.x;

// make them unique
// tall rotating red one
light1.eval( "rotate 0.2" );
light1.eval( "num 10" );
light1.rgba.set(1,0,0,1);
10 => light1.sca.y;

// top down orange one
light2.eval( "rotate 0.8" );
light2.eval( "num 4" );
light2.rgba.set(1,0.5,0,1);
90 => light2.ori.x;

// side yellow squash
light3.eval( "rotate 2" );
light3.eval( "num 6" );
light3.rgba.set(1,0.8,0,1);
90 => light3.ori.z;
5 => light3.sca.y;
2 +=> light3.loc.x;

// add to scene
VR.root().addChild( light1 );
VR.root().addChild( light2 );
VR.root().addChild( light3 );


// disable lights
VR.allLightsOff();

// loop
while( true )
{
    // do nothing because lights are incredible
    
    // synch with display
    VR.displaySync() => now;
}
