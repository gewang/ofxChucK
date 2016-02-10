SinOsc foo => dac;

while( true )
{
    400 + VR.leap().loc.y/2 => foo.freq;
    VR.displaySync() => now;
}