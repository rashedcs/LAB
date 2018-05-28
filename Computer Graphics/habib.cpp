#include <windows.h>
#include<bits/stdc++.h>
#include <GL/glut.h>

#define pi  3.14159

double cameraHeight;
double cameraAngle;
double angle;

int drawaxes;

double var=0;


void drawAxes()
{
	if(drawaxes==1)
	{
		glBegin(GL_LINES);{
		    glColor3f(1.0, 0, 0);
			glVertex3f( 100,0,0);
			glVertex3f(-100,0,0);

			glColor3f(1.0, 1.0, 1.0);
			glVertex3f(0,-100,0);
			glVertex3f(0, 100,0);

            glColor3f(1.0, 1.0, 1.0);
			glVertex3f(0,0, 100);
			glVertex3f(0,0,-100);
		}glEnd();
	}
}

void drawSquare(double a)
{
	glBegin(GL_POLYGON);
		glVertex3f( a, a,0);
		glVertex3f( a,-a,0);
		glVertex3f(-a,-a,0);
		glVertex3f(-a, a,0);
	glEnd();
}



void DrawSphere()
{
    glColor3f(1,0,0);
    glPushMatrix();
        glTranslated(2,0,0);
        glRotated(20,1,0,0);
        glRotated(40,0,0,1);
        glutSolidSphere(8,10,10);
    glPopMatrix();
}



void display()
{

	/********************  clean the display  ********************/
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0,0,0,0);	//color black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	/********************  set-up camera here  ********************/
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(200*cos(cameraAngle), 200*sin(cameraAngle), cameraHeight, 0,0,0,	0,0,1);
	glMatrixMode(GL_MODELVIEW);



	/********************  add object ********************/
	drawAxes();
    DrawSphere();


	glutSwapBuffers();
}


void animate()
{
	angle+=0.05;
	glutPostRedisplay();
}

void init()
{
   	/************************ initialize variable ********************/
	drawaxes=1;
	cameraHeight=80.0;
	cameraAngle=1.0;
	angle=0;
	glClearColor(0,0,0,0);


	/************************ set-up projection here ********************/
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80,	1,	1,	1000.0);
}


void specialKeyListener(int key, int x,int y)
{
	switch(key)
	{
		case GLUT_KEY_DOWN:
			cameraHeight -= 3.0;
			break;
		case GLUT_KEY_UP:
			cameraHeight += 3.0;
			break;

		case GLUT_KEY_RIGHT:
			cameraAngle += 0.03;
			break;
		case GLUT_KEY_LEFT:
			cameraAngle -= 0.03;
			break;

		case GLUT_KEY_HOME:
			break;

		default:
			break;
	}
}



int main(int argc, char **argv)
{
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
	glutCreateWindow("Lab 1");

    init();
	glutDisplayFunc(display);
	glutIdleFunc(animate);
	glutSpecialFunc(specialKeyListener);

	glutMainLoop();

	return 0;
}
