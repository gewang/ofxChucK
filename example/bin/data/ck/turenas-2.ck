// keyboard number
2 => int KB_NUM;
// light pool fade factor
.95 => float FADE_FACTOR;
// toggle
0 => int LIGHT_ONOFF;
0 => int TRAIL_ONOFF;
0 => int POOL_ONOFF;

// keyboard
Hid kb;
// hid message
HidMsg msg;

// open
if( !kb.openKeyboard(KB_NUM) ) me.exit();
<<< "KB open:", kb.name() >>>;
spork ~ kbf();

// patch
SndBuf L => dac.left;
SndBuf R => dac.right;

// envelope followers
L => OnePole envL => blackhole; L => envL; 3 => envL.op;
R => OnePole envR => blackhole; R => envR; 3 => envR.op;
.99 => envL.pole => envR.pole;

// load
me.dir() + "../audio/turenas-L.aiff" => L.read;
me.dir() + "../audio/turenas-R.aiff" => R.read;
L.samples() => L.pos;
R.samples() => R.pos;
0 => L.gain => R.gain;

SinOsc x => blackhole;
SinOsc y => blackhole;

1 => x.freq;
1.5 => y.freq;

// light pool
VREntity pool[0];
// pool index
0 => int poolIndex;
// number in pool
50 => int POOL_SIZE;
// go
for( int i; i < POOL_SIZE; i++ )
{
    // construct some lights
    VR.makeEntity("pool"+i, "light") @=> VREntity e;
    // set texture
    e.eval( "texture texture:flare-1" );
    e.eval( "rotate 2" );
    e.eval( "num 3" );
    // make transparent
    0 => e.rgba.a;
    // append
    pool << e;
    // add
    VR.root().addChild( e );
}

// construct some lights
VR.makeEntity("light1", "light") @=> VREntity light;
// trail (should to same root as the entity it's trailing)
VR.makeEntity("trail1", "trail") @=> VREntity trail;

-2 => light.loc.y;

// set texture
light.eval( "texture texture:flare-1" );
// set trail length
trail.eval( "length 200" );
trail.eval( "draw linestrip" );

// tall rotating red one
light.eval( "rotate 1" );
light.eval( "num 5" );
light.rgba.set(.25,1,.25,LIGHT_ONOFF*1);
1 => light.sca.setAll;

// color
trail.rgba.set(.25,1,.25,TRAIL_ONOFF*.5);

// add to scene
VR.root().addChild( light );
VR.root().addChild( trail );

// disable lights
VR.allLightsOff();

fun void kbf()
{
    while( true )
    {
        // wait
        kb => now;
        // wait
        while( kb.recv(msg) )
        {
            if( !msg.isButtonDown() )
                continue;
            
            if( msg.ascii == 48 ) // 1
            {
                0 => L.pos => R.pos;
                1 => L.gain => R.gain;
            }
            // <<< "kb:", msg.ascii >>>;
            if( msg.ascii == 49 ) // 1
            {
                !LIGHT_ONOFF => LIGHT_ONOFF;
                LIGHT_ONOFF * 1 => light.rgba.a;
            }
            else if( msg.ascii == 50 ) // 2
            {
                !TRAIL_ONOFF => TRAIL_ONOFF;
                TRAIL_ONOFF * .5 => trail.rgba.a;
            }
            else if( msg.ascii == 51 ) // 3
            {
                !POOL_ONOFF => POOL_ONOFF;
            }
        }
    }
}

// bang detector
fun void bangDetect()
{
    while( true )
    {
        if( envL.last() > 0.000001 )
        {
            // add vertex
            // trail.eval( "add", light.loc );
            // check
            if( POOL_ONOFF )
            {
                light.loc => pool[poolIndex].loc;
                light.rgba => pool[poolIndex].rgba;
                1 => pool[poolIndex].rgba.a;
                .5 => pool[poolIndex].sca.setAll;
                poolIndex++; POOL_SIZE %=> poolIndex;
            }
            <<< "BANG!!", poolIndex, now/second >>>;
            30::ms => now;
        }
        5::ms => now;
    }
}

// keyboard function
spork ~ kbf();
// detector
spork ~ bangDetect();

// loop
while( true )
{
    6 * x.last() => light.loc.x;
    6 * y.last() => light.loc.y;
    // add vertex
    trail.eval( "add", light.loc );
    
    // update light pool
    updatePool();
    
    // synch with display
    VR.displaySync() => now;
}

// update light pool
fun void updatePool()
{
    for( int i; i < POOL_SIZE; i++ )
    {
        FADE_FACTOR *=> pool[i].rgba.a;
    }
}