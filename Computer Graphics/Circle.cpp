#include <windows.h>
#include <math.h>
#include <GL\glut.h>



void display()
{
        glClear(GL_COLOR_BUFFER_BIT);
	
	     /* 1st Method */
              glColor3f(1.0, 0.0, 1.0);
              double xc=10, yc=10, rx, ry, rad_angle ;
              glBegin(GL_POINTS); //glBegin(GL_LINES);  //glBegin(GL_LINE_LOOP);
              for(double angle=0; angle<360;  angle+=1.0)
              {
                    rad_angle = angle * 3.14 / 180;
                    rx = 10 * sin(rad_angle);
                    ry = 10 * cos(rad_angle);
                    glVertex3f (xc+rx, yc+ry, 0);
              }
              glEnd();

	
              /* 2nd Method */
              glColor3f(1.0, 1.0, 0.0);
              float cx=20, cy=20, r=10, num=100,  theta, x, y;
              glBegin(GL_LINE_LOOP);
              for (int i= 0; i<num; i++)
              {
                 theta = 2.0* 3.1415926 * float(i) / float(num);
                 x = r * cosf(theta);
                 y = r * sinf(theta);
                 glVertex2f(x + cx, y + cy);
              }
              glEnd();
	
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

    glutInitWindowPosition(100, 100);

    glutCreateWindow("Circle");

    glutDisplayFunc(display);


    init();

    glutMainLoop();

    return 0;

}
//glBegin(GL_LINE_LOOP) is better for both way
