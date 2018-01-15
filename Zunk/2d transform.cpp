#include <bits/stdc++.h>
#include <windows.h>
#include <GL/glut.h>
using namespace std;

int xa[10], ya[10];

int   tx, ty, line=3;

double angle, rx, ry,  sx, sy;


void draw()
{
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	for(int i=0; i<line;  i++)
	{
		glVertex2i(xa[i], ya[i]);
	}
	glEnd();
}



void Translation(int x, int y)
{
	glBegin(GL_POLYGON);
	for(int i=0; i<line; i++)
	{
		glVertex2i(xa[i]+x,  ya[i] + y);
	}
	glEnd();
}

void Scalation(double x, double y)
{
	glBegin(GL_POLYGON);
	for(int i=0; i<line; i++)
	{
		glVertex2i(xa[i]*x,  ya[i] * y);
	}
	glEnd();
}

void Rotation(double rx, double ry, double angle)
{
	glBegin(GL_POLYGON);

    double t = angle*(3.14/180);
	for(int i=0; i<line; i++)
	{
        xa[i] = rx + (xa[i] - rx) * cos (t) - (ya[i] - ry) * sin (t);
        ya[i] = ry + (xa[i] - rx) * sin (t) + (ya[i]- ry) * cos (t);
		glVertex2i(xa[i],  ya[i]);
	}

	glEnd();
}


void init ()
{
    glClearColor (0.0, 0.0, 0.0, 0.0);     //terminal background color
    glMatrixMode(GL_PROJECTION);          //2d coordinates mode
    gluOrtho2D(0.0, 600.0, 0.0, 600.0);  //2d coordinates mode
}


void display()
{
	      glClear (GL_COLOR_BUFFER_BIT);
	      glColor3f (0.0, 0.0, 0.0);

	      //draw();
	      //Translation(tx, ty);

	      //draw();
	      //Scalion(sx, sy);

          draw();
	      Rotation(rx, ry,angle);

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

     //tx=150,  ty=150;
     //sx =0.5, sy=1.5;
       rx = 300, ry=300, angle=50;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //
    glutInitWindowSize(755,450);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Lab 2");
    glutDisplayFunc(display);
    init();

    glutMainLoop();
    return 0;
}
