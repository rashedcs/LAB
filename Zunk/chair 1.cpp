#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#define degree 2*M_PI/360.0

void drawCube(GLfloat baseX, GLfloat baseY, GLfloat baseZ,GLfloat l, GLfloat w, GLfloat h, GLfloat r, GLfloat g, GLfloat b){
    glBegin(GL_QUADS);
    //Front
    glColor3f(r, g, b);
    glVertex3f(baseX,baseY,baseZ);
    glVertex3f(baseX+l,baseY,baseZ);
    glVertex3f(baseX+l,baseY+h,baseZ);
    glVertex3f(baseX,baseY+h,baseZ);

    // Back
    glColor3f(r, g, b);
    glVertex3f(baseX,baseY,baseZ+w);
    glVertex3f(baseX+l,baseY,baseZ+w);
    glVertex3f(baseX+l,baseY+h,baseZ+w);
    glVertex3f(baseX,baseY+h,baseZ+w);

    // Left
    glColor3f(r, g, b);
    glVertex3f(baseX,baseY,baseZ);
    glVertex3f(baseX,baseY,baseZ+w);
    glVertex3f(baseX,baseY+h,baseZ+w);
    glVertex3f(baseX,baseY+h,baseZ);

    // Right
    glColor3f(r, g, b);
    glVertex3f(baseX+l,baseY,baseZ);
    glVertex3f(baseX+l,baseY,baseZ+w);
    glVertex3f(baseX+l,baseY+h,baseZ+w);
    glVertex3f(baseX+l,baseY+h,baseZ);

    // Bottom
    glColor3f(r, g, b);
    glVertex3f(baseX,baseY,baseZ);
    glVertex3f(baseX+l,baseY,baseZ);
    glVertex3f(baseX+l,baseY,baseZ+w);
    glVertex3f(baseX,baseY,baseZ+w);

    // Top
    glColor3f(r, g, b);
    glVertex3f(baseX,baseY+h,baseZ);
    glVertex3f(baseX+l,baseY+h,baseZ);
    glVertex3f(baseX+l,baseY+h,baseZ+w);
    glVertex3f(baseX,baseY+h,baseZ+w);

    glEnd();
}
void nKeys(unsigned char key, int x, int y)
{
    switch(key)
    {
    case 27:
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

    drawCube(0.0f, 0.0f, 0.0f, 1.0f, 1.0f, 5.0f, 0.0f,0.0f,1.0f);
    drawCube(4.0f, 0.0f, 0.0f, 1.0f, 1.0f, 5.0f, 0.0f,1.0f,1.0f);
    drawCube(4.0f, 0.0f, 4.0f, 1.0f, 1.0f, 5.0f, 1.0f,0.0f,0.0f);
    drawCube(0.0f, 0.0f, 4.0f, 1.0f, 1.0f, 5.0f, 0.0f,1.0f,0.0f);
    drawCube(0.0f, 5.0f, 0.0f, 5.0f, 5.0f, 1.0f, 1.0f,1.0f,0.0f);
    drawCube(0.0f, 6.0f, 0.0f, 1.0f, 5.0f, 5.0f, 1.0f,0.5f,0.5f);

    glutSwapBuffers();
}

void init()
{
    glClearColor(0, 0, 0, 0);
	glViewport(0, 0, 500, 500);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50, 50, -50, 50, -50, 50);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(0, 0);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Room");
    init();
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutKeyboardFunc(nKeys);
    glutMainLoop();
    return 0;
}
