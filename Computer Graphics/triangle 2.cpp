#include<bits/stdc++.h>
#include <windows.h>
#include <math.h>
#include <GL\glut.h>


void display()
{
	   glClear(GL_COLOR_BUFFER_BIT);
	   glColor3f(1.0, 0.0, 0.0);

	   glBegin(GL_LINES);
	   glVertex3f (-10, 20, 0.0);
	   glVertex3f (-30, 20, 0.0);
	   glVertex3f (-30, 20, 0.0);
	   glVertex3f (-10, 40, 0.0);
	   glVertex3f (-10, 40, 0.0);
	   glVertex3f (-10, 20, 0.0);
	   glEnd();
	
	  /*
	            glVertex2i (200, 200);
                    glVertex2i (300, 300);

                    glVertex2i (300, 300);
                    glVertex2i (400, 200);

                    glVertex2i (400, 200);
                    glVertex2i (200, 200);
         */

	   glBegin(GL_TRIANGLES);
	   glVertex3f (0, 10, 0.0);
	   glVertex3f (-10, -10, 0.0);
	   glVertex3f (10, -10, 0.0);
	   glEnd();
	   glFlush();
}


void init(void)
{
	glClearColor (0.0, 0.0, 0.0, 0.0);
	glOrtho(-50.0, 55.0, -50.0, 50.0, -1.0, 1.0);
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
