#include<windows.h>
#include<GL/glut.h>
#include<math.h>
#include<iostream>
#include<stdio.h>
#define PI 3.14159265358979323846264338327950288419716939937510582097494459230781640
float angle = 0.0;
float x = 137.0, z = 10.0;    //Represents the camera's direction
float lx = 0.0, lz = -1.0;  //For the XZ position of the camera
float deltaAngle = 0.0; 
float deltaMove = 0.0;
float camHeight = 2.0;  //Initial height of camera position
int theta;  //The angle to draw circle
GLfloat density = 0.03;     //These are fog variables
GLfloat fogColor[4] = { 0.6, 0.6, 0.6, 1.0 };
float rate = 0.0;
float windangle = 0.05;

void circle(float xa, float ya, float ra) {
    glPushMatrix();
    glBegin(GL_POLYGON);
    for (theta = 0; theta < 360; theta++)
        glVertex3f(xa + (ra * cos(theta * PI / 180)), 0.02, ya + (ra * sin(theta * PI / 180)));
    glEnd();
    glPopMatrix();
}
void cylinder(GLdouble ba, GLdouble ta, GLdouble ha, GLdouble slia, GLdouble slaka) {
    glPushMatrix();
    GLUquadricObj* cyl;
    cyl = gluNewQuadric();
    gluQuadricDrawStyle(cyl, GL_POLYGON);
    glRotatef(-90.0, 1.0, 0.0, 0.0);
    glRotatef(45.0, 0.0, 0.0, 1.0);
    glTranslatef(0, 0.0, 0);
    gluCylinder(cyl, ba, ta, ha, 8, 8);
    glPopMatrix();
}
/** Amusement1 **/
void horse() {
    glPushMatrix();
    glTranslatef(0, 1.0, 0);
    //Body of horse
    glPushMatrix();
    glColor3ub(128, 0, 128);
    glScalef(1.0, 0.5, 0.8);
    glutSolidCube(0.7);
    glPopMatrix();

    //Head of the horse
    glPushMatrix();
    glColor3ub(128, 0, 128);
    glTranslatef(-0.4, 0.3, 0);
    glutSolidCube(0.28);
    glPopMatrix();
    glPopMatrix();

    //Leg 1
    glPushMatrix();
    glColor3ub(128, 0, 128);
    glTranslatef(0.3, 0.62, -0.2);
    cylinder(0.05, 0.05, 0.22, 70, 70);
    glPopMatrix();

    //leg 2
    glPushMatrix();
    glColor3ub(128, 0, 128);
    glTranslatef(-0.3, 0.62, -0.2);
    cylinder(0.05, 0.05, 0.22, 70, 70);
    glPopMatrix();

    //leg 3
    glPushMatrix();
    glColor3ub(128, 0, 128);
    glTranslatef(-0.3, 0.62, 0.2);
    cylinder(0.05, 0.05, 0.22, 70, 70);
    glPopMatrix();

    //leg 4
    glPushMatrix();
    glColor3ub(128, 0, 128);
    glTranslatef(0.3, 0.62, 0.2);
    cylinder(0.05, 0.05, 0.22, 70, 70);
    glPopMatrix();
}
void amusement1() {
    glPushMatrix();
    glScalef(1.5, 1.5, 1.5);
    glRotatef(-windangle, 0.0, 1.0, 0.0);
    windangle = windangle + rate + rate;
    //Base of amusement 1
    glPushMatrix();
    glColor3ub(115, 57, 0);
    circle(0.0, 0.0, 1.8);
    cylinder(1.8, 1.8, 0.2, 70, 70);
    glPopMatrix();
    //circle 1
    glPushMatrix();
    glTranslatef(0, 0.18, 0);
    circle(0.0, 0.0, 1.8);
    glPopMatrix();
    //circle 2
    glPushMatrix();
    glColor3ub(191, 191, 0);
    glTranslatef(0, 0.182, 0);
    circle(0.0, 0.0, 1.6);
    glPopMatrix();
    //circle 3
    glPushMatrix();
    glColor3ub(115, 57, 0);
    glTranslatef(0, 0.183, 0);
    circle(0.0, 0.0, 1.4);
    glPopMatrix();
    //middle rod
    glPushMatrix();
    glColor3ub(49, 49, 49);
    glTranslatef(0, 0, 0);
    cylinder(0.3, 0.3, 2.3, 30, 30);
    glPopMatrix();
    //1st rod
    glPushMatrix();
    glTranslatef(0, 0, 1.5);
    glColor3ub(191, 191, 0);
    cylinder(0.1, 0.1, 2.3, 30, 30);
    glPopMatrix();
    //2nd rod
    glPushMatrix();
    glColor3ub(191, 191, 0);
    glTranslatef(1.5, 0, 0);
    cylinder(0.1, 0.1, 2.3, 30, 30);
    glPopMatrix();
    //3rd rod
    glPushMatrix();
    glColor3ub(191, 191, 0);
    glTranslatef(-1.5, 0, 0);
    cylinder(0.1, 0.1, 2.3, 30, 30);
    glPopMatrix();
    //4th rod
    glPushMatrix();
    glColor3ub(191, 191, 0);
    glTranslatef(0, 0, -1.5);
    cylinder(0.1, 0.1, 2.3, 30, 30);
    glPopMatrix();
    //Top of the amusement 1
    glPushMatrix();
    glColor3ub(191, 191, 0);
    glTranslatef(0, 2.1, 0);
    cylinder(1.8, 1.8, 0.23, 70, 70);
    glPopMatrix();
    //circle 1
    glPushMatrix();
    glColor3ub(196, 0, 0);
    glTranslatef(0, 2.3, 0);
    circle(0.0, 0.0, 1.8);
    glPopMatrix();
    //circle 2
    glPushMatrix();
    glColor3ub(191, 191, 0);
    glTranslatef(0, 2.28, 0);
    circle(0.0, 0.0, 1.6);
    glPopMatrix();
    //circle 3
    glPushMatrix();
    glColor3ub(196, 0, 0);
    glTranslatef(0, 2.27, 0);
    circle(0.0, 0.0, 1.4);
    glPopMatrix();
    //Horses on the 4 rods
    glPushMatrix();
    glTranslatef(0, 0, 1.5);
    horse();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, -1.5);
    glRotatef(180, 0, 1, 0);
    horse();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(1.5, 0, 0);
    glRotatef(90, 0, 1, 0);
    horse();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(-1.5, 0, 0);
    glRotatef(-90, 0, 1, 0);
    horse();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}
/** Amusement2 **/
void amusementpark_seater() {
    //Building the seater
    glPushMatrix();
    glColor3ub(255, 255, 0);
    glTranslatef(0, 0, -0.2);
    glScalef(3.2, 0.1, 1.1);
    glutSolidCube(0.8);
    glPopMatrix();
    glPushMatrix();
    glColor3ub(255, 255, 0);
    glTranslatef(0, 0.35, -0.6);
    glRotatef(90, 1, 0, 0);
    glScalef(3.2, 0.1, 1.0);
    glutSolidCube(0.8);
    glPopMatrix();
    //handle 1
    glPushMatrix();
    glColor3ub(0, 0, 0);
    glTranslatef(0, 0, 0);
    cylinder(0.02, 0.02, 0.5, 30, 30);
    glPopMatrix();
    glPushMatrix();
    glColor3ub(0, 0, 0);
    glTranslatef(0, 0.5, 0);
    glRotatef(-90, 1, 0, 0);
    cylinder(0.02, 0.02, 0.55, 30, 30);
    glPopMatrix();
    glPushMatrix();
    glColor3ub(0, 0, 0);
    glTranslatef(0, 0.5, 0);
    glutSolidSphere(0.02, 10, 10);
    glPopMatrix();
    //handle 2
    glPushMatrix();
    glTranslatef(0.6, 0, 0);
    glPushMatrix();
    glColor3ub(0, 0, 0);
    glTranslatef(0, 0, 0);
    cylinder(0.02, 0.02, 0.5, 30, 30);
    glPopMatrix();
    glPushMatrix();
    glColor3ub(0, 0, 0);
    glTranslatef(0, 0.5, 0);
    glRotatef(-90, 1, 0, 0);
    cylinder(0.02, 0.02, 0.55, 30, 30);
    glPopMatrix();
    glPushMatrix();
    glColor3ub(0, 0, 0);
    glTranslatef(0, 0.5, 0);
    glutSolidSphere(0.02, 10, 10);
    glPopMatrix();
    glPopMatrix();
    //handle 3
    glPushMatrix();
    glTranslatef(1.1, 0, 0);
    glPushMatrix();
    glColor3ub(0, 0, 0);
    glTranslatef(0, 0, 0);
    cylinder(0.02, 0.02, 0.5, 30, 30);
    glPopMatrix();
    glPushMatrix();
    glColor3ub(0, 0, 0);
    glTranslatef(0, 0.5, 0);
    glRotatef(-90, 1, 0, 0);
    cylinder(0.02, 0.02, 0.55, 30, 30);
    glPopMatrix();
    glPushMatrix();
    glColor3ub(0, 0, 0);
    glTranslatef(0, 0.5, 0);
    glutSolidSphere(0.02, 10, 10);
    glPopMatrix();
    glPopMatrix();
    //handle 4
    glPushMatrix();
    glTranslatef(-1.1, 0, 0);
    glPushMatrix();
    glColor3ub(0, 0, 0);
    glTranslatef(0, 0, 0);
    cylinder(0.02, 0.02, 0.5, 30, 30);
    glPopMatrix();
    glPushMatrix();
    glColor3ub(0, 0, 0);
    glTranslatef(0, 0.5, 0);
    glRotatef(-90, 1, 0, 0);
    cylinder(0.02, 0.02, 0.55, 30, 30);
    glPopMatrix();
    glPushMatrix();
    glColor3ub(0, 0, 0);
    glTranslatef(0, 0.5, 0);
    glutSolidSphere(0.02, 10, 10);
    glPopMatrix();
    glPopMatrix();
    //handle 5
    glPushMatrix();
    glTranslatef(-0.6, 0, 0);
    glPushMatrix();
    glColor3ub(0, 0, 0);
    glTranslatef(0, 0, 0);
    cylinder(0.02, 0.02, 0.5, 30, 30);
    glPopMatrix();
    glPushMatrix();
    glColor3ub(0, 0, 0);
    glTranslatef(0, 0.5, 0);
    glRotatef(-90, 1, 0, 0);
    cylinder(0.02, 0.02, 0.55, 30, 30);
    glPopMatrix();
    glPushMatrix();
    glColor3ub(0, 0, 0);
    glTranslatef(0, 0.5, 0);
    glutSolidSphere(0.02, 10, 10);
    glPopMatrix();
    glPopMatrix();
}
void amusement2() {

    //bottom base
    glPushMatrix();
    glColor3ub(0, 0, 160);
    glScalef(3.0, 0.8, 3.0);
    glScalef(1.5, 1.6, 2.0);
    glutSolidCube(0.5);
    glPopMatrix();

    //middle long rod
    glPushMatrix();
    glColor3ub(0, 0, 160);
    cylinder(0.4, 0.4, 10.0, 30, 30);
    glPopMatrix();

    //middle cube
    glPushMatrix();
    glColor3ub(0, 0, 160);
    glScalef(1.2, 1.6, 2.0);
    glTranslatef(0, 5.8, 0);
    glutSolidCube(0.8);

    //top slant rod
    glPushMatrix();
    glColor3ub(54, 54, 54);
    glTranslatef(1.5, 0, 0);
    glRotatef(90, 0, 0, 1);
    cylinder(0.1, 0.1, 3.2, 70, 70);
    glPopMatrix();

    //Rotating right side part
    //right cube
    glPushMatrix();
    glTranslatef(0, -5.8, 0);
    glColor3ub(0, 0, 160);
    glTranslatef(2.2, 5.8, 0);
    glRotatef(90, 0, 1, 0);

    glRotatef(-windangle, 0.0, 0.0, 1.0);
    windangle = windangle + (rate / 2.0);

    glPushMatrix();
    glScalef(1.2, 1.6, 1.8);
    glutSolidCube(0.8);
    glPopMatrix();

    //right double rod
    glPushMatrix();
    glTranslatef(0, -5.5, -1.9);
    glScalef(0.8, 1., 0.8);
    glRotatef(-90, 0, 1, 0);
    glPushMatrix();
    glColor3ub(54, 54, 54);
    glTranslatef(2.7, 1.0, 0);
    cylinder(0.15, 0.15, 4.2, 70, 70);
    glPopMatrix();
    glPushMatrix();
    glColor3ub(54, 54, 54);
    glTranslatef(2.1, 1.0, 0);
    cylinder(0.15, 0.15, 4.2, 70, 70);
    glPopMatrix();

    //right slant cube
    glPushMatrix();
    glColor3ub(0, 0, 200);
    glTranslatef(2.4, 1.0, 0);
    glScalef(3.2, 0.25, 7.6);
    glutSolidCube(0.8);
    glPopMatrix();

    //right back chair
    glPushMatrix();
    glTranslatef(2.4, 1.14, -1.89);
    amusementpark_seater();
    glPopMatrix();

    //right front chair
    glPushMatrix();
    glTranslatef(2.4, 1.14, 1.7);
    amusementpark_seater();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();


    //Rotating Left side part
    //left cube
    glPushMatrix();
    glTranslatef(0, -5.8, 0);
    glColor3ub(0, 0, 160);
    glTranslatef(-2.4, 5.8, 0);
    glRotatef(90, 0, 1, 0);
    glRotatef(windangle, 0.0, 0.0, 1.0);
    windangle = windangle + (rate / 2.0);
    glPushMatrix();
    glScalef(1.2, 1.6, 1.8);
    glutSolidCube(0.8);
    glPopMatrix();

    //left double rod
    glPushMatrix();
    glTranslatef(0, -5.5, 1.9);
    glScalef(0.8, 1., 0.8);
    glRotatef(-90, 0, 1, 0);
    glPushMatrix();
    glColor3ub(54, 54, 54);
    glTranslatef(-2.8, 1.0, 0);
    cylinder(0.15, 0.15, 4.2, 70, 70);
    glPopMatrix();
    glPushMatrix();
    glColor3ub(54, 54, 54);
    glTranslatef(-2.1, 1.0, 0);
    cylinder(0.15, 0.15, 4.2, 70, 70);
    glPopMatrix();

    //left slant cube
    glPushMatrix();
    glColor3ub(0, 0, 200);
    glTranslatef(-2.4, 1.0, 0);
    glScalef(3.2, 0.25, 7.6);
    glutSolidCube(0.8);
    glPopMatrix();

    //left back chair
    glPushMatrix();
    glTranslatef(-2.4, 1.14, -1.89);
    amusementpark_seater();
    glPopMatrix();

    //left front chair
    glPushMatrix();
    glTranslatef(-2.4, 1.14, 1.7);
    amusementpark_seater();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
}
/** Amusement3 **/
void giantwheelchair() {
    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glPushMatrix();
    glTranslatef(2.5, 0.05, -0.65);
    glRotatef(90, 0, 0, 1);
    cylinder(0.06, 0.06, 5.0, 20, 20);
    glPopMatrix();
    amusementpark_seater();
    glPopMatrix();
}
void giantwheelrod() {
    glColor3f(0.0, 0.5, 1.0);
    //1st rod.for 2nd circle
    glPushMatrix();
    cylinder(0.05, 0.05, 7, 70, 70);
    glPopMatrix();
    //2nd rod.for 2nd circle
    glPushMatrix();
    glRotatef(45, 0, 0, 1);
    cylinder(0.05, 0.05, 7, 70, 70);
    glPopMatrix();
    //3rd rod.for 2nd circle
    glPushMatrix();
    glRotatef(90, 0, 0, 1);
    cylinder(0.05, 0.05, 7, 70, 70);
    glPopMatrix();
    //4th rod.for 2nd circle
    glPushMatrix();
    glRotatef(135, 0, 0, 1);
    cylinder(0.05, 0.05, 7, 70, 70);
    glPopMatrix();
    //5th rod.for 2nd circle
    glPushMatrix();
    glRotatef(180, 0, 0, 1);
    cylinder(0.05, 0.05, 7, 70, 70);
    glPopMatrix();
    //6th rod.for 2nd circle
    glPushMatrix();
    glRotatef(225, 0, 0, 1);
    cylinder(0.05, 0.05, 7, 70, 70);
    glPopMatrix();
    //7th rod.for 2nd circle
    glPushMatrix();
    glRotatef(275, 0, 0, 1);
    cylinder(0.05, 0.05, 7, 70, 70);
    glPopMatrix();
    //8th rod.for 2nd circle
    glPushMatrix();
    glRotatef(315, 0, 0, 1);
    cylinder(0.05, 0.05, 7, 70, 70);
    glPopMatrix();
}
void amusement3() {
    //base rod 1
    glPushMatrix();
    glColor3ub(101, 101, 101);
    glTranslatef(-8.5, 0, 1.0);
    glRotatef(-45, 0, 0, 1);
    cylinder(0.3, 0.3, 12.2, 70, 70);
    glPopMatrix();
    glPushMatrix();
    glColor3ub(101, 101, 101);
    glTranslatef(8.5, 0, 1.0);
    glRotatef(45, 0, 0, 1);
    cylinder(0.3, 0.3, 12.5, 70, 70);
    glPopMatrix();
    //base rod 2
    glPushMatrix();
    glColor3ub(101, 101, 101);
    glTranslatef(-8.5, 0, -6.0);
    glRotatef(-45, 0, 0, 1);
    cylinder(0.2, 0.2, 12.5, 70, 70);
    glPopMatrix();
    glPushMatrix();
    glColor3ub(101, 101, 101);
    glTranslatef(8.5, 0, -6.0);
    glRotatef(45, 0, 0, 1);
    cylinder(0.2, 0.2, 12.2, 70, 70);
    glPopMatrix();
    //Rotation for the giant wheel
    glPushMatrix();
    glColor3f(0.0, 0.5, 1.0);
    glTranslatef(0, 8.5, 0);
    glRotatef(windangle, 0.0, 0.0, 1.0);
    windangle = windangle + rate;
    //1st circle
    glutSolidTorus(0.2, 7.0, 50, 500);
    //2nd circle
    glTranslatef(0, 0, -5.0);
    glutSolidTorus(0.2, 7.0, 50, 50);
    //reverting the position to place the rods from center of circle
    glTranslatef(0, 0, 0);
    //cylinder in the middle
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glColor3ub(101, 101, 101);
    glTranslatef(0, -1.0, 0);
    cylinder(0.4, 0.4, 7.0, 30, 30);
    glPopMatrix();
    //2 circle at the ends of middle cylinder
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glColor3ub(255, 255, 255);
    glTranslatef(0, 6.0, 0.0);
    glutSolidSphere(0.6, 20, 20);
    glPopMatrix();
    glPushMatrix();
    glRotatef(90, 1, 0, 0);
    glColor3ub(255, 255, 255);
    glTranslatef(0, -1.0, 0.0);
    glutSolidSphere(0.6, 20, 20);
    glPopMatrix();
    glPushMatrix();
    giantwheelrod();
    glPopMatrix();
    glPushMatrix();
    glTranslatef(0, 0, 5);
    giantwheelrod();
    glPopMatrix();
    //reverting position to the center of 2 giant wheel circles
    glTranslatef(0, 0.0, 0);
    //Placing the seater on the giant wheel
    //1st chair
    glPushMatrix();
    glTranslatef(-7.0, -0.55, 2.4);
    glRotatef(-90, 0, 0, 1);
    giantwheelchair();
    glPopMatrix();
    //2nd chair
    glPushMatrix();
    glTranslatef(-4.5, -5.35, 2.5);
    glRotatef(-45, 0, 0, 1);
    glColor3f(0.0, 0.5, 1.0);
    giantwheelchair();
    glPopMatrix();
    //3rd chair
    glPushMatrix();
    glTranslatef(0.5, -7., 2.5);
    //glRotatef(0,0,0,1);
    glColor3f(0.0, 0.5, 1.0);
    giantwheelchair();
    glPopMatrix();
    //4th chair
    glPushMatrix();
    glTranslatef(5.3, -4.5, 2.5);
    glRotatef(45, 0, 0, 1);
    glColor3f(0.0, 0.5, 1.0);
    giantwheelchair();
    glPopMatrix();
    //5th chair
    glPushMatrix();
    glTranslatef(7.0, 0.6, 2.4);
    glRotatef(90, 0, 0, 1);
    glColor3f(0.0, 0.5, 1.0);
    giantwheelchair();
    glPopMatrix();
    //6th chair
    glPushMatrix();
    glTranslatef(4.5, 5.5, 2.5);
    glRotatef(135, 0, 0, 1);
    glColor3f(0.0, 0.5, 1.0);
    giantwheelchair();
    glPopMatrix();
    //7nd chair
    glPushMatrix();
    glTranslatef(-0.55, 6.9, 2.5);
    glRotatef(180, 0, 0, 1);
    glColor3f(0, 0.5, 1.0);
    giantwheelchair();
    glPopMatrix();
    //8th chair
    glPushMatrix();
    glTranslatef(-5.5, 4.55, 2.4);
    glRotatef(225, 0, 0, 1);
    glColor3f(0, 0.5, 1.0);
    giantwheelchair();
    glPopMatrix();
    glPopMatrix();
}
/** Amusement4 **/
void amusementpark_seater1() {
    glPushMatrix();
    //base of the seater1
    glBegin(GL_POLYGON);
    glColor3ub(115, 57, 0);
    glVertex3f(-0.4, 0.0, 0);
    glVertex3f(-0.4, 0.5, 0);
    glVertex3f(0.4, 0.5, 0);
    glVertex3f(0.4, 0.0, 0);
    glEnd();
    //back of the seater1
    glPushMatrix();
    glColor3ub(115, 57, 1);
    glRotatef(90, 1, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.4, 0.0, 0);
    glVertex3f(-0.4, 0.4, 0);
    glVertex3f(0.4, 0.4, 0);
    glVertex3f(0.4, 0.0, 0);
    glEnd();
    glPopMatrix();
    //2 sides of the seater
    glPushMatrix();
    glColor3ub(115, 57, 0);
    glBegin(GL_POLYGON);
    glVertex3f(-0.399, 0.0, 0.0);
    glVertex3f(-0.399, 0.0, 0.4);
    glVertex3f(-0.399, 0.5, 0.4);
    glVertex3f(-0.399, 0.5, 0.0);
    glEnd();
    glPopMatrix();
    glPushMatrix();
    glColor3ub(115, 57, 0);
    glBegin(GL_POLYGON);
    glVertex3f(0.399, 0.0, 0.0);
    glVertex3f(0.399, 0.0, 0.4);
    glVertex3f(0.399, 0.5, 0.4);
    glVertex3f(0.399, 0.5, 0.0);
    glEnd();
    glPopMatrix();
    glPopMatrix();
}
void amusement4() {
    glPushMatrix();
    glScalef(1.5, 1.5, 1.5);
    glRotatef(windangle, 0.0, 1.0, 0.0);
    windangle = windangle + rate + rate;
    //base of amusement4
    glPushMatrix();
    glColor3ub(191, 191, 0);
    circle(0.0, 0, 1.8);
    cylinder(1.8, 1.8, .2, 70, 70);
    glPopMatrix();

    //Circles at the base
    //circle 1
    glPushMatrix();
    glColor3ub(255, 0, 255);
    glTranslatef(0, 0.18, 0);
    circle(0.0, 0.0, 1.8);
    glPopMatrix();
    //circle 2
    glPushMatrix();
    glColor3ub(0, 255, 0);
    glTranslatef(0, 0.182, 0);
    circle(0.0, 0.0, 1.6);
    glPopMatrix();
    //circle 3
    glPushMatrix();
    glColor3ub(255, 0, 255);
    glTranslatef(0, 0.183, 0);
    circle(0.0, 0.0, 1.4);
    glPopMatrix();

    //height of the cylinder to be passed as argument
    GLdouble h = 2.0;

    //rod of amusement4
    //middle rod
    glPushMatrix();
    glColor3ub(111, 43, 213);
    glTranslatef(0, 0, 0);
    cylinder(0.3, 0.3, 3.3, 30, 30);
    glPopMatrix();

    //1st rod and seater
    glPushMatrix();
    glTranslatef(0, 1.3, 1.5);
    glColor3ub(0, 128, 0);
    glRotatef(90, 0, 1, 0);
    cylinder(0.05, 0.05, h, 30, 30);
    glTranslatef(0, -0.5, 0);
    amusementpark_seater1();
    glPopMatrix();
    //2nd rod and seater
    glPushMatrix();
    glColor3ub(0, 128, 0);
    glTranslatef(1.5, 1.3, 0);
    glRotatef(180, 0, 1, 0);
    cylinder(0.05, 0.05, h, 30, 30);
    glTranslatef(0, -0.5, 0);
    amusementpark_seater1();
    glPopMatrix();
    //3rd rod and seater
    glPushMatrix();
    glColor3ub(0, 128, 0);
    glTranslatef(-1.5, 1.3, 0);
    glRotatef(360, 0, 1, 0);
    cylinder(0.05, 0.05, h, 30, 30);
    glTranslatef(0, -0.5, 0);
    amusementpark_seater1();
    glPopMatrix();
    //4th rod and seater
    glPushMatrix();
    glColor3ub(0, 128, 0);
    glTranslatef(0, 1.3, -1.5);
    glRotatef(270, 0, 1, 0);
    cylinder(0.05, 0.05, h, 30, 30);
    glTranslatef(0, -0.5, 0);
    amusementpark_seater1();
    glPopMatrix();
    //5th rod and seater
    glPushMatrix();
    glTranslatef(-1.1, 1.3, 1.1);
    glColor3ub(0, 128, 0);
    glRotatef(45, 0, 1, 0);
    cylinder(0.05, 0.05, h, 30, 30);
    glTranslatef(0, -0.5, 0);
    amusementpark_seater1();
    glPopMatrix();
    //6th rod and seater
    glPushMatrix();
    glTranslatef(-1.1, 1.3, -1.1);
    glColor3ub(0, 128, 0);
    glRotatef(315, 0, 1, 0);
    cylinder(0.05, 0.05, h, 30, 30);
    glTranslatef(0, -0.5, 0);
    amusementpark_seater1();
    glPopMatrix();
    //7th rod and seater
    glPushMatrix();
    glTranslatef(1.1, 1.3, -1.1);
    glColor3ub(0, 128, 0);
    glRotatef(225, 0, 1, 0);
    cylinder(0.05, 0.05, h, 30, 30);
    glTranslatef(0, -0.5, 0);
    amusementpark_seater1();
    glPopMatrix();
    //8th rod and seater
    glPushMatrix();
    glTranslatef(1.1, 1.3, 1.1);
    glColor3ub(0, 128, 0);
    glRotatef(135, 0, 1, 0);
    cylinder(0.05, 0.05, h, 30, 30);
    glTranslatef(0, -0.5, 0);
    amusementpark_seater1();
    glPopMatrix();
    //top of the amusement 1*
    glPushMatrix();
    glColor3ub(191, 191, 0);
    glTranslatef(0, 3.1, 0);
    cylinder(1.8, 1.8, 0.23, 70, 70);
    glPopMatrix();

    //Circles at the top
    //circle 1
    glPushMatrix();
    glColor3ub(255, 0, 255);
    glTranslatef(0, 3.3, 0);
    circle(0.0, 0.0, 1.8);
    glPopMatrix();
    //circle 2
    glPushMatrix();
    glColor3ub(0, 255, 0);
    glTranslatef(0, 3.28, 0);
    circle(0.0, 0.0, 1.6);
    glPopMatrix();
    //circle 3
    glPushMatrix();
    glColor3ub(255, 0, 255);
    glTranslatef(0, 3.27, 0);
    circle(0.0, 0.0, 1.4);
    glPopMatrix();}
/** Amusement5 **/
void amusement5() {

    //bottom base
    glPushMatrix();
    glColor3ub(0, 0, 160);
    glScalef(3.0, 0.8, 3.0);
    glScalef(1.5, 1.6, 2.0);
    glutSolidCube(0.5);
    glPopMatrix();

    //middle long rod
    glPushMatrix();
    glColor3ub(0, 0, 160);
    cylinder(0.4, 0.4, 10.0, 30, 30);
    glPopMatrix();

    //middle top cube
    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glRotatef(-windangle, 0.0, 1.0, 0.0);
    glScalef(1.2, 1.6, 2.0);
    glColor3ub(0, 0, 160);
    glTranslatef(0, 5.8, 0);
    glutSolidCube(0.8);

    //top slant rod
    glPushMatrix();
    glColor3ub(54, 54, 54);
    glTranslatef(1.5, 0, 0);
    glRotatef(90, 0, 0, 1);
    cylinder(0.1, 0.1, 3.2, 70, 70);
    glPopMatrix();

    //Rotating right side part
    //right cube
    glPushMatrix();
    glTranslatef(0, -5.8, 0);
    glColor3ub(0, 0, 160);
    glTranslatef(2.2, 5.8, 0);
    glRotatef(90, 0, 1, 0);
    glRotatef(-windangle, 0.0, 0.0, 1.0);
    windangle = windangle + (rate / 2.0);
    glPushMatrix();
    glScalef(1.2, 1.6, 1.8);
    glutSolidCube(0.8);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -5.5, -1.9);
    glScalef(0.8, 1., 0.8);
    glRotatef(-90, 0, 1, 0);

    //right double rod
    glPushMatrix();
    glColor3ub(54, 54, 54);
    glTranslatef(2.7, 1.0, 0);
    cylinder(0.15, 0.15, 4.2, 70, 70);
    glPopMatrix();
    glPushMatrix();
    glColor3ub(54, 54, 54);
    glTranslatef(2.1, 1.0, 0);
    cylinder(0.15, 0.15, 4.2, 70, 70);
    glPopMatrix();

    //right slant cube to place the seater1
    glPushMatrix();
    glColor3ub(0, 0, 200);
    glTranslatef(2.4, 1.0, 0);
    glScalef(3.2, 0.25, 7.6);
    glutSolidCube(0.8);
    glPopMatrix();

    //right back chair
    glPushMatrix();
    glTranslatef(2.4, 1.14, -1.89);
    amusementpark_seater();
    glPopMatrix();

    //right front chair
    glPushMatrix();
    glTranslatef(2.4, 1.14, 1.7);
    amusementpark_seater();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();


    //Rotating left side part
    //left cube
    glPushMatrix();
    glTranslatef(0, -5.8, 0);
    glColor3ub(0, 0, 160);
    glTranslatef(-2.4, 5.8, 0);
    glRotatef(90, 0, 1, 0);
    glRotatef(windangle, 0.0, 0.0, 1.0);
    windangle = windangle + (rate / 2.0);
    glPushMatrix();
    glScalef(1.2, 1.6, 1.8);
    glutSolidCube(0.8);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0, -5.5, 1.9);
    glScalef(0.8, 1., 0.8);
    glRotatef(-90, 0, 1, 0);

    //left double rod
    glPushMatrix();
    glColor3ub(54, 54, 54);
    glTranslatef(-2.8, 1.0, 0);
    cylinder(0.15, 0.15, 4.2, 70, 70);
    glPopMatrix();
    glPushMatrix();
    glColor3ub(54, 54, 54);
    glTranslatef(-2.1, 1.0, 0);
    cylinder(0.15, 0.15, 4.2, 70, 70);
    glPopMatrix();

    //left slant cube to place the seater
    glPushMatrix();
    glColor3ub(0, 0, 200);
    glTranslatef(-2.4, 1.0, 0);
    glScalef(3.2, 0.25, 7.6);
    glutSolidCube(0.8);
    glPopMatrix();

    //left back chair
    glPushMatrix();
    glTranslatef(-2.4, 1.14, -1.89);
    amusementpark_seater();
    glPopMatrix();

    //left front chair
    glPushMatrix();
    glTranslatef(-2.4, 1.14, 1.7);
    amusementpark_seater();
    glPopMatrix();
    glPopMatrix();
    glPopMatrix();
    //end of first push matrix
    glPopMatrix();
}
/** Amusement Park **/
void amusground() {
    //fence around the parking area
    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glTranslatef(125.9, 0, 190);
    glPopMatrix();
    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glTranslatef(115.75, 0, 190);
    glPopMatrix();
    glPushMatrix();
    glRotatef(90, 0, 1, 0);
    glTranslatef(105.35, 0, 190);
    glPopMatrix();
    glPushMatrix();
    glTranslatef(210, 0.017, -74.75);
    glPopMatrix();

    //white area in front of parking
    glBegin(GL_QUADS);
    glColor3ub(198, 198, 198);
    glVertex3f(190, 0.013, -75.2);
    glVertex3f(139.3, 0.015, -75.2);
    glVertex3f(139.3, 0.015, -105.7);
    glVertex3f(190, 0.015, -105.7);
    glEnd();

    //black layer
    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex3f(190, 0.017, -75.2);
    glVertex3f(148.99, 0.017, -75.2);
    glVertex3f(148.99, 0.017, -105.7);
    glVertex3f(190, 0.017, -105.7);
    glEnd();

    //1st parking white line
    glLineWidth(3.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(1, 1, 1);
    glVertex3f(190, 0.017, -75.2);
    glVertex3f(148.99, 0.017, -75.2);
    glVertex3f(148.99, 0.017, -84.7);
    glVertex3f(190, 0.017, -84.7);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(1, 1, 1);
    glVertex3f(182, 0.017, -75.2);
    glVertex3f(156.99, 0.017, -75.2);
    glVertex3f(156.99, 0.017, -84.7);
    glVertex3f(182, 0.017, -84.7);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(1, 1, 1);
    glVertex3f(174, 0.017, -75.2);
    glVertex3f(164.99, 0.017, -75.2);
    glVertex3f(164.99, 0.017, -84.7);
    glVertex3f(174, 0.017, -84.7);
    glEnd();
    glLineWidth(3.0);
    glBegin(GL_LINE_LOOP);
    glColor3f(1, 1, 1);
    glVertex3f(190, 0.017, -85.7);
    glVertex3f(148.99, 0.017, -85.7);
    glVertex3f(148.99, 0.017, -95.2);
    glVertex3f(190, 0.017, -95.2);
    glEnd();

    //2nd parking white line
    glBegin(GL_LINE_LOOP);
    glColor3f(1, 1, 1);
    glVertex3f(190, 0.017, -96.2);
    glVertex3f(148.99, 0.017, -96.2);
    glVertex3f(148.99, 0.017, -105.7);
    glVertex3f(190, 0.017, -105.7);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(1, 1, 1);
    glVertex3f(182, 0.017, -96.2);
    glVertex3f(156.99, 0.017, -96.2);
    glVertex3f(156.99, 0.017, -105.7);
    glVertex3f(182, 0.017, -105.7);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3f(1, 1, 1);
    glVertex3f(174, 0.017, -96.2);
    glVertex3f(164.99, 0.017, -96.2);
    glVertex3f(164.99, 0.017, -105.7);
    glVertex3f(174, 0.017, -105.7);
    glEnd();

    //amusement ground
    glBegin(GL_QUADS);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(190, 0.02, -14.7);
    glVertex3f(139.3, 0.02, -14.7);
    glVertex3f(139.3, 0.02, -75.2);
    glVertex3f(190, 0.02, -75.2);
    glEnd();

    //titles pattern around the amusement horizontally
    glLineWidth(3.0);
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(190, 0.02, -14.7);
    glVertex3f(139.3, 0.02, -14.7);
    glVertex3f(139.3, 0.02, -75.2);
    glVertex3f(190, 0.02, -75.2);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(190, 0.02, -18.7);
    glVertex3f(139.3, 0.02, -18.7);
    glVertex3f(139.3, 0.02, -71.2);
    glVertex3f(190, 0.02, -71.2);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(190, 0.02, -22.7);
    glVertex3f(139.3, 0.02, -22.7);
    glVertex3f(139.3, 0.02, -67.2);
    glVertex3f(190, 0.02, -67.2);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(190, 0.02, -26.7);
    glVertex3f(139.3, 0.02, -26.7);
    glVertex3f(139.3, 0.02, -63.2);
    glVertex3f(190, 0.02, -63.2);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(190, 0.02, -30.7);
    glVertex3f(139.3, 0.02, -30.7);
    glVertex3f(139.3, 0.02, -59.2);
    glVertex3f(190, 0.02, -59.2);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(190, 0.02, -34.7);
    glVertex3f(139.3, 0.02, -34.7);
    glVertex3f(139.3, 0.02, -55.2);
    glVertex3f(190, 0.02, -55.2);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(190, 0.02, -38.7);
    glVertex3f(139.3, 0.02, -38.7);
    glVertex3f(139.3, 0.02, -51.2);
    glVertex3f(190, 0.02, -51.2);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(190, 0.02, -42.7);
    glVertex3f(139.3, 0.02, -42.7);
    glVertex3f(139.3, 0.02, -47.2);
    glVertex3f(190, 0.02, -47.2);
    glEnd();

    //titles pattern on the amusement vertically
    glLineWidth(3.0);
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(186, 0.02, -14.7);
    glVertex3f(143.3, 0.02, -14.7);
    glVertex3f(143.3, 0.02, -75.2);
    glVertex3f(186, 0.02, -75.2);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(182, 0.02, -14.7);
    glVertex3f(147.3, 0.02, -14.7);
    glVertex3f(147.3, 0.02, -75.2);
    glVertex3f(182, 0.02, -75.2);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(178, 0.02, -14.7);
    glVertex3f(151.3, 0.02, -14.7);
    glVertex3f(151.3, 0.02, -75.2);
    glVertex3f(178, 0.02, -75.2);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(174, 0.02, -14.7);
    glVertex3f(155.3, 0.02, -14.7);
    glVertex3f(155.3, 0.02, -75.2);
    glVertex3f(174, 0.02, -75.2);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(170, 0.02, -14.7);
    glVertex3f(159.3, 0.02, -14.7);
    glVertex3f(159.3, 0.02, -75.2);
    glVertex3f(170, 0.02, -75.2);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);
    glVertex3f(166.25, 0.02, -14.7);
    glVertex3f(163.3, 0.02, -14.7);
    glVertex3f(163.3, 0.02, -75.2);
    glVertex3f(166.25, 0.02, -75.2);
    glEnd();
}
void amwall() {
    glPushMatrix();
    amusground();
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.0, 0.5, 1.0);
    glTranslatef(149.5, 0, -45.0);
    glRotatef(90, 0, 1, 0);
    glutSolidTorus(0.8, 5.6, 30, 30);
    glPopMatrix();
    //walls
    glPushMatrix();
    glColor3ub(230, 230, 0);
    glScalef(20.0, 1.5, 0.5);
    glTranslatef(8.5, 0, -150);
    glutSolidCube(2.0);
    glPopMatrix();
    glPushMatrix();
    glColor3ub(230, 230, 0);
    glScalef(0.5, 1.5, 30.0);
    glTranslatef(379, 0, -1.5);
    glutSolidCube(2.0);
    glPopMatrix();
    glPushMatrix();
    glColor3ub(230, 230, 0);
    glScalef(20.0, 1.5, 0.5);
    glTranslatef(8.5, 0, -30);
    glutSolidCube(2.0);
    glPopMatrix();
    glPushMatrix();
    glColor3ub(230, 230, 0);
    glScalef(0.5, 1.5, 12.0);
    glTranslatef(299, 0, -2.21);
    glutSolidCube(2.0);
    glPopMatrix();
    glPushMatrix();
    glColor3ub(230, 230, 0);
    glScalef(0.5, 1.5, 12.0);
    glTranslatef(299, 0, -5.29);
    glutSolidCube(2.0);
    glPopMatrix();
    //Big wall block at the entrance on each side of park
    glPushMatrix();
    glColor3ub(230, 230, 0);
    glScalef(0.5, 2.0, 0.5);
    glTranslatef(299, 0, -77);
    glutSolidCube(2.0);
    glPopMatrix();
    glPushMatrix();
    glColor3ub(230, 230, 0);
    glScalef(0.5, 2.0, 0.5);
    glTranslatef(299, 0, -102);
    glutSolidCube(2.0);
    glPopMatrix();
}
void amusementpark() {
    //Creating the green layer inside the park
    glColor3f(0.0, 0.5, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(190, 0.021, -14.7);
    glVertex3f(149, 0.021, -14.7);
    glVertex3f(149, 0.021, -75.0);
    glVertex3f(190, 0.021, -75.0);
    glEnd();

    //Now Placing the amusements
    glPushMatrix();
    glTranslatef(162, 0.0, -64.0);
    amusement1();

    glPushMatrix();
    glRotatef(-90, 0, 1, 0);
    glTranslatef(-62.5, 0.0, -180.0);
    amusement2();
    glTranslatef(19.5, 0, 0);
    amusement5();
    glPopMatrix();

    glPushMatrix();
    glRotatef(-180, 0, 1, 0);
    glTranslatef(-170.0, 0.0, 25.0);
    amusement3();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(162.0, 0.0, -44.5);
    amusement4();
    glPopMatrix();
    glPopMatrix();
}

void myReshape(int w, int h) {
    if (h == 0) h = 1;
    float ratio = w * 1.0 / h;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, w, h);
    gluPerspective(45.0, ratio, 0.1, 2000.0);
    glMatrixMode(GL_MODELVIEW);
}

void drawSea() {
    glDisable(GL_LIGHTING);
    glColor3f(0.0, 0.3, 1.0);
    glBegin(GL_QUADS);//sea
    glVertex3f(100, 0.005, -175);
    glVertex3f(-100, 0.005, -175);
    glVertex3f(-100, 0.005, 100);
    glVertex3f(100, 0.005, 100);
    glEnd();
    
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 1.0);
    glVertex3f(115.0, 0.005, -175);
    glColor3f(0.0, 0.3, 1.0);
    glVertex3f(100, 0.005, -175);
    glColor3f(0.0, 0.3, 1.0);
    glVertex3f(100, 0.005, 100);
    glColor3f(0.6, 0.6, 1.0);
    glVertex3f(115, 0.005, 100);
    glEnd();//sea-shore
    glColor3f((254.0 / 255.0), (199.0 / 255.0), (141.0 / 255.0));

    glBegin(GL_POLYGON);//sand
    glVertex3f(120.0, 0.005, -175.0);
    glVertex3f(115.0, 0.005, -175.0);
    glVertex3f(115.0, 0.005, 100.0);
    glVertex3f(120.0, 0.005, 100.0);
    glEnd();
    glEnable(GL_LIGHTING);
}

void lightingInit() {
    GLfloat lightpos[] = { 0.0,500.0,-500.0,0.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightpos);
    GLfloat litambient[] = { 0.8f, 0.8f, 0.8f };
    GLfloat litdiffuse[] = { 0.5f, 0.5f, 0.5f };
    GLfloat litspecular[] = { 1.0f, 1.0f, 1.0f };
    glLightfv(GL_LIGHT0, GL_AMBIENT, litambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, litdiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, litspecular);
    GLfloat mat_ambient[] = { 0.5f, 0.5f, 0.5f, 1.0f };
    GLfloat mat_diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };
    GLfloat mat_specular[] = { 0.1f, 0.1f, 0.1f, 1.0f };
    GLfloat mat_shininess[] = { 50.0f };
}

void theSun() {
    glColor3f(1.0, 0.5, 0.5);
    glPushMatrix();
    glTranslatef(-200.0, 30.0, -200.0);
    glutSolidSphere(8.0, 20, 20);
    glPopMatrix();
}

void rotatemenu(int option) {
    if (option == 1) rate = 0.1;
    if (option == 2) rate = 0.2;
    if (option == 3) rate = 0.0;
}

void drawHouse2() {
    glPushMatrix();
    glTranslatef(-4.0, 0.0, -8.0);
    glColor3f(0.6, 0.6, 0.6); 
    glRectf(-10.0, 0.0, -5.0, 3.0);
    glColor3f(0.7, 0.7, 0.7);
    glBegin(GL_POLYGON);
    glVertex3f(-5.0, 0.0, 0.0);
    glVertex3f(-5.0, 3.0, 0.0);
    glVertex3f(-5.0, 4.5, -1.5);
    glVertex3f(-5.0, 3.0, -3.0);
    glVertex3f(-5.0, 0.0, -3.0);
    glEnd();    
    glBegin(GL_POLYGON);
    glVertex3f(-10.0, 0.0, 0.0);
    glVertex3f(-10.0, 3.0, 0.0);
    glVertex3f(-10.0, 4.5, -1.5);
    glVertex3f(-10.0, 3.0, -3.0);
    glVertex3f(-10.0, 0.0, -3.0);
    glEnd();
    glColor3f(0.6, 0.6, 0.6);       
    glTranslatef(0.0, 0.0, -3.0);
    glRectf(-10.0, 0.0, -5.0, 3.0);
    glTranslatef(0.0, 0.0, 3.0);
    glColor3f(0.8392, 0.3490, 0.0431);
    glBegin(GL_POLYGON);
    glVertex3f(-4.6, 2.5, 0.5);
    glVertex3f(-4.6, 4.5, -1.5);
    glVertex3f(-10.4, 4.5, -1.5);
    glVertex3f(-10.4, 2.5, 0.5);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex3f(-4.6, 4.5, -1.5);
    glVertex3f(-4.6, 2.5, -3.5);
    glVertex3f(-10.4, 2.5, -3.5);
    glVertex3f(-10.4, 4.5, -1.5);
    glEnd();
    glColor3f(0.2, 0.5, 0.7);
    glTranslatef(-2.99, 0.0, -0.9);
    glBegin(GL_POLYGON);
    glVertex3f(-2.0, 0.0, 0.0);
    glVertex3f(-2.0, 2.0, 0.0);
    glVertex3f(-2.0, 2.0, -1.0);
    glVertex3f(-2.0, 0.0, -1.0);
    glEnd();
    glColor3f(0.2, 0.5, 0.7);
    glTranslatef(0.001, -0.3, 0.4);
    glRotatef(90.0, 0.0, 1.0, 0.0);
    glTranslatef(5.49, -0.3, -3.25);
    glBegin(GL_POLYGON);
    glVertex3f(-6.0, 1.5, 0.0);
    glVertex3f(-6.0, 2.5, 0.0);
    glVertex3f(-6.0, 2.5, -3.0);
    glVertex3f(-6.0, 1.5, -3.0);
    glEnd();
    glPopMatrix();
}

void drawRoadCircle(float xm, float zm, float rm) {
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
    for (theta = 0; theta < 360; theta++) 
        glVertex3f(xm + (rm * cos(theta * PI / 180)), 0.02, zm + (rm * sin(theta * PI / 180)));
    glEnd();
}

void drawRoad() {
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex3f(1.75, 0.01, -120.3);
    glVertex3f(-3.5, 0.01, -120.3);
    glVertex3f(-3.5, 0.01, -0.2);
    glVertex3f(1.75, 0.01, -0.2);
    glEnd();
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_QUADS);
    glVertex3f(1.75, 0.01, -120.3);
    glVertex3f(2.3, 0.01, -120.3);
    glVertex3f(2.3, 0.01, -0.2);
    glVertex3f(1.75, 0.01, -0.2);
    glEnd();
    glColor3f(0.3, 0.3, 0.3);
    glBegin(GL_QUADS);
    glVertex3f(-4.05, 0.01, -120.3);
    glVertex3f(-3.5, 0.01, -120.3);
    glVertex3f(-3.5, 0.01, -0.2);
    glVertex3f(-4.05, 0.01, -0.2);
    glEnd();
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(-1.10, 0.02, -119);
    glVertex3f(-1.17, 0.02, -119);
    glVertex3f(-1.17, 0.02, -0.1);
    glVertex3f(-1.10, 0.02, -0.1);
    glEnd();
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_QUADS);
    glVertex3f(-0.9, 0.02, -119.0);
    glVertex3f(-0.82, 0.02, -119.0);
    glVertex3f(-0.82, 0.02, -0.0);
    glVertex3f(-0.9, 0.02, -0.0);
    glEnd();
}

void extendRoad() {
    glPushMatrix();
    glPushMatrix();
    glTranslatef(7.5, 0.0, -129.5);
    glRotatef(-90.0, 0.0, 1.0, 0.0);
    glPopMatrix();
    drawRoadCircle(137.0, 9.0, 10.0);
    drawRoadCircle(137.0, -129.0, 10.0);
    glPushMatrix();
    glTranslatef(137.0, 0.0, 0.0);
    drawRoad();
    glPopMatrix();
    glPopMatrix();
}

void computePos(float deltaMove) {
    x += deltaMove * lx * 0.1;
    z += deltaMove * lz * 0.1;
}

void computeDir(float deltaAngle) {
    angle += deltaAngle;
    lx = sin(angle);
    lz = -cos(angle);
}

void display() {    //the main display function
    if (deltaMove)  computePos(deltaMove);
    if (deltaAngle) computeDir(deltaAngle);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.5, 0.5, 1.0, 1.0);
    glLoadIdentity();
    gluLookAt(x, camHeight, z, x + lx, camHeight, z + lz, 0.0, camHeight, 0.0);
    glColor3f(0.0, 0.5, 0.0);
    
    glBegin(GL_QUADS); //terrain co-ordinates
    glVertex3f(-100.0, 0.0, 100.0);
    glVertex3f(-100.0, 0.0, -175.0);
    glVertex3f(200.0, 0.0, -175.0);
    glVertex3f(200.0, 0.0, 100.0);
    glEnd();
    glColor3f(0.0, 0.0, 1.0);
    amusementpark();
    amwall();
    //Code for 8 houses
    glPushMatrix();
    glTranslatef(140.0, 0.0, -7.0);
    drawHouse2();
    glTranslatef(0.0, 0.0, -10.0);
    drawHouse2();
    glTranslatef(0.0, 0.0, -10.0);
    drawHouse2();
    glTranslatef(0.0, 0.0, -10.0);
    drawHouse2();
    glTranslatef(0.0, 0.0, -10.0);
    drawHouse2();
    glTranslatef(0.0, 0.0, -10.0);
    drawHouse2();
    glTranslatef(0.0, 0.0, -10.0);
    drawHouse2();
    glRotatef(-90, 0.0, 1.0, 0.0);
    glPopMatrix();
    theSun();
    extendRoad();
    drawSea();
    lightingInit();
    glutPostRedisplay();
    glutSwapBuffers();
}

void keyboardmenu(unsigned char key,int x,int y) {
    if ((int)key == 27) exit(0);
    switch (key) {
    case 'u': camHeight += 0.2; break;
    case 'd': if (camHeight > 0.3) camHeight -= 0.2; break; //cam-height
    }
}

void pressKey(int key, int xx, int yy) {
    switch (key) {
    case GLUT_KEY_UP: deltaMove = 5 * 0.05 * 5; break;
    case GLUT_KEY_DOWN: deltaMove = 5 * -0.05 * 5; break;
    case GLUT_KEY_LEFT: deltaAngle = -0.005 *2; break;
    case GLUT_KEY_RIGHT: deltaAngle = 0.005 * 2; break;
    }
}

void releaseKey(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_UP:
    case GLUT_KEY_DOWN: deltaMove = 0.0; break;
    case GLUT_KEY_LEFT:
    case GLUT_KEY_RIGHT:deltaAngle = 0.0; break;
    }
}

int main(int argc, char** argv) {
    char cont;
    printf("Instructions:\n\t1.Use Arrow keys to move.\n\t2.Use 'u' to go up.\n\t3.Use 'd' to come down\n\t4.Click right mouse button to vary speed\n\t5.Press 'ESC' to quit.\n");
    printf("Press ENTER to continue");
    scanf_s("%c", &cont);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(1024, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("The OpenWorld");
    glutDisplayFunc(display);
    glutReshapeFunc(myReshape);
    glutKeyboardFunc(keyboardmenu);
    glutSpecialFunc(pressKey);
    glutSpecialUpFunc(releaseKey);
    glutCreateMenu(rotatemenu);
    glutAddMenuEntry("Start Rotation", 1);
    glutAddMenuEntry("Speed Rotation", 2);
    glutAddMenuEntry("Stop Rotation", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutFullScreen();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glutMainLoop();
}