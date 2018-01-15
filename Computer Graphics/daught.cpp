#include <bits/stdc++.h>
#include <windows.h>
#include <GL/glut.h>
using namespace std;

int xa[10], ya[10];

int   tx, ty, line=6;

double angle, rx, ry,  sx, sy;


void draw()
{
        xa[0] = 200; ya[0] = 300;
        xa[1] = 300; ya[1] = 300;

        xa[2] = 300; ya[2] = 300;
        xa[3] = 300; ya[3] = 400;

        xa[4] = 300; ya[4] = 400;
        xa[5] = 200; ya[5] = 300;


     glBegin(GL_LINES);

     glColor3f(1.0, 0.0, 0.0);



	for(int i=0; i<6;  i++)
	{
		glVertex2i(xa[i], ya[i]);
	}

		glEnd();
       glFlush();


/*
     glBegin(GL_LINES);

     glColor3f(1.0, 0.0, 0.0);
                    glVertex2i (200, 300);
                    glVertex2i (300, 300);

                    glVertex2i (300, 300);
                    glVertex2i (300, 400);

                    glVertex2i (300, 400);
                    glVertex2i (200, 300);


	glEnd();
    glFlush();
    */

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
	// Rotation(rx, ry,angle);

	 glFlush ();
}

int main(int argc, char** argv)
{
    /*
        xa[1] = 200; ya[1] = 200;

        xa[2] = 300; ya[2] = 300;

        xa[3] = 300; xa[3] = 300;

        xa[4] = 400; ya[4] = 200;

        xa[5] = 400; ya[5] = 200;

        xa[6] = 200; ya[6] = 200;
*/


        //tx=150,  ty=150;
        //sx =0.5, sy=1.5;
        //rx = 300, ry=300, angle=50;

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
