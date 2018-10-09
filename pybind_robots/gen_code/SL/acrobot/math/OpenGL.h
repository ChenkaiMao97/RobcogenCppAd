#define RAD2DEG (57.3)

static double x,y,z; // support vars

// The state of the base
glPushMatrix();
glTranslated((GLdouble)basec[0].x[1],(GLdouble)basec[0].x[2],(GLdouble)basec[0].x[3]);
glRotated((GLdouble)114.5916*ArcCos(baseo[0].q[1]),(GLdouble)baseo[0].q[2],(GLdouble)baseo[0].q[3],(GLdouble)baseo[0].q[4]);

// Joint jA

glPushMatrix();
glPushMatrix();
// Align the Z axis along the direction between the two joints, to display
//  the link correctly ('myDrawGLElement()' draws along the Z axis)
// nothing to do
myDrawGLElement(::JA, 0.0, 1);
glPopMatrix();

// move to the next joint, the same parameters as in the kinematics model file
glTranslated((GLdouble)0.0, (GLdouble)0.0, (GLdouble)0.0);
glRotated((GLdouble)(RAD2DEG*0.0), (GLdouble)1.0, (GLdouble)0.0, (GLdouble)0.0);
glRotated((GLdouble)(RAD2DEG*0.0), (GLdouble)0.0, (GLdouble)1.0, (GLdouble)0.0);
glRotated((GLdouble)(RAD2DEG*0.0), (GLdouble)0.0, (GLdouble)0.0, (GLdouble)1.0);

// move according to the joint state
glRotated((GLdouble)RAD2DEG*state[::JA].th,(GLdouble)0.0, (GLdouble)0.0, (GLdouble)1.0);

// Joint jB

glPushMatrix();
glPushMatrix();
// Align the Z axis along the direction between the two joints, to display
//  the link correctly ('myDrawGLElement()' draws along the Z axis)
glRotated((GLdouble)(RAD2DEG*std::acos( 0.0/(std::sqrt(1.0*1.0 + 0.0*0.0 + 0.0*0.0)) )), (GLdouble)-(0.0), (GLdouble)1.0, (GLdouble)0.0);
myDrawGLElement(::JB, 1.0, 1);
glPopMatrix();

// move to the next joint, the same parameters as in the kinematics model file
glTranslated((GLdouble)1.0, (GLdouble)0.0, (GLdouble)0.0);
glRotated((GLdouble)(RAD2DEG*0.0), (GLdouble)1.0, (GLdouble)0.0, (GLdouble)0.0);
glRotated((GLdouble)(RAD2DEG*0.0), (GLdouble)0.0, (GLdouble)1.0, (GLdouble)0.0);
glRotated((GLdouble)(RAD2DEG*0.0), (GLdouble)0.0, (GLdouble)0.0, (GLdouble)1.0);

// move according to the joint state
glRotated((GLdouble)RAD2DEG*state[::JB].th,(GLdouble)0.0, (GLdouble)0.0, (GLdouble)1.0);

// Draw the end effector
glPushMatrix();
x = eff[1].x[_X_];
y = eff[1].x[_Y_];
z = eff[1].x[_Z_];
glRotated(
        (GLdouble)RAD2DEG*acos(z),(GLdouble)-y,(GLdouble)x,(GLdouble)0);
myDrawGLElement(101, (double)Sqrt(x*x + y*y + z*z), 0);
glPopMatrix();

glPopMatrix();

glPopMatrix();

// pops the first matrix related to the state of the base
glPopMatrix();
