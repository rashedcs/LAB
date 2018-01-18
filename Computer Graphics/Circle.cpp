//1st Method :

#include <windows.h>
#include <bits/stdc++.h>
#include <GL\glut.h>



void display(void)
{
         glClear(GL_COLOR_BUFFER_BIT);
	     glColor3f(1.0, 0.0, 0.0);

	     float rx, ry, x=10, y=10;

         glBegin(GL_POINTS);
         //glBegin(GL_LINES);
         for (float angle=0; angle<360;  angle+=1.0)
         {
               float rad_angle = angle * 3.14 / 180;
                rx = x+10 * sin((double)rad_angle);
                ry = y+10 * cos((double)rad_angle);
                glVertex3f (rx, ry, 0);
         }
         glEnd();

	    glFlush();
}


void init()
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

    glutCreateWindow("Circle");

    glutDisplayFunc(display);


    init();

    glutMainLoop();

    return 0;

}

