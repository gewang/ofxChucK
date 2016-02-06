SinOsc s => Gain g =>BPanner bp;
//SndBuf snd => Gain g => BPanner bp;
//me.sourceDir() + "3d/mozart.wav" => snd.read;
500 => g.gain;


270 => float myAzim;
40 => float myElev;


while(true){
        
    // map y axis of head from -180-180 to 0-360
    ((VR.head().ori.y+ 360 + myAzim) $ int) % 360 => float currAzim;
    // x axis of head
    -VR.head().ori.x + myElev => float currElev;
    bp.setPos(currElev,currAzim);
    10::ms => now;
    VR.displaySync() => now;
}