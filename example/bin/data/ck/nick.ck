// get root
VR.getEntity("root") @=> VREntity root;
// make a nick
VR.makeEntity("nick","nick") @=> VREntity nick;
// add to root
root.addChild( nick );


nick.eval( "toggle split" );
nick.eval( "toggle fill" );
nick.eval( "toggle wireframe" );
nick.eval( "toggle normals" );
nick.eval( "toggle axes" );

nick.eval( "rotate x 2" );
nick.eval( "rotate y 2" );


// infinite time loop
while( true )
{
    // do nothing

    // when there is a new graphics draw
    VR.displaySync() => now;
}
