// control LFO's (no sound)
SinOsc a => blackhole;
SinOsc b => blackhole;

// frequencies
1.1 => a.freq;
1.13 => b.freq;

// FM synthesis
SinOsc c => SinOsc d => dac;
2 => d.sync;

// time loop
while( true )
{
    // send data to graphics
    VR.setFloat( "color-x", (a.last()+1)/2*620 );
    VR.setFloat( "color-y", (b.last()+1)/2*620 );
    
    // get values from graphics
    VR.getFloat( "mouse-x" ) => d.freq;
    d.freq() * 2 => c.freq;
    VR.getFloat( "mouse-y" ) => c.gain;

    // when there is a new graphics draw
    VR.displaySync() => now;
}
