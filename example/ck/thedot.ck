// x LFO
SinOsc x => blackhole;
// y LFO
SinOsc y => blackhole;

// set frequency
1 => x.freq;
// set frequency
1 => y.freq;
// set phase
pi/4 => x.phase;

// get a name 
VR.getEntity("dot") @=> VREntity dot;
// print pointer
<<< "dot:", dot >>>;
// set color
// dot.rgba.setAll(255);
// set scale
// dot.sca.setAll(1);

// potential dot things
// .loc (vec3)
// .ori (vec3)
// .scale (vec3)
// .rgba (vec4)
// .addChild
// .removeChild
// .children (VRObject[])

// infinite time loop
while( true )
{
    // control location of dot
    512 + x.last() * 200 => dot.loc.x;
    384 + y.last() * 200 => dot.loc.y;
    
    // <<< dot.loc >>>;
    // when there is a new graphics draw
    VR.displaySync() => now;
}
