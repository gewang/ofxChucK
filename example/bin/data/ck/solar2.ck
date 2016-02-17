// sound
TriOsc synthS => NRev rL => dac.left;
// sound
TriOsc synthE => NRev rR => dac.right;
.2 => rL.mix;
.2 => rR.mix;

69 => Math.mtof => synthS.freq;
73 => Math.mtof => synthE.freq;

// make sun
VR.makeEntity("sun","dot") @=> VREntity sun;
// color
sun.rgba.set(1,1,.25,1);
// scale sun
sun.sca.setAll(2);

// make earth
VR.makeEntity("earth","dot") @=> VREntity earth;
// color
earth.rgba.set(.25,1,1,1);
// scale
earth.sca.setAll(.3);
// offset the earth
4 => earth.loc.x;

// make
VR.makeEntity("moon","dot") @=> VREntity moon;
// color
moon.rgba.set(.5,.5,.5,1);
// scale
moon.sca.setAll(.5);
// offset
3 => moon.loc.x;

// add sun to root, so it can be drawn
VR.root().addChild( sun );
// add earth as child of sun
sun.addChild( earth );
// add earth as child of sun
earth.addChild( moon );

// infinite time loop
while( true )
{
    // rotate teh sun (and its children)
    1 +=> sun.ori.z;
    // rotate teh sun (and its children)
    2.5 +=> earth.ori.y;
    
    // map to sound
    (Math.sin( sun.ori.z / 360 * 2 *pi ) + 1 )/2 => synthS.gain;
    (Math.sin( earth.ori.y / 360 * 2 *pi ) + 1 )/2 => synthE.gain;
    
    // when there is a new graphics draw
    VR.displaySync() => now;
}