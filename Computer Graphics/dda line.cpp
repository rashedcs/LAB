#include <GL/gl.h>
#include <GL/glut.h>
#include<bits/stdc++.h>

int x1, y1, x2, y2, dx, dy, step;

void display()
{
    glClear (GL_COLOR_BUFFER_BIT);

    dx = x2-x1;
    dy = y2-y1;

    int xIncrement, yIncrement, x = x1, y = y1;

    if(abs(dx)>abs(dy))
    {
       step = abs(dx);
    }
    else
    {
       step = abs(dy);
    }

    xIncrement = dx /  step;
    yIncrement = dy /  step;

    glColor3f (1.0, 0.0, 0.0);
    glBegin(GL_POINTS);
    glVertex2d(x, y);

    for (int k=0; k<step; k++)
    {
       x += xIncrement;
       y += yIncrement;
       glVertex2d(x, y);
    }
    glEnd();

    glFlush ();
}

void init()
{
    /* select clearing (background) color */
    glClearColor (0.0, 0.0, 0.0, 0.0);
    /* initialize viewing values */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 500, 0, 600);

}

int main(int argc, char** argv)
{
    printf("Enter first Point\n");
    scanf("%d", &x1);
    scanf("%d", &y1);

    printf("Enter End Point \n");
    scanf("%d", &x2);
    scanf("%d", &y2);

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("hello");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0; /* ISO C requires main to return int. */
}
