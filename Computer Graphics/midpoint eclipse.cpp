#include<bits/stdc++.h>
#include<windows.h>
#include <GL/glu.h>
#include <GL/glut.h>


int xc,yc,x,y;
float p;
long rx,ry;


void putpixel(int x, int y)
{
    	glPointSize(3.0);
	glBegin(GL_POINTS);
	glVertex2i(x,  y);
	glEnd();
}


void display()
{
	glClear (GL_COLOR_BUFFER_BIT);
	glColor3f (1.0, 0.0, 0.0);


	p=ry*ry-rx*rx*ry+rx*rx/4;
	x=0;y=ry;

        while(2.0*ry*ry*x <= 2.0*rx*rx*y)
        {
	    if(p < 0)
	    {
	      x++;
	      p = p+2*ry*ry*x+ry*ry;
	    }
	    else
	    {
	      x++;y--;
	      p = p+2*ry*ry*x-2*rx*rx*y-ry*ry;
	    }
	    putpixel(xc+x,yc+y);
	    putpixel(xc+x,yc-y);
	    putpixel(xc-x,yc+y);
	    putpixel(xc-x,yc-y);
        }

  	//Region 2
        p=ry*ry*(x+0.5)*(x+0.5)+rx*rx*(y-1)*(y-1)-rx*rx*ry*ry;
        while(y > 0)
        {  
            if(p <= 0)
            {
                x++;y--;
                p = p+2*ry*ry*x-2*rx*rx*y+rx*rx;
            }
            else
            {
                y--;
                p = p-2*rx*rx*y+rx*rx;
            }
            putpixel(xc+x,yc+y);
            putpixel(xc+x,yc-y);
            putpixel(xc-x,yc+y);
            putpixel(xc-x,yc-y);
        }
       glFlush ();
}


void init()
{
      glClearColor(1.0, 1.0, 1.0, 1.0);
      glMatrixMode(GL_PROJECTION);
      glLoadIdentity();
      gluOrtho2D(0, 500, 0, 600);
}


int main(int argc, char** argv)
{
     xc=200;
     yc=200;
     rx=10;
     ry=20;

     glutInit(&argc, argv);
     glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
     glutInitWindowSize (600, 600);
     glutInitWindowPosition (100, 100);
     glutCreateWindow ("Eclipse");
     init ();
     glutDisplayFunc(display);
     glutMainLoop();

     return 0;
}
