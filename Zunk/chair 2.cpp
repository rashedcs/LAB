#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#define degree 2*M_PI/360.0

void drawCube(GLfloat X, GLfloat Y, GLfloat Z,GLfloat l, GLfloat w, GLfloat h, GLfloat r, GLfloat g, GLfloat b)
{
    glBegin(GL_QUADS);
    //Front
    glColor3f(r, g, b);
    glVertex3f(X,Y,Z);
    glVertex3f(X+l,Y,Z);
    glVertex3f(X+l,Y+h,Z);
    glVertex3f(X,Y+h,Z);

    // Back
    glColor3f(r, g, b);
    glVertex3f(X,Y,Z+w);
    glVertex3f(X+l,Y,Z+w);
    glVertex3f(X+l,Y+h,Z+w);
    glVertex3f(X,Y+h,Z+w);

    // Left
    glColor3f(r, g, b);
    glVertex3f(X,Y,Z);
    glVertex3f(X,Y,Z+w);
    glVertex3f(X,Y+h,Z+w);
    glVertex3f(X,Y+h,Z);

    // Right
    glColor3f(r, g, b);
    glVertex3f(X+l,Y,Z);
    glVertex3f(X+l,Y,Z+w);
    glVertex3f(X+l,Y+h,Z+w);
    glVertex3f(X+l,Y+h,Z);

    // Bottom
    glColor3f(r, g, b);
    glVertex3f(X,Y,Z);
    glVertex3f(X+l,Y,Z);
    glVertex3f(X+l,Y,Z+w);
    glVertex3f(X,Y,Z+w);

    // Top
    glColor3f(r, g, b);
    glVertex3f(X,Y+h,Z);
    glVertex3f(X+l,Y+h,Z);
    glVertex3f(X+l,Y+h,Z+w);
    glVertex3f(X,Y+h,Z+w);

    glEnd();
}
void Keys(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 'e':
        exit(0);
        break;
    case 'd':
        glRotatef(30*degree, 1, 0, 0);
        break;
    case 'a':
        glRotatef(-30*degree, 1, 0, 0);
        break;
    case 'w':
        glRotatef(30*degree, 0, 1, 0);
        break;
    case 's':
        glRotatef(-30*degree, 0, 1, 0);
        break;
    case 'x':
        glRotatef(30*degree, 0, 0, 1);
        break;
    case 'z':
        glRotatef(-30*degree, 0, 0, 1);
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

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    drawCube(0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 7.0f, 0.0f,0.0f,1.0f);
    drawCube(6.0f, 0.0f, 0.0f, 1.0f, 1.0f, 7.0f, 0.0f,1.0f,1.0f);
    drawCube(6.0f, 0.0f, 6.0f, 1.0f, 1.0f, 7.0f, 1.0f,0.0f,0.0f);
    drawCube(0.0f, 0.0f, 6.0f, 1.0f, 1.0f, 7.0f, 0.0f,1.0f,0.0f);
    drawCube(0.0f, 7.0f, 0.0f, 7.0f, 7.0f, 1.0f, 1.0f,1.0f,0.0f);
    drawCube(0.0f, 7.0f, 0.0f, 1.0f, 7.0f, 7.0f, 1.0f,0.5f,0.5f);

    /*drawCube(10.0f, 0.0f, 10.0f, 1.0f, 1.0f, 10.0f, 0.0f,0.0f,1.0f);
    drawCube(18.90f, 0.0f, 10.0f, 1.0f, 1.0f, 10.0f, 0.0f,1.0f,1.0f);
    drawCube(18.90f, 0.0f, 15.0f, 1.0f, 1.0f, 10.0f, 1.0f,0.0f,0.0f);
    drawCube(10.0f, 0.0f, 15.0f, 1.0f, 1.0f, 10.0f, 0.0f,1.0f,0.0f);
    drawCube(10.0f, 10.0f, 10.0f, 10.0f, 6.0f, 1.0f, 1.0f,1.0f,0.0f);
    drawCube(10.0f, 10.0f, 10.0f, 1.0f, 6.0f, 6.0f, 1.0f,0.5f,0.5f);*/

    glutSwapBuffers();
}

void init()
{
    //glClearColor(0, 0, 0, 0);
	glViewport(0, 0, 400, 400);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-70, 70, -70, 70, -70, 70);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(600, 600);
    glutCreateWindow("Room");
    init();
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutKeyboardFunc(Keys);
    glutMainLoop();

    return 0;
}
