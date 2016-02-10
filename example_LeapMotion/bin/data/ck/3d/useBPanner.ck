SinOsc s => Gain g =>BPanner bp;
// SndBuf snd => Gain g => BPanner bp;
//me.sourceDir() + "myaudio.wav" => snd.read;
500 => g.gain;

// 270: Left, 180: Front, 90: Right, 0: Rear
bp.setPos(0,270);
3::second => now;

bp.setPos(0,180);
3::second => now;

bp.setPos(0,90);
3::second => now;

bp.setPos(0,0);
3::second => now;

0.0 => float t;
-40 => float currA;



while(true){
//while(snd.pos() < snd.samples()) {
    0.012 +=> t;
    // the two values represent the x and y coordinates to which we pan
    bp.setPos(currA, (Math.sin(t)+1)*180);
    10::ms => now;
    
    if (currA < 0) { 
        0.1 +=> currA;
    }
    if (currA > 100){
        0.1 -=> currA;
    }    
}



