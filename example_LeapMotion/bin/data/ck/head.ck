SinOsc foo => dac;

while( true )
{
    400 + (VR.head().ori.y + 90) * 4 => foo.freq;
    VR.displaySync() => now;
}