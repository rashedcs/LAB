#include <bits/stdc++.h>
#include <windows.h>
#include <GL/glut.h>
using namespace std;

int  choice = 0, edges=3;

int xa[10];
int ya[10];


int transX, transY;
double scaleX, scaleY;


void drawPolygon()
{
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	for(int i=0; i<3;  i++)
	{
		glVertex2i(xa[i], ya[i]);
	}
	glEnd();
}



void drawPolygonTrans(int x, int y)
{
	glBegin(GL_POLYGON);
	for(int i=0; i<3; i++)
	{
		glVertex2i(xa[i] + x, ya[i] + y);
	}
	glEnd();
}

void drawPolygonScale(double x, double y)
{
	glBegin(GL_POLYGON);
	for(int i = 0; i < edges; i++)
	{
		glVertex2i(xa[i]*x,  ya[i] * y);
	}
	glEnd();
}


void myInit ()
{
    glClearColor (0.0, 0.0, 0.0, 0.0);     //terminal background color
    glMatrixMode(GL_PROJECTION);          //2d coordinates mode
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);  //2d coordinates mode
}


void myDisplay()
{
	    glClear (GL_COLOR_BUFFER_BIT);
	    glColor3f (0.0, 0.0, 0.0);

		drawPolygon();
		drawPolygonTrans(transX, transY);

		//drawPolygon();
		//drawPolygonScale(scaleX, scaleY);

	    glFlush ();
}

int main(int argc, char** argv)
{

     xa[0] = 200;
     ya[0] = 200;
     xa[1] = 300;
     ya[1] = 300;
     xa[2] = 400;
     ya[2] = 200;

    transX=150,  transY=150;

    //scaleY >> scaleX;


	glutInit(&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (640, 480);
	glutInitWindowPosition (100, 150);
	glutCreateWindow ("Basic Transformations");
	glutDisplayFunc(myDisplay);
	myInit ();
	glutMainLoop();

}
