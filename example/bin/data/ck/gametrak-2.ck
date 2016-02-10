class Monkey
{
    // sound
    SndBuf buffy => dac;
    // load
    me.dir() + "../audio/wee.wav" => buffy.read;
    // to back
    buffy.samples() => buffy.pos;
    
    // mesh + shadow
    VR.makeEntity("mesh-1","mesh") @=> VREntity head;
    VR.makeEntity("shadow-1","flare") @=> VREntity shadow;
    
    // load obj
    head.eval( "load model/suzanne.obj" );
    // draw points
    head.eval( "draw triangles" );
    // shadow texture
    shadow.eval( "texture texture:flare-4" );
    // shadows
    90 => shadow.ori.x;
    @(.5,.5,.5,.5) => shadow.rgba;
    
    // monkey location
    0 => head.loc.y;
    // scale
    2 => head.sca.setAll;
    
    // add to world
    VR.root().addChild( head );
    VR.root().addChild( shadow );
    
    // collision detection
    fun int collide( vec3 center, float radius )
    {
        // monkey radius
        head.sca.magnitude() => float r;
        // get diff
        center - head.loc => vec3 diff;
        // get length
        diff.magnitude() => float L;
        // check
        return (r + radius) > L;
    }
}

// make a monkey
Monkey m[3];
// colors
vec4 colors[3];
// hands state
int collideL[3];
int collideR[3];

// 1
-7 => m[0].head.loc.x;
.75 => m[0].buffy.rate;
@(1,0,0,1) => m[0].head.rgba => colors[0];
// 2
@(0,1,0,1) => m[1].head.rgba => colors[1];
// 3
7 => m[2].head.loc.x;
1.25 => m[2].buffy.rate;
@(0,0,1,1) => m[2].head.rgba => colors[2];

// disable lights
VR.allLightsOn();

// left hand location
vec3 handL;
vec3 handR;
// ground level
float GROUND_LEVEL;

// main loop
while( true )
{
    // get data
    VR.getVec3("hand.left") => handL;
    VR.getVec3("hand.right") => handR;
    // get it
    VR.getFloat( "GROUND_LEVEL" ) => GROUND_LEVEL;

    // loop
    for( int i; i < m.size(); i++ )
    {
        // shadow
        m[i].head.loc => m[i].shadow.loc;
        GROUND_LEVEL => m[i].shadow.loc.y;
        4 => m[i].shadow.sca.setAll;
            
        // check collision
        m[i].collide( handL, -.5 ) => int cL;
        m[i].collide( handR, -.5 ) => int cR;
        
        // check state
        if( !collideL[i] && !collideR[i] && (cL || cR) )
        {
            // play
            0 => m[i].buffy.pos;
            // set gain
            1 => m[i].buffy.gain;
        }
        
        // set it
        cL => collideL[i];
        cR => collideR[i];
        
        // color
        if( collideL[i] || collideR[i] ) @(1,1,1,1) => m[i].head.rgba;
        else colors[i] => m[i].head.rgba;
    }
    
    // synchronize to display
    VR.displaySync() => now;
}
