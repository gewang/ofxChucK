class Monkey
{
    // sound
    SndBuf buffy => dac;
    // load
    "special:dope" => buffy.read;
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
    1.5 => head.sca.setAll;
    
    // add to world
    VR.root().addChild( head );
    VR.root().addChild( shadow );
    
    // collide state
    0 => int isColliding;
    
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
        (r + radius) > L => int colliding;
        // check current state
        if( colliding && !isColliding )
        {
            true => isColliding;
            return true;
        }
        
        // set state
        colliding => isColliding;
        // return false
        return false;
    }
}

// make a monkey
new Monkey @=> Monkey m;

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
    
    // shadow
    m.head.loc => m.shadow.loc;
    GROUND_LEVEL => m.shadow.loc.y;
    4 => m.shadow.sca.setAll;
    
    // check collision
    if( m.collide( handR, -.5 ) )
    {
        // play
        0 => m.buffy.pos;
        // set gain
        1 => m.buffy.gain;
    }
    
    // color
    if( m.isColliding ) @(1,.25,1,1) => m.head.rgba;
    else @(1,1,1,1) => m.head.rgba;
    
    // synchronize to display
    VR.displaySync() => now;
}
