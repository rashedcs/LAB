/** Name : Md. Rashedul Islam    Roll   : 150135  **/
#include<windows.h>
#include<GL/glut.h>
#include<bits/stdc++.h>



void init()
{
          glClearColor(0,0,0,0);
          glMatrixMode(GL_PROJECTION);
	  glOrtho(-50, 50, -50, 50, -50, 50);
}

void drawCube(GLfloat baseX, GLfloat baseY, GLfloat baseZ,GLfloat l, GLfloat w, GLfloat h, GLfloat r, GLfloat g, GLfloat b)
{
    glBegin(GL_QUADS);
	
     ///Front
    glColor3f(r, g, b);
    glVertex3f(baseX,baseY,baseZ);
    glVertex3f(baseX+l,baseY,baseZ);
    glVertex3f(baseX+l,baseY+h,baseZ);
    glVertex3f(baseX,baseY+h,baseZ);

     /// Back
    glColor3f(r, g, b);
    glVertex3f(baseX,baseY,baseZ+w);
    glVertex3f(baseX+l,baseY,baseZ+w);
    glVertex3f(baseX+l,baseY+h,baseZ+w);
    glVertex3f(baseX,baseY+h,baseZ+w);

     /// Left
    glColor3f(r, g, b);
    glVertex3f(baseX,baseY,baseZ);
    glVertex3f(baseX,baseY,baseZ+w);
    glVertex3f(baseX,baseY+h,baseZ+w);
    glVertex3f(baseX,baseY+h,baseZ);


    /// Right
    glColor3f(r, g, b);
    glVertex3f(baseX+l,baseY,baseZ);
    glVertex3f(baseX+l,baseY,baseZ+w);
    glVertex3f(baseX+l,baseY+h,baseZ+w);
    glVertex3f(baseX+l,baseY+h,baseZ);

    /// Bottom
    glColor3f(r, g, b);
    glVertex3f(baseX,baseY,baseZ);
    glVertex3f(baseX+l,baseY,baseZ);
    glVertex3f(baseX+l,baseY,baseZ+w);
    glVertex3f(baseX,baseY,baseZ+w);

    ///Top
    glColor3f(r, g, b);
    glVertex3f(baseX,baseY+h,baseZ);
    glVertex3f(baseX+l,baseY+h,baseZ);
    glVertex3f(baseX+l,baseY+h,baseZ+w);
    glVertex3f(baseX,baseY+h,baseZ+w);
	
    glEnd();
}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    drawCube(0.0, 0.0, 0.0, 1.0, 1.0, 5.0, 0.0,0.0,1.0);
    drawCube(4.0, 0.0, 0.0, 1.0, 1.0, 5.0, 0.0,1.0,1.0);
    drawCube(4.0, 0.0, 4.0, 1.0, 1.0, 5.0, 1.0,0.0,0.0);
    drawCube(0.0, 0.0, 4.0, 1.0, 1.0, 5.0, 0.0,1.0,0.0);
    drawCube(0.0, 5.0, 0.0, 5.0, 5.0, 1.0, 1.0,1.0,0.0);
    drawCube(0.0, 6.0, 0.0, 1.0, 5.0, 5.0, 1.0,0.5,0.5);
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
