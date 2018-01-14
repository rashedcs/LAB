#include<windows.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include<bits/stdc++.h>

int xa, ya,  xb,  yb;

void display()
{
        int dx = abs (xa - xb), dy = abs (ya - yb), p = 2 * dy - dx;
        int twoDy = 2 * dy,  twoDyDx = 2 *(dy - dx), x, y, xEnd;

	if(xa > xb)
	{
	  x = xb;
	  y = yb;
	  xEnd = xa;
	}
	else
	{
	  x = xa;
	  y = ya;
	  xEnd = xb;
	}

        glColor3f (1.0, 0.0, 0.0);
        glBegin(GL_POINTS);
	glVertex2d(x, y);

	while(x<xEnd)
	{
		x++;
		if(p < 0)
                {
                   p += twoDy;
                }
		else
		{
		  y++;
		  p += twoDyDx;
		}
		glVertex2d(x, y);
	}
}

void init()
{
    /* select clearing (background) color */
    glClearColor (0.0, 0.0, 0.0, 0.0);
    /* initialize viewing values */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 600);
}


int main(int argc, char** argv)
{
   /*Jodi input user theke newa possible na hoy 
    printf("Enter first Point\n");
    scanf("%d", &xa);
    scanf("%d", &ya);

    printf("Enter End Point \n");
    scanf("%d", &xb);
    scanf("%d", &yb);
   */	
   	
    xa=200;
    ya=200;
    xb=400;
    yb=200;
   


    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("hello");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0; 
}

