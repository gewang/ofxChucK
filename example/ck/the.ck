SinOsc a => blackhole;
SinOsc b => blackhole;

1.1 => a.freq;
1.13 => b.freq;

SinOsc c => SinOsc d => dac;
2 => d.sync;

while( true )
{
    VR.setFloat( "color-x", (a.last()+1)/2*620 );
    VR.setFloat( "color-y", (b.last()+1)/2*620 );
    
    VR.getFloat( "mouse-x" ) => d.freq;
    d.freq() * 2 => c.freq;
    VR.getFloat( "mouse-y" ) => c.gain;

    // when there is a new graphics draw
    VR.displaySync() => now;
}
