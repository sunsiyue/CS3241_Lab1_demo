// CS3241Lab1.cpp : Defines the entry point for the console application.
#include <cmath>
#include <iostream>

/* header files for xcode */
#include <OpenGL/gl.h>
#include <GLUT/GLUT.h>

/* header files for lab machine */
//#include "GL\glut.h"

using namespace std;

GLfloat PI = 3.14;
float alpha = 0.0, k=1;
float tx = 0.0, ty=0.0;




void drawLine(void) {
    glBegin(GL_LINE);
    glVertex2f(3, 3);
    glVertex2f(3, -3);
    glEnd();
}


void drawArc(double cx, double cy, float r,
             int startDeg, int endDeg, int thickness)
{
    int i;
    glColor3f(0,0,0);
    
    glLineWidth(thickness);
    glBegin(GL_LINE_STRIP);
    for(i=startDeg;i<=endDeg;i++)
        glVertex2f(cx+r*sin(2.0*M_PI*i/360.0),
                   cy+r*cos(2.0*M_PI*i/360.0));
    glEnd();
}

void drawArcOval(double cx, double cy, float Rwidth, float Rheight
            , int startDeg, int endDeg, int thichness)
{
    int i;
    glColor3f(0,0,0);
    
    glLineWidth(thichness);
    glBegin(GL_LINE_STRIP);
    for(i=startDeg;i<=endDeg;i++)
        glVertex2f(cx+Rwidth*sin(2.0*M_PI*i/360.0),
                   cy+Rheight*cos(2.0*M_PI*i/360.0));
    glEnd();
}

void drawCirclePlate(double r) {
    
    int i;
    glBegin(GL_POLYGON);
    
    glColor3f(0.0, 0.0, 0.0);
    for(i=0;i<50;i++)
        glVertex2f(r*sin(2.0*M_PI*i/50.0),
                   r*cos(2.0*M_PI*i/50.0));
    
    
    glEnd();
    
}



void drawCirclePlateYello(double r) {
    
    int i;
    glBegin(GL_POLYGON);
    
    glColor3f(1, 0.89, 0.8);
    for(i=0;i<50;i++)
        glVertex2f(r*sin(2.0*M_PI*i/50.0),
                   r*cos(2.0*M_PI*i/50.0));
    
    
    glEnd();
    
}


void drawOvalPlate(double widthR, double heightR) {
    int i;
    glBegin(GL_POLYGON);
    
    glColor3f(0.0, 0.0, 0.0);
    for(i=0;i<50;i++)
        glVertex2f(widthR*sin(2.0*M_PI*i/50.0),
                   heightR*cos(2.0*M_PI*i/50.0));
    
    
    glEnd();
}


void drawOvalPlateYellow(double widthR, double heightR) {
    int i;
    glBegin(GL_POLYGON);
    
    glColor3f(1, 0.89, 0.8);
    for(i=0;i<50;i++)
        glVertex2f(widthR*sin(2.0*M_PI*i/50.0),
                   heightR*cos(2.0*M_PI*i/50.0));
    
    
    glEnd();
}

void display(void)
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
    
	glPushMatrix();
    
	//controls transformation
	glScalef(k, k, k);
		
	glRotatef(alpha, 0, 0, 1);
	glTranslatef(tx, ty, 0);
	//draw your stuff here
    
    //drawCirclePlate(3.0);
    
    drawOvalPlate(6, 6.5);
    
    glTranslatef(6,6,0);
    
    drawOvalPlate(4,4);
    
    glTranslatef(-12,0,0);
    
    drawOvalPlate(4,4);
    
    glTranslatef(6, -6, 0);
    

    drawCirclePlateYello(2.4);
    
    glTranslatef(1.6, 1.6, 0);
    
    drawCirclePlateYello(3);
    
    glTranslatef(-3.2, 0, 0);
    
    drawCirclePlateYello(3);
    
    glTranslatef(1.6, -1, 0);
    
    glTranslatef(0, -3, 0);
    
    drawOvalPlateYellow(6.4, 3.2);
    
    //eyes
    
    drawArcOval(0, 0, 6.4, 3.4, 45, 315, 20);
    
    drawArcOval(0, 1.4, 2, 0.8, -70, 70, 13);
    
    drawArcOval(1.2, 3.7, 0.8, 1.8, -160, 175, 7);

    drawArcOval(-1.2, 3.7, 0.8, 1.8, -175, 160, 7);
    
    glTranslatef(1, 3, 0);
    
    drawOvalPlate(0.4, 0.8);
    
    glTranslatef(-2, 0, 0);
    
    drawOvalPlate(0.4, 0.8);
    
    glTranslatef(1, -3, 0);
    
    //nose
    
    glTranslatef(0, 0.8, 0);
    
    drawOvalPlate(1.6, 1);
    
    //mouse
    
    drawArc(0, 4, 6, 130, 230, 7);
    
    drawArc(3, -1, 2, 20, 90, 5);
    
    drawArc(-3, -1, 2, -90, -20, 5);
    
    drawArc(0, -1.2, 2, 107, 253, 7);
    
    drawArc(0, -3.6, 1.2, -60, 60, 5);
    
    


    //drawArc(0,0,10,0,360,7);
//    drawArc(3,2,2,-90,90);
//    drawArc(-3,2,2,-90,90);
//    drawArc(0,-2,4,90,270);

    

    
	glPopMatrix();
	glFlush ();
}





void reshape(int w, int h)
{
	glViewport (0, 0, (GLsizei) w, (GLsizei) h);
    
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
    
	glOrtho(-10, 10, -10, 10, -10, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void init(void)
{
	glClearColor (1.0, 1.0, 1.0, 1.0);
	glShadeModel (GL_SMOOTH);
}



void keyboard (unsigned char key, int x, int y)
{
	//keys to control scaling - k
	//keys to control rotation - alpha
	//keys to control translation - tx, ty
	switch (key) {
            
		case 'a':
			alpha+=10;
			glutPostRedisplay();
            break;
            
		case 'd':
			alpha-=10;
			glutPostRedisplay();
            break;
            
		case 'q':
			k+=0.1;
			glutPostRedisplay();
            break;
            
		case 'e':
			if(k>0.1)
				k-=0.1;
			glutPostRedisplay();
            break;
            
		case 'z':
			tx-=0.1;
			glutPostRedisplay();
            break;
            
		case 'c':
			tx+=0.1;
			glutPostRedisplay();
            break;
            
		case 's':
			ty-=0.1;
			glutPostRedisplay();
            break;
            
		case 'w':
			ty+=0.1;
			glutPostRedisplay();
            break;
            
		default:
            break;
	}
}

int main(int argc, char **argv)
{
	cout<<"CS3241 Lab 1\n\n";
	cout<<"+++++CONTROL BUTTONS+++++++\n\n";
	cout<<"Scale Up/Down: Q/E\n";
	cout<<"Rotate Clockwise/Counter-clockwise: A/D\n";
	cout<<"Move Up/Down: W/S\n";
	cout<<"Move Left/Right: Z/C\n";
    
	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize (600, 600);
	glutInitWindowPosition (50, 50);
	glutCreateWindow (argv[0]);
	init ();
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	//glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutMainLoop();
    
	return 0;
}
