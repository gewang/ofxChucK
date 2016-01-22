// Adapted from http://chuck.cs.princeton.edu/doc/examples/analysis/fft3.ck

// our patch
adc => FFT fft => blackhole;

// set parameters
1024 => fft.size;
// use this to hold contents
complex s[fft.size()/2];

// FLAG: Vary number of particles displayed here
fft.size()/2 => int numParticles;
// spacing
20.0 / numParticles => float spacePerParticle;

// initialize
for(0 => int i; i < numParticles; i++)
{
    VR.makeEntity("p" + i, "dot") @=> VREntity p;
    p.rgba.set(1,1,1,1);
    p.sca.setAll(0.1);
    spacePerParticle * i - 10.0 => p.loc.x;
    VR.root().addChild(p);
}

// control loop
while( true )
{   
    // take fft
    fft.upchuck();
    // get contents
    fft.spectrum( s );
    // push to openframeworks
    for(0 => int i; i < numParticles;  i++)
    {
        VR.getEntity("p" + i) @=> VREntity p;
        (s[i]$polar).mag * 50 => p.loc.y;
    }
    
    // advance time
    VR.displaySync() => now;
}