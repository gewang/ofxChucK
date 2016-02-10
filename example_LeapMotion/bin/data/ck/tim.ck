// Tim's ck playground

SinOsc foo => dac;
SinOsc fm => foo;
foo.sync(2);
3 => fm.freq;
100 => fm.gain;

while( true )
{
    400 + (VR.head().ori.y + 90) * 4 => foo.freq;
    VR.head().ori.x * 4 => fm.freq;
    //(VR.head().ori.z + 180)/360 => fm.gain;
    VR.displaySync() => now;
}I