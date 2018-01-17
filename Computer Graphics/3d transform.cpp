#include<bits/stdc++.h>
#include <windows.h>
#include <GL\glut.h>



void init()
{
          glClearColor(0,0,0,0);
          glMatrixMode(GL_PROJECTION);
          glOrtho(-15,15,-15,15,-15,15);
}



void DrawCube()
{
        glClear(GL_COLOR_BUFFER_BIT);

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
        DrawCube();
}


int main(int argc, char** argv)
{
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
        glutInitWindowSize(600, 600);
        glutCreateWindow("3d Cube");
        init();
        glutDisplayFunc(DrawCube);
        glutSpecialFunc(keyboard);
        glutMainLoop();
        return 0;
}
//Reference : https://www.wikihow.com/Make-a-Cube-in-OpenGL
