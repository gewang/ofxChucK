// make sun
VR.makeEntity("sun","dot") @=> VREntity sun;
// location
//sun.loc.set(0,0,5);
// color
sun.rgba.set(1,1,.25,0.5);
// scale sun
sun.sca.setAll(1);

// make earth
VR.makeEntity("earth","dot") @=> VREntity earth;
// color
earth.rgba.set(.25,1,1,1);
// scale
earth.sca.setAll(.5);
// offset the earth
10 => earth.loc.x;


// add sun to root, so it can be drawn
VR.root().addChild( sun );
// add earth as child of sun
sun.addChild( earth );

//SinOsc s => Gain g =>BPanner bp;
SndBuf snd => Gain g => BPanner bp;
me.sourceDir() + "3d/mywave.wav" => snd.read;
500 => g.gain;


270 => float myAzim;
40 => float myElev;


while(true){
    // rotate the sun (and its children)
    1 +=> sun.ori.y;

     
    // map y axis of head from -180-180 to 0-360
    ((VR.head().ori.y+ 360 + sun.ori.y + 90) $ int) % 360 => float currAzim;
    // x axis of head
    -VR.head().ori.x + myElev => float currElev;
    bp.setPos(currElev,currAzim);
    10::ms => now;
    VR.displaySync() => now;
}