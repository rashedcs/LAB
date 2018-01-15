#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>


void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //glScalef(2.0, 2.0, 2.0);
    // start drawing
    // draw the seat

    glRotatef(30.0, 0.0, 1.0, 0.0);
    glColor3f(0.654, 0.258, 0.1259);
    glBegin(GL_POLYGON);

    glVertex3f(5.0, 5.0, 5.0);
    glVertex3f(10.0, 5.0, 5.0);
    glVertex3f(10.0, 5.0, 10.0);
    glVertex3f(5.0, 5.0, 10.0);

    glVertex3f(5.0, 4.5, 5.0);
    glVertex3f(10.0, 4.5, 5.0);
    glVertex3f(10.0, 4.5, 10.0);
    glVertex3f(5.0, 4.5, 5.0);

    glVertex3f(5.0, 5.0, 5.0);
    glVertex3f(5.0, 4.5, 5.0);
    glVertex3f(10.0, 4.5, 5.0);
    glVertex3f(10.0, 5.0, 5.0);

    glVertex3f(5.0, 5.0, 10.0);
    glVertex3f(5.0, 4.5, 10.0);
    glVertex3f(10.0, 4.5, 10.0);
    glVertex3f(10.0, 5.0, 10.0);

    glVertex3f(5.0, 5.0, 10.0);
    glVertex3f(5.0, 4.5, 10.0);
    glVertex3f(5.0, 4.5, 5.0);
    glVertex3f(5.0, 5.0, 5.0);

    glVertex3f(10.0, 5.0, 10.0);
    glVertex3f(10.0, 5.0, 5.0);
    glVertex3f(10.0, 4.5, 5.0);
    glVertex3f(10.0, 4.5, 10.0);

    glEnd();

    // draw the front left leg
    glColor3f(0.125, 0.855, 0.125);
    glBegin(GL_POLYGON);

    glVertex3f(5.5, 4.5, 5.0);
    glVertex3f(5.0, 4.5, 5.0);
    glVertex3f(5.0, -0.5, 5.0);
    glVertex3f(5.5, -0.5, 5.0);

    glVertex3f(5.0, 4.5, 5.5);
    glVertex3f(5.5, 4.5, 5.5);
    glVertex3f(5.5, -0.5, 5.5);
    glVertex3f(5.0, -0.5, 5.5);

    glVertex3f(5.0, 4.5, 5.0);
    glVertex3f(5.0, 4.5, 5.5);
    glVertex3f(5.0, -0.5, 5.5);
    glVertex3f(5.0, -0.5, 5.0);

    glVertex3f(5.5, 4.5, 5.5);
    glVertex3f(5.5, 4.5, 5.0);
    glVertex3f(5.5, -0.5, 5.0);
    glVertex3f(5.5, -0.5, 5.5);

    glVertex3f(5.5, -0.5, 5.0);
    glVertex3f(5.0, -0.5, 5.0);
    glVertex3f(5.0, -0.5, 5.5);
    glVertex3f(5.5, -0.5, 5.5);



    glEnd();

    // draw front right leg
    glColor3f(0.125, 0.855, 0.125);
    glBegin(GL_POLYGON);

    glVertex3f(10.0, 4.5, 5.0);
    glVertex3f(9.5, 4.5, 5.0);
    glVertex3f(9.5, -0.5, 5.0);
    glVertex3f(10.0, -0.5, 5.0);

    glVertex3f(10.0, 4.5, 5.5);
    glVertex3f(10.0, -0.5, 5.5);
    glVertex3f(9.5, -0.5, 5.5);
    glVertex3f(9.5, 4.5, 5.5);

    glVertex3f(9.5, 4.5, 5.0);
    glVertex3f(9.5, 4.5, 5.5);
    glVertex3f(9.5, -0.5, 5.5);
    glVertex3f(9.5, -0.5, 5.0);

    glVertex3f(10.0, -0.5, 5.5);
    glVertex3f(10.0, -0.5, 5.0);
    glVertex3f(9.5, -0.5, 5.0);
    glVertex3f(9.5, -0.5, 5.5);

    glEnd();

    // back left leg
    glColor3f(0.125, 0.855, 0.125);
    glBegin(GL_POLYGON);

    glVertex3f(5.0, 4.5, 9.5);
    glVertex3f(5.0, 4.5, 10.0);
    glVertex3f(5.0, -0.5, 10.0);
    glVertex3f(5.0, -0.5, 9.5);

    glVertex3f(5.5, 4.5, 9.5);
    glVertex3f(5.5, -0.5, 9.5);
    glVertex3f(5.5, -0.5, 10.0);
    glVertex3f(5.5, 4.5, 10.0);

    glVertex3f(5.5, 4.5, 9.5);
    glVertex3f(5.0, 4.5, 9.5);
    glVertex3f(5.0, -0.5, 9.5);
    glVertex3f(5.5, -0.5, 9.5);

    glVertex3f(5.0, 4.5, 10.0);
    glVertex3f(5.5, 4.5, 10.0);
    glVertex3f(5.5, -0.5, 10.0);
    glVertex3f(5.5, -0.5, 10.0);

    glVertex3f(5.0, -0.5, 10.0);
    glVertex3f(5.5, -0.5, 10);
    glVertex3f(5.5, -0.5, 9.5);
    glVertex3f(5.0, -0.5, 9.5);

    glEnd();

    // draw back right leg
    glColor3f(0.125, 0.855, 0.125);
    glBegin(GL_POLYGON);

    glVertex3f(10.0, 4.5, 9.5);
    glVertex3f(9.5, 4.5, 9.5);
    glVertex3f(9.5, -0.5, 9.5);
    glVertex3f(10.0, -0.5, 9.5);

    glVertex3f(9.5, 4.5, 10.0);
    glVertex3f(10.0, 4.5, 10.0);
    glVertex3f(10.0, -0.5, 10.0);
    glVertex3f(9.5, -0.5, 10.0);

    glVertex3f(9.5, 4.5, 9.5);
    glVertex3f(9.5, 4.5, 10.0);
    glVertex3f(9.5, -0.5, 10.0);
    glVertex3f(10.0, -0.5, 10.0);

    glEnd();


    // draw back seat of the chair
    glColor3f(0.125, 0.55, 0.625);
    glBegin(GL_POLYGON);

    glVertex3f(10.0, 10.0, 9.5);
    glVertex3f(5.0, 10.0, 9.5);
    glVertex3f(5.0, 5.0, 9.5);
    glVertex3f(10.0, 5.0, 9.5);

    glVertex3f(5.0, 10.0, 10.0);
    glVertex3f(10.0, 10.0, 10.0);
    glVertex3f(10.0, 5.0, 10.0);
    glVertex3f(5.0, 5.0, 10.0);

    glVertex3f(5.0, 10.0, 9.5);
    glVertex3f(5.0, 10.0, 10.0);
    glVertex3f(5.0, 5.0, 10.0);
    glVertex3f(5.0, 5.0, 9.5);

    glVertex3f(10.0, 10.0, 10.0);
    glVertex3f(10.0, 10.0, 9.5);
    glVertex3f(10.0, 5.0, 9.5);
    glVertex3f(10.0, 5.0, 10.0);

    glEnd();
    glFlush();
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
    glutCreateWindow("Chair");
    init();
    glEnable(GL_DEPTH_TEST);
    glutDisplayFunc(display); // place the rendering function
    glutMainLoop();
    return 0;
}
