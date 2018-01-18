#include <windows.h>
#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;

struct Color
{
	GLfloat r;
	GLfloat g;
	GLfloat b;
};


void init()
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glOrtho(-50.0, 55.0, -50.0, 50.0, -1.0, 1.0);
}

void putpixel(double  x, double  y, Color color)
{
	glColor3f(color.r, color.g, color.b);
	glBegin(GL_POINTS);
		glVertex2i(x, y);
	glEnd();
	glFlush();
}

void draw()
{
	   glClear(GL_COLOR_BUFFER_BIT);
	   glColor3f(1.0, 1.0, 1.0);
	   glBegin(GL_POLYGON);
	   glVertex3f (0, 0, 0.0);
	   glVertex3f (0, 25, 0.0);
	   glVertex3f (25, 25, 0.0);
       glVertex3f (25, 0, 0.0);
	   glEnd();
	   glFlush();
}





void floodFill(float  x, float y, Color oldColor, Color newColor)
{
	Color color;
	glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, &color);
	if(color.r == oldColor.r && color.g == oldColor.g && color.b == oldColor.b)
	{
		putpixel(x, y,  newColor);
		floodFill(x+1, y, oldColor, newColor);
		floodFill(x, y+1, oldColor, newColor);
		floodFill(x-1, y, oldColor, newColor);
		floodFill(x, y-1, oldColor, newColor);
	}
	return;
}


void display()
{
    draw();
    Color newColor = {1.0f, 0.0f, 0.0f};
	Color oldColor = {1.0f, 1.0f, 1.0f};

	floodFill(0, 0, oldColor, newColor);
}


int main (int argc, char **argv)
{
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
