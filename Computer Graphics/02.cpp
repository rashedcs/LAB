#include<windows.h>
#include<GL/glut.h>
#include<bits/stdc++.h>



void init()
{
          glClearColor(0,0,0,0);
          glMatrixMode(GL_PROJECTION);
          glOrtho(-15,15,-15,15,-15,15);
}


void drawAxes()
{
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);
		{
		    glColor3f(1, 1, 0);
			glVertex3f( 15,0,0);
			glVertex3f(-15,0,0);

			glColor3f(1, 0, 1.);
			glVertex3f(0,-15,0);
			glVertex3f(0, 15,0);

            glColor3f(1, 1, 1);
			glVertex3f(0,0, 15);
			glVertex3f(0,0,-15);
		}
		glEnd();
}


void drawCylinder(double radius, double height, double segments)
{
    struct point points[100];

    for(int i=0; i<=segments; i++)
    {
        points[i].x=radius*cos(((double)i/(double)segments)*2*3.1416);
        points[i].z=radius*sin(((double)i/(double)segments)*2*3.1416);
    }

    for(int i=0;i<segments;i++)
    {
        glColor3f(1, 0, 1);
        glBegin(GL_POLYGON);
        {
            glVertex3f(points[i].x,-radius,points[i].z);
			glVertex3f(points[i].x,radius,points[i].z);
			glVertex3f(points[i+1].x,radius,points[i+1].z);
			glVertex3f(points[i+1].x,-radius,points[i+1].z);
        }
        glEnd();
    }
}


void drawCylinder(double radius, double height, double segments)
{
    for(int i=0; i<segments; i++)
    {
        glBegin(GL_LINES);
        {
            glColor3f(1,0,0);

            double x = radius*cos(((double)i/(double)segments)*2*3.1416);
            double y = radius*sin(((double)i/(double)segments)*2*3.1416);

            double  fx = radius*cos(((double)(1+i)/(double)segments+1)*2*3.1416);
            double  fy = radius*sin(((double)(1+i)/(double)segments+1)*2*3.1416);

            glVertex3f(x, y, 0);
            glVertex3f(x, y, height);

             glVertex3f(x, y, 0);
	         glVertex3f(fx, fy, 0);

	        glVertex3f(x, y, height);
            glVertex3f(fx, fy, height);
        }
        glEnd();
    }
}

void DrawCone()
{
    glColor3f(1,0,1);
    glPushMatrix();
        glTranslated(-8,6,6);
        glRotated(60,1,0,0);
        glRotated(60,0,0,1);
        glutSolidCone(5,5,16,16);
    glPopMatrix();
}


void DrawSphere()
{
    glColor3f(1,0,0);
    glPushMatrix();
        glTranslated(+8,-6,-6);
        glRotated(60,1,0,0);
        glRotated(90,0,0,1);
        glutSolidSphere(3,16,16);
    glPopMatrix();
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
          drawAxes();
          drawCylinder(2,2,70);
          DrawSphere();
          DrawCone();
     glutSwapBuffers();
}


void specialKeys(unsigned char key, int x, int y)
{
    switch(key)
    {
        case 'd':
            glRotatef(10, 1, 0, 0);
            break;
        case 'a':
            glRotatef(-10, 1, 0, 0);
            break;
        case 'w':
            glRotatef(10, 0, 1, 0);
            break;
        case 's':
            glRotatef(-10, 0, 1, 0);
            break;
        case 'x':
            glRotatef(10, 0, 0, 1);
            break;

        case 'z':
            glRotatef(-10, 0, 0, 1);
            break;

        case 't':
            glTranslatef(2.0, 0, 0);
            break;

        case '+':
            glScalef(2.0f, 2.0f, 2.0f);
            break;

        case '-':
            glScalef(0.75f, 0.75f, 0.75f);
            break;

        case 'l':
            glLoadIdentity();
            break;
    }
}




int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("3D Chair");

    init();

    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutKeyboardFunc(specialKeys);
    glutMainLoop();

    return 0;
}
