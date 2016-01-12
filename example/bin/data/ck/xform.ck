// make sun, earth
VR.makeEntity("sun","dot");
VR.makeEntity("earth","dot");

// get entities
VR.getEntity("root") @=> VREntity root;
VR.getEntity("sun") @=> VREntity sun;
VR.getEntity("earth") @=> VREntity earth;
// set color
sun.rgba.set(1,1,.5,1);
earth.rgba.set(.25,.5,1,1);
// set scale
sun.sca.setAll(1);
earth.sca.setAll(1);

// add to root
root.addChild(sun);
// add relation
sun.addChild( earth );
// offset earth
5 => earth.loc.x;

// rotation
float r;

// infinite time loop
while( true )
{
    // set sun rotation
    r => sun.ori.z;
    // increment rotation
    .25 +=> r;

    // when there is a new graphics draw
    VR.displaySync() => now;
}
