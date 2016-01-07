// ensure load of texture
// VR.loadImage("texture:flare-1", "flare-tng-1.png");

// make entity
VR.makeEntity("f1", "flare" ) @=> VREntity f;
// set the texture
f.setString("texture", "texture:flare-1");
// set color
f.rgba.set(1,1,0,1);
// set scale
f.sca.setAll(10);

// infinite time loop
while( true )
{
    // when there is a new graphics draw
    VR.displaySync() => now;
}
