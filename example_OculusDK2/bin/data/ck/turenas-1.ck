
// keyboard
Hid kb;
// hid message
HidMsg msg;

// open
if( !kb.openKeyboard(0) ) me.exit();
<<< "KB open:", kb.name() >>>;
spork ~ kbf();

// patch
SndBuf L => dac.left;
SndBuf R => dac.right;

// envelope followers
L => OnePole envL => blackhole; L => envL; 3 => envL.op;
R => OnePole envR => blackhole; R => envR; 3 => envR.op;
.9995 => envL.pole => envR.pole;

// load
me.dir() + "../audio/turenas-L.aiff" => L.read;
me.dir() + "../audio/turenas-R.aiff" => R.read;
L.samples() => L.pos;
R.samples() => R.pos;
0 => L.gain => R.gain;

-100 => float FRONT;
FRONT * .5 => float FRONT_FENCE;
100 => float BACK;
BACK * .5 => float BACK_FENCE;

// entities
VREntity es[0];
vec3 v;
polar p;
complex c;
fun void makeOne()
{
    // make a some points
    VR.makeEntity("one"+es.size(),"mesh") @=> VREntity mesh;
    // make
    mesh.eval( "vertex -1 -1 0" );
    //mesh.eval( "color 1 1 1" );
    mesh.eval( "normal 0 0 1" );
    mesh.eval( "vertex 1 -1 0" );
    //mesh.eval( "color 1 1 1" );
    mesh.eval( "normal 0 0 1" );
    mesh.eval( "vertex -1 1 0" );
    //mesh.eval( "color 1 1 1" );
    mesh.eval( "normal 0 0 1" );
    mesh.eval( "vertex 1 1 0" );
    //mesh.eval( "color 1 1 1" );
    mesh.eval( "normal 0 0 1" );
    // draw as triangle
    mesh.eval( "draw trianglestrip" );
    // add to world
    VR.root().addChild( mesh );
    // loc
    Math.random2f(5,100) => p.mag;
    Math.random2f(-pi,pi) => p.phase;
    p$complex => c;
    c.re => mesh.loc.x;
    c.im => mesh.loc.z;
    Math.random2f(FRONT,FRONT_FENCE) => mesh.loc.y;
    
    Math.random2f(.1,1) => mesh.rgba.r;
    Math.random2f(.1,1) => mesh.rgba.g;
    Math.random2f(.1,1) => mesh.rgba.b;
    Math.random2f(0,0) => mesh.rgba.a;
    Math.random2f(0,360) => mesh.ori.y;

    // add
    es << mesh;
}

VREntity @ es2[0];
float es2t[0];

fun void makeTwo()
{
    // make a some points
    VR.makeEntity("two"+es.size(),"flare") @=> VREntity f;
    // set the texture
    f.setString( "texture", "texture:flare-1");
    // loc
    Math.random2f(5,100) => p.mag;
    Math.random2f(-pi,pi) => p.phase;
    p$complex => c;
    c.re => f.loc.x;
    c.im => f.loc.y;
    f.sca.setAll(10);
    Math.random2f(FRONT,FRONT_FENCE) => f.loc.z;
    
    Math.random2f(1,1) => f.rgba.r;
    Math.random2f(1,1) => f.rgba.g;
    Math.random2f(1,1) => f.rgba.b;
    Math.random2f(0,0) => f.rgba.a;
    
    // add
    es2 << f;
    es2t << Math.random2f(0,2*pi);

    // add to world
    VR.root().addChild( f );
}

VREntity @ es3[0];
float es3t[0];

-500 => float FRONT3;
FRONT3 * .5 => float FRONT_FENCE3;
300 => float BACK3;
BACK3 * .5 => float BACK_FENCE3;

fun void makeThree( float inner, float outer, float whereY, float varyY )
{
    // make a some points
    VR.makeEntity("three"+es.size(),"mesh") @=> VREntity f;
    // set the texture
    f.setString( "texture", "texture:flare-1");
    
    f.eval( "draw points" );
    repeat(4000)
    {
        // loc
        Math.random2f(inner,outer) => p.mag;
        Math.random2f(-pi,pi) => p.phase;
        p$complex => c;
        c.re => v.x;
        Math.random2f(-1,1) => v.y;
        c.im => v.z;
        f.eval( "vertex", v );
    }
    
    0 => f.loc.x;
    0 => f.loc.z;
    Math.random2f(whereY,whereY*varyY) => f.loc.y;
    
    Math.random2f(1,1) => f.rgba.r;
    Math.random2f(1,1) => f.rgba.g;
    Math.random2f(1,1) => f.rgba.b;
    Math.random2f(0,0) => f.rgba.a;
    
    // add
    es3 << f;
    es3t << .0000002 / Math.pow((inner+outer)/6.0/outer,10);
    // <<< "spin:", es3t[es3t.size()-1] >>>;

    // add to world
    VR.root().addChild( f );
}


//repeat(4)
//    for(int i; i < 10; i++ )
//        makeThree( 2*(20+i*15), 4*(20+i*15+5), FRONT3*3, .6 );

//repeat(4)
//    for(int i; i < 10; i++ )
//        makeThree( 2*(20+i*15), 4*(20+i*15+5), FRONT3*6, .6 );

//repeat(4)
//    for(int i; i < 10; i++ )
//        makeThree( 2*(20+i*15), 4*(20+i*15+5), FRONT3*12, .6 );


// disable lights
VR.allLightsOn();

// bang detector
fun void bangDetect()
{
    while( true )
    {
        if( envL.last() > 0.0001 )
        {
            <<< "BANG!!", now/second >>>;
            100::ms => now;
        }
        10::ms => now;
    }
}

// detector
// spork ~ bangDetect();
VREntity @ e;

// loop
while( true )
{
    for( int i; i < es.size(); i++ )
    {
        es[i] @=> e;
        if( e.loc.y <= FRONT_FENCE )
            1-Math.fabs((e.loc.y-FRONT_FENCE)/(FRONT-FRONT_FENCE)) => e.rgba.a;
        else if( e.loc.y >= BACK_FENCE )
            1-Math.fabs((e.loc.y-BACK_FENCE)/(BACK-BACK_FENCE)) => e.rgba.a;
        else
            1 => e.rgba.a;
        
        if( e.rgba.a < 0 ) 0 => e.rgba.a;
        else if( e.rgba.a > 1 ) 1 => e.rgba.a;
        
        5 +=> e.ori.y;
        .5 +=> e.loc.y;
        if( e.loc.y > BACK ) FRONT => e.loc.y;
    }
    
    for( int i; i < es2.size(); i++ )
    {
        es2[i] @=> e;
        if( e.loc.z <= FRONT_FENCE )
            1-Math.fabs((e.loc.z-FRONT_FENCE)/(FRONT-FRONT_FENCE)) => e.rgba.a;
        else if( e.loc.z >= BACK_FENCE )
            1-Math.fabs((e.loc.z-BACK_FENCE)/(BACK-BACK_FENCE)) => e.rgba.a;
        else
            1 => e.rgba.a;

        if( e.rgba.a < 0 ) 0 => e.rgba.a;
        else if( e.rgba.a > 1 ) 1 => e.rgba.a;
        
        Math.pow(envL.last(),1)*100 *=> e.rgba.a;

        5 * (1 + .2*Math.sin(es2t[i])) => e.sca.setAll; .1 +=> es2t[i];
        .2 +=> e.loc.z;
        if( e.loc.z > BACK ) FRONT => e.loc.z;
    }
    
    for( int i; i < es3.size(); i++ )
    {
        es3[i] @=> e;
        if( e.loc.y <= FRONT_FENCE3 )
            1-Math.fabs((e.loc.y-FRONT_FENCE3)/(FRONT3-FRONT_FENCE3)) => e.rgba.a;
        else if( e.loc.y >= BACK_FENCE3 )
            1-Math.fabs((e.loc.y-BACK_FENCE3)/(BACK3-BACK_FENCE3)) => e.rgba.a;
        else
            1 => e.rgba.a;
        
        if( e.rgba.a < 0 ) 0 => e.rgba.a;
        else if( e.rgba.a > 1 ) 1 => e.rgba.a;
        
        es3t[i] +=> e.ori.y;
        .5 +=> e.loc.y;
        if( e.loc.y > BACK3 ) FRONT3 => e.loc.y;
    }
    
    // VR.root().rgba.setAll(Math.pow(envL.last(),.75)*500);
    
    // synch with display
    VR.displaySync() => now;
}

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
                repeat(10) makeOne();
            }
            else if( msg.ascii == 50 ) // 2
            {
                repeat(10) makeTwo();
            }
            else if( msg.ascii == 51 ) // 3
            {
                for(int i; i < 10; i++ )
                    makeThree( 2*(20+i*15), 4*(20+i*15+5), FRONT3*2.5, .75 );
            }
        }
    }
}
