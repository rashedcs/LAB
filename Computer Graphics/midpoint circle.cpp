#include<bits/stdc++.h>
#include<windows.h>
#include <GL/glu.h>
#include <GL/glut.h>


int xCenter,  yCenter,   radius;


void putpixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x+xCenter,  y+yCenter);
	glEnd();
}


void display()
{
        glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 0.0, 0.0);
	glPointSize(1.0);

	int   x=0, y = radius;
	float  p = 1 - radius;

        glBegin(GL_POINTS);
	glVertex2i(x+xCenter, y+yCenter);
	glEnd();

        while(x<y)
	{
		if(p<0)
		{
			p += 2*x+1;
		}
		else
		{
			y--;
			p += 2*(x-y)+1;
		}
		putpixel(x, y);
		putpixel(x, -y);
		putpixel(-x, y);
		putpixel(-x, -y);
		putpixel(y, x);
		putpixel(-y, x);
		putpixel(y, -x);
		putpixel(-y, -x);
		
         	x++;
	}
        glFlush ();
}


void init()
{
      glClearColor(1.0, 1.0, 1.0, 1.0);
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluOrtho2D(0, 500, 0, 600);
      glPointSize(1.0);
}


int main(int argc, char** argv)
{
     xCenter=250;
     yCenter=250;
     radius=150;

     glutInit(&argc, argv);
     glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
     glutInitWindowSize (500, 500);
     glutInitWindowPosition (100, 100);
     glutCreateWindow ("Circle");
     init ();
     glutDisplayFunc(display);
     glutMainLoop();
	
     return 0;
}
