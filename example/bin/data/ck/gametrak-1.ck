// construct some lights
VR.makeEntity("handL", "light") @=> VREntity handL;
VR.makeEntity("trailL", "trail") @=> VREntity trailL;
VR.makeEntity("handR", "light") @=> VREntity handR;
VR.makeEntity("trailR", "trail") @=> VREntity trailR;

// set their textures
handL.eval( "texture texture:flare-1" );
handR.eval( "texture texture:flare-1" );
// set trail length
trailL.eval( "length 100" );
trailL.eval( "draw linestrip" );
trailR.eval( "length 100" );
trailR.eval( "draw linestrip" );

// tall rotating red one
handL.eval( "rotate 1" );
handL.eval( "num 5" );
handL.rgba.set(.25,1,.25,.5);
3 => handL.sca.setAll;
handR.eval( "rotate 1" );
handR.eval( "num 5" );
handR.rgba.set(.25,.25,1,.5);
3 => handR.sca.setAll;
// color
handL.rgba => trailL.rgba;
handR.rgba => trailR.rgba;

// add to scene
VR.root().addChild( handL );
VR.root().addChild( trailL );
VR.root().addChild( handR );
VR.root().addChild( trailR );

// z axis deadzone
.032 => float DEADZONE;

// which joystick
0 => int device;
// get from command line
if( me.args() ) me.arg(0) => Std.atoi => device;

// data structure for gametrak
class GameTrak
{
    // timestamps
    time lastTime;
    time currTime;
    
    // previous axis data
    float lastAxis[6];
    // current axis data
    float axis[6];
}
// gametrack
GameTrak gt;

// HID objects
Hid trak;
HidMsg msg;

// open joystick 0, exit on fail
if( !trak.openJoystick( device ) ) me.exit();

// print
<<< "joystick '" + trak.name() + "' ready", "" >>>;

// spork control
spork ~ gametrak();
// print
spork ~ print();

// main loop
while( true )
{
    // left hand: L to R
    gt.axis[0]*8-4 => handL.loc.x;
    // left hand: front to back
    -gt.axis[1]*8 => handL.loc.z;
    // left hand: up down
    gt.axis[2]*40-5 => handL.loc.y;
    // add vertex
    trailL.eval( "add", handL.loc );
    // right hand: L to R
    gt.axis[3]*8+4 => handR.loc.x;
    // left hand: front to back
    -gt.axis[4]*8 => handR.loc.z;
    // left hand: up down
    gt.axis[5]*40-5 => handR.loc.y;
    // add vertex
    trailR.eval( "add", handR.loc );
    // synchronize to display
    VR.displaySync() => now;
}

// print
fun void print()
{
    // time loop
    while( true )
    {
        // values
        <<< "axes:", gt.axis[0],gt.axis[1],gt.axis[2], gt.axis[3],gt.axis[4],gt.axis[5] >>>;
        // advance time
        100::ms => now;
    }
}

// gametrack handling
fun void gametrak()
{
    while( true )
    {
        // wait on HidIn as event
        trak => now;
        
        // messages received
        while( trak.recv( msg ) )
        {
            // joystick axis motion
            if( msg.isAxisMotion() )
            {            
                // check which
                if( msg.which >= 0 && msg.which < 6 )
                {
                    // check if fresh
                    if( now > gt.currTime )
                    {
                        // time stamp
                        gt.currTime => gt.lastTime;
                        // set
                        now => gt.currTime;
                    }
                    // save last
                    gt.axis[msg.which] => gt.lastAxis[msg.which];
                    // the z axes map to [0,1], others map to [-1,1]
                    if( msg.which != 2 && msg.which != 5 )
                    { msg.axisPosition => gt.axis[msg.which]; }
                    else
                    {
                        1 - ((msg.axisPosition + 1) / 2) - DEADZONE => gt.axis[msg.which];
                        if( gt.axis[msg.which] < 0 ) 0 => gt.axis[msg.which];
                    }
                }
            }
            
            // joystick button down
            else if( msg.isButtonDown() )
            {
                <<< "button", msg.which, "down" >>>;
            }
            
            // joystick button up
            else if( msg.isButtonUp() )
            {
                <<< "button", msg.which, "up" >>>;
            }
        }
    }
}
