
#include <GL/glut.h>
//#include<window.h>

void display(void)
{
/*	clear all pixels  */
	glClear(GL_COLOR_BUFFER_BIT);

/*	draw white polygon (rectangle) with corners at
 *	(0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
 */
	glColor3f (1.0, 0.0, 0.0);

	glBegin(GL_POLYGON);
      glVertex3f (1, 1, 0.0);
      glVertex3f (-1, 1, 0.0);
      glVertex3f (-1, -1, 0.0);
      glVertex3f (1, -1, 0.0);
	glEnd();
	//printf("mist");
/* don't wait!
 * start processing buffered OpenGL routines
 */
   glFlush();
}

void init (void)
{
/* select clearing color 	*/
   glClearColor (0.0, 0.0, 0.0, 0.0);

/* initialize viewing values  */
   //glLoadIdentity();
   glOrtho(-2, 2, -2, 2, -2, 2);
}

/*
 * Declare initial window size, position, and display mode
 * (single buffer and RGBA).  Open window with "hello"
 * in its title bar.  Call initialization routines.
 * Register callback function to display graphics.
 * Enter main loop and process events.
 */

//Main program
int main(int argc, char **argv) 
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);  //Mode for later glutCreateWindow() call
   glutInitWindowSize (350, 350);
   glutInitWindowPosition (100, 100);
   glutCreateWindow("Our first drawing In OpenGL");
   init();

   glutDisplayFunc(display);
   glutMainLoop();
   return 0;
}
