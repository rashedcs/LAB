#include <GL/glu.h>
#include <GL/glut.h>
#include<bits/stdc++.h>

int xa, ya,  xb,  yb;

void display()
{
        glClear (GL_COLOR_BUFFER_BIT);

	int dx = xb-xa, dy=yb-ya, steps;
	float xIncrement, yIncrement, x = xa, y = ya;
	
	if(abs (dx) > abs (dy)) steps = abs (dx);
	else                    steps = abs (dy);
	
	xIncrement = dx / (float) steps;
	yIncrement = dy / (float) steps;

        glColor3f (1.0, 0.0, 0.0);
        glBegin(GL_POINTS);
	glVertex2d(x, y);

	for(int k=0; k<steps; k++)
	{
	  x += xIncrement;
	  y += yIncrement;
	  glVertex2d(x, y);
	}
	
    	glEnd();
   	glFlush ();
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
    printf("Enter first Point\n");
    scanf("%d", &xa);
    scanf("%d", &ya);

    printf("Enter End Point \n");
    scanf("%d", &xb);
    scanf("%d", &yb);
	
   /*Jodi input user theke newa possible na hoy 	
   xa=200;
   ya=200;
   xb=200;
   yb=400;
   */


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
