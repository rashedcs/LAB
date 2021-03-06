#include<bits/stdc++.h>
#include <windows.h>
#include <math.h>
#include <GL\glut.h>


void display()
{
                    glClear(GL_COLOR_BUFFER_BIT); //clear buffers to preset values
                    glColor3f(1.0, 0.0, 0.0);    //figure color


                    glBegin(GL_POLYGON);
                    glVertex2i (250, 300);
                    glVertex2i (450, 300);

                    glVertex2i (450, 300);
                    glVertex2i (450, 500);

                    glVertex2i (450, 500);
                    glVertex2i (250, 500);

                    glVertex2i (250, 500);
                    glVertex2i (250, 300);
                    glEnd();


                    glBegin(GL_LINES);
                    glVertex2i (50, 100);
                    glVertex2i (250, 100);

                    glVertex2i (250, 100);
                    glVertex2i (250, 300);

                    glVertex2i (250, 300);
                    glVertex2i (50, 300);

                    glVertex2i (50, 300);
                    glVertex2i (50, 100);
                    glEnd();

                    glFlush();
}


void init(void)
{
    glClearColor (0.0, 0.0, 0.0, 0.0);     //terminal background color
    glMatrixMode(GL_PROJECTION);          //2d coordinates mode
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);  //2d coordinates mode
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
