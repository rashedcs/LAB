/** Md. Rashedul Islam   ID : 150135 **/
#include<bits/stdc++.h>
#include <windows.h>
#include <GL\glut.h>


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


double xpoint(double x, int seg)
{

}


void drawCylinder(double radius, double height, double segments)
{
    double shade;

    for(int i=0;i<segments;i++)
    {
        glBegin(GL_LINES);
        {
           // if(i<segments/2)shade=2*(double)i/(double)segments;
          //  else shade=2*(1.0-(double)i/(double)segments);

            double x = radius*cos(((double)i/(double)segments)*2*3.1416);
            double y = radius*sin(((double)i/(double)segments)*2*3.1416);

            double  fx = radius*cos(((double)(1+i)/(double)segments+1)*2*3.1416);
            double fy = radius*sin(((double)(1+i)/(double)segments+1)*2*3.1416);

            glColor3f(1,0,0);
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

void display()
{
      glClear(GL_COLOR_BUFFER_BIT);
          drawAxes();
         DrawSphere();
         DrawCone();
          drawCylinder(5,5,100);
       glFlush();
}


void keyboard(int key, int x, int y)
{
        switch(key)
        {
            case GLUT_KEY_UP:
                glRotatef(3,1,0,0);
                break;

            case GLUT_KEY_DOWN:
                glRotatef(-3,1,0,0);
                break;

            case GLUT_KEY_LEFT:
                glRotatef(3,0,1,0);
                break;

            case GLUT_KEY_RIGHT:
                glRotatef(-3,0,1,0);
                break;

            case GLUT_KEY_PAGE_UP:
                glScalef(1.5, 1.5, 0.0 );
                break;

            case GLUT_KEY_PAGE_DOWN:
                glScalef(0.75, 0.75, 0.0);
                break;
        }
        display();
}


int main(int argc, char** argv)
{
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
        glutInitWindowSize(600, 600);
        glutCreateWindow("Lab 2");
        init();
        glutDisplayFunc(display);
        glutSpecialFunc(keyboard);
        glutMainLoop();
        return 0;
}
