//Roll:140140
//Name:Ridwanul Islam"
//#include <windows.h>
#include <math.h>
#include <GL/glut.h>

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT); //glClear — clear buffers to preset values
	glColor3f(1.0, 1.0, 1.0);

        glBegin(GL_LINES);
        glVertex3f (-40, 20, 0.0);
        glVertex3f (-20, 40, 0.0);
        glEnd();

        glBegin(GL_LINES);
       glVertex3f (-10, 20, 0.0);
        glVertex3f (-30, 20, 0.0);
        glVertex3f (-30, 20, 0.0);
        glVertex3f (-10, 40, 0.0);
        glVertex3f (-10, 40, 0.0);
        glVertex3f (-10, 20, 0.0);
        glEnd();


        glBegin(GL_LINES);
       glVertex3f  (00, 20, 0.0);
        glVertex3f (20, 20, 0.0);
        glVertex3f (20, 20, 0.0);
        glVertex3f (20, 40, 0.0);
         glVertex3f (20, 40, 0.0);
        glVertex3f (00, 40, 0.0);
        glVertex3f (00, 40, 0.0);
         glVertex3f  (00, 20, 0.0);
        glEnd();


         glBegin(GL_LINES);
       glVertex3f  (30, 40, 0.0);
        glVertex3f (45, 40, 0.0);
        glVertex3f (45, 40, 0.0);
        glVertex3f (40, 35, 0.0);
         glVertex3f (40,35,0.0);
        glVertex3f (25, 35, 0.0);
        glVertex3f (25, 35, 0.0);
         glVertex3f (30, 40, 0.0);

         glVertex3f  (30, 25, 0.0);
        glVertex3f (45, 25, 0.0);
        glVertex3f (45, 25, 0.0);
        glVertex3f (40, 20, 0.0);
         glVertex3f (40,20,0.0);
        glVertex3f (25, 20, 0.0);
        glVertex3f (25, 20, 0.0);
         glVertex3f (30, 25, 0.0);


        glVertex3f (25, 35, 0.0);
        glVertex3f (25, 20, 0.0);
        glVertex3f (30, 40, 0.0);
        glVertex3f (30, 25, 0.0);



        glVertex3f (45, 40, 0.0);
        glVertex3f (45, 25, 0.0);
        glVertex3f (40, 35, 0.0);
        glVertex3f (40, 20, 0.0);

        glEnd();


        glBegin(GL_LINE_LOOP);
	for(int ii = 0; ii < 300; ii++)
	{
		float theta = 2.0f * 3.1415926f * float(ii) / float(300); //curr angle

		float x = 10 * cosf(theta);
		float y =  10* sinf(theta);//calculate the y component

		glVertex2f(x -30, y + 0);//output vertex

	}
	glEnd();

   // glutSolidSphere( 5.0, 20.0, 2.0);

	//glPopMatrix();
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
    glutInitWindowPosition(100, 150);
    glutCreateWindow("Roll:140140 Ridwanul Islam");
    glutDisplayFunc(display);

    init();
    glutMainLoop();
    return 0;
}
