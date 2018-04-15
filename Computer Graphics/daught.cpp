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
		glBegin(GL_LINES);{
			glVertex3f( 100,0,0);
			glVertex3f(-100,0,0);

			glVertex3f(0,-100,0);
			glVertex3f(0, 100,0);

			glVertex3f(0,0, 100);
			glVertex3f(0,0,-100);
		}glEnd();
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

void display()
{
          glClear(GL_COLOR_BUFFER_BIT);
          drawAxes();
          DrawSphere();
          DrawCone();
          /*
          glBegin(GL_QUADS);
          glColor3f(1, 0, 0);
          glVertex3f(3, -3, -3);
          glVertex3f(3,  3, -3);
          glVertex3f(-3,  3, -3);
          glVertex3f(-3, -3, -3 );
          glEnd();

          glBegin(GL_QUADS);
          glColor3f(1,  1, 1);
          glVertex3f( 3, -3, 3 );
          glVertex3f( 3,  3, 3 );
          glVertex3f(-3,  3, 3);
          glVertex3f(-3, -3, 3);
          glEnd();


          glBegin(GL_QUADS);
          glColor3f(1,  0,  1);
          glVertex3f( 3, -3, -3);
          glVertex3f( 3,  3, -3);
          glVertex3f( 3,  3,  3);
          glVertex3f( 3, -3,  3 );
          glEnd();


          glBegin(GL_QUADS);
          glColor3f(0,  1,  0);
          glVertex3f( -3,  -3,  3 );
          glVertex3f( -3,  3, 3 );
          glVertex3f( -3,  3, -3 );
          glVertex3f( -3, -3, -3 );
          glEnd();


          glBegin(GL_QUADS);
          glColor3f(0,  0,  1);
          glVertex3f(  3,  3,  3 );
          glVertex3f(  3,  3, -3 );
          glVertex3f( -3,  3, -3 );
          glVertex3f( -3,  3,  3 );
          glEnd();


          glBegin(GL_QUADS);
          glColor3f( 1,  0,  0);
          glVertex3f(  3, -3, -3 );
          glVertex3f(  3, -3,  3 );
          glVertex3f( -3, -3,  3 );
          glVertex3f( -3, -3, -3 );
          glEnd();

          */
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
                glScalef( 2.0, 2.0, 0.0 );
                break;

            case GLUT_KEY_PAGE_DOWN:
                glScalef(0.5, 0.5, 0.0);
                break;
        }
        display();
}


int main(int argc, char** argv)
{
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
        glutInitWindowSize(600, 600);
        glutCreateWindow("3d Cube");
        init();
        glutDisplayFunc(display);
        glutSpecialFunc(keyboard);
        glutMainLoop();
        return 0;
}




/*
static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double a = t*90.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);

    glPushMatrix();
        glTranslated(-2.4,1.2,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutSolidSphere(1,slices,stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0,1.2,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutSolidCone(1,1,slices,stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(2.4,1.2,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutSolidTorus(0.2,0.8,slices,stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(-2.4,-1.2,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutWireSphere(1,slices,stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0,-1.2,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutWireCone(1,1,slices,stacks);
    glPopMatrix();

    glPushMatrix();
        glTranslated(2.4,-1.2,-6);
        glRotated(60,1,0,0);
        glRotated(a,0,0,1);
        glutWireTorus(0.2,0.8,slices,stacks);
    glPopMatrix();

    glutSwapBuffers();
}
*/
