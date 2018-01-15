
#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<cmath>
/* Global variables */
char title[] = "3D Shapes";
void specialKeys();
float light_diffuse[] = {1.0, 1.0, 1.0,1.0};
float light_position[] = {1.0, 1.0, 1.0,1.0};
static int slices = 16;
static int stacks = 16;
// ----------------------------------------------------------
// Global Variables
// ----------------------------------------------------------
double rotate_y=0;
double rotate_x=0;
double rotate_a=0;
double rotate_b=0;
double rotate_c=0;
double rotate_d=0;
double rotate_p=0;
double rotate_q=0;



///for the tors

GLdouble innerRadius=0.2;
GLdouble outerRadius=0.8;
GLint sides =50;
GLint rings =50;



/* Initialize OpenGL Graphics */
void initGL() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClearDepth(1.0f);                   // Set background depth to farthest
   glEnable(GL_DEPTH_TEST);   // Enable depth testing for z-culling
   glDepthFunc(GL_LEQUAL);    // Set the type of depth-test
   glShadeModel(GL_SMOOTH);   // Enable smooth shading
   glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);  // Nice perspective corrections
}

/* Handler for window-repaint event. Called back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Clear color and depth buffers
   glMatrixMode(GL_MODELVIEW);     // To operate on model-view matrix

glLoadIdentity();                 // Reset the model-view matrix



        glTranslated(-1.5f,1.0f,-6.0f);
  glRotatef( rotate_c, 1.0, 0.0, 0.0 );
  glRotatef( rotate_d, 0.0, 1.0, 0.0 );
       // glutWireSphere(.6,slices,stacks);
           glColor3f(0.0, 1.0, 0.0);
          glutWireTorus(innerRadius,outerRadius,sides,rings);



glLoadIdentity();                 // Reset the model-view matrix
   glTranslatef(-1.0f,3.0f,-.7);  // Move right and into the screen
  glRotatef( rotate_a, 1.0, 0.0, 0.0 );
  glRotatef( rotate_b, 0.0, 1.0, 0.0 );
 glBegin(GL_LINES);
   glColor3f(1.0,0.0,1.0);

  glVertex3f(0.0f, 0.0f, 0.0f);
  glVertex3f(1.0f, 1.0f,1.0f);
glEnd();
   glEnd();               // Begi
   // Render a color-cube consisting of 6 quads with different colors
   glLoadIdentity();                 // Reset the model-view matrix
   glTranslatef(2.0f, -1.5f, -7.0f);  // Move right and into the screen
  glRotatef( rotate_a, 1.0, 0.0, 0.0 );
  glRotatef( rotate_b, 0.0, 1.0, 0.0 );
   glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
      // Top face (y = 1.0f)
      // Define vertices in counter-clockwise (CCW) order with normal pointing out
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f( .5f, .5f, -.5f);
      glVertex3f(-.5f, .5f, -.5f);
      glVertex3f(-.5f, .5f,  .5f);
      glVertex3f( .5f, .5f,  .5f);

      // Bottom face (y = -1.0f)
      glColor3f(1.0f, 0.5f, 0.0f);     // Orange
      glVertex3f( .5f, -.5f,  .5f);
      glVertex3f(-.5f, -.5f,  .5f);
      glVertex3f(-.5f, -.5f, -.5f);
      glVertex3f( .5f, -.5f, -.5f);

      // Front face  (z = 1.0f)
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( .5f,  .5f, .5f);
      glVertex3f(-.5f,  .5f, .5f);
      glVertex3f(-.5f, -.5f, .5f);
      glVertex3f( .5f, -.5f, .5f);

      // Back face (z = -1.0f)
      glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
      glVertex3f( .5f, -.5f, -.5f);
      glVertex3f(-.5f, -.5f, -.5f);
      glVertex3f(-.5f,  .5f, -.5f);
      glVertex3f( .5f,  .5f, -.5f);

      // Left face (x = -1.0f)
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(-.5f,  .5f,  .5f);
      glVertex3f(-.5f,  .5f, -.5f);
      glVertex3f(-.5f, -.5f, -.5f);
      glVertex3f(-.5f, -.5f,  .5f);

      // Right face (x = 1.0f)
      glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
      glVertex3f(.5f,  .5f, -.5f);
      glVertex3f(.5f,  .5f,  .5f);
      glVertex3f(.5f, -.5f,  .5f);
      glVertex3f(.5f, -.5f, -.5f);
   glEnd();  // End of drawing color-cube

   // Render a pyramid consists of 4 triangles
   glLoadIdentity();                  // Reset the model-view matrix
   glTranslatef(-1.5f, -1.0f, -6.0f);  // Move left and into the screen
  glRotatef( rotate_x, 1.0, 0.0, 0.0 );
  glRotatef( rotate_y, 0.0, 1.0, 0.0 );
 /// glScaled(1,1,2);
   glBegin(GL_TRIANGLES);           // Begin drawing the pyramid with 4 triangles
      // Front
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 0.0f, .6f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(-.6f, -.6f, .6f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(.6f, -.6f, .6f);

      // Right
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f(0.0f, .6f, 0.0f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(.6f, -.6f, .6f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(.6f, -.6f, -.6f);

      // Back
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f(0.0f, .6f, 0.0f);
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f(.6f, -.6f, -.6f);
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(-.6f, -.6f, -.6f);

      // Left
      glColor3f(1.0f,0.0f,0.0f);       // Red
      glVertex3f( 0.0f, .6f, 0.0f);
      glColor3f(0.0f,0.0f,1.0f);       // Blue
      glVertex3f(-.6f,-.6f,-.6f);
      glColor3f(0.0f,1.0f,0.0f);       // Green
      glVertex3f(-.6f,-.6f, .6f);
   glEnd();   // Done drawing the pyramid



///rectangle
glLoadIdentity();
             // Reset the model-view matrix
   glTranslatef(2.0f, 1.5f, -7.0f);  // Move right and into the screen
  glRotatef( rotate_p, 1.0, 0.0, 0.0 );
  glRotatef( rotate_q, 0.0, 1.0, 0.0 );
  glScaled(2,1,2);
    glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
      // Top face (y = 1.0f)
      // Define vertices in counter-clockwise (CCW) order with normal pointing out
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f( .5f, .5f, -.5f);
      glVertex3f(-.5f, .5f, -.5f);
      glVertex3f(-.5f, .5f,  .5f);
      glVertex3f( .5f, .5f,  .5f);

      // Bottom face (y = -1.0f)
      glColor3f(1.0f, 0.5f, 0.0f);     // Orange
      glVertex3f( .5f, -.5f,  .5f);
      glVertex3f(-.5f, -.5f,  .5f);
      glVertex3f(-.5f, -.5f, -.5f);
      glVertex3f( .5f, -.5f, -.5f);

      // Front face  (z = 1.0f)
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( .5f,  .5f, .5f);
      glVertex3f(-.5f,  .5f, .5f);
      glVertex3f(-.5f, -.5f, .5f);
      glVertex3f( .5f, -.5f, .5f);

      // Back face (z = -1.0f)
      glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
      glVertex3f( .5f, -.5f, -.5f);
      glVertex3f(-.5f, -.5f, -.5f);
      glVertex3f(-.5f,  .5f, -.5f);
      glVertex3f( .5f,  .5f, -.5f);

      // Left face (x = -1.0f)
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(-.5f,  .5f,  .5f);
      glVertex3f(-.5f,  .5f, -.5f);
      glVertex3f(-.5f, -.5f, -.5f);
      glVertex3f(-.5f, -.5f,  .5f);

      // Right face (x = 1.0f)
      glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
      glVertex3f(.5f,  .5f, -.5f);
      glVertex3f(.5f,  .5f,  .5f);
      glVertex3f(.5f, -.5f,  .5f);
      glVertex3f(.5f, -.5f, -.5f);
   glEnd();  // End of drawing color-cube

/*

 glLoadIdentity();                 // Reset the model-view matrix
   glTranslatef(-1.0f, 1.0f, -8.0f);  // Move right and into the screen


    glutSolidSphere( 1.0,  20,  20);

*/
/*
 glBegin(GL_POINTS);
 for(int i=0;i<1000;++i)
  {
  glVertex3f(cos(2*3.14159*i/1000.0),sin(2*3.14159*i/1000.0),0);
  }
 glEnd();
 */
   glutSwapBuffers();  // Swap the front and back frame buffers (double buffering)

}

/* Handler for window re-size event. Called back when the window first appears and
   whenever the window is re-sized with its new width and height */
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;



   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);

   // Set the aspect ratio of the clipping volume to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset
   // Enable perspective projection with fovy, aspect, zNear and zFar
   gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

void specialKeys( int key, int x, int y ) {

  //  Right arrow - increase rotation by 5 degree
  if (key == GLUT_KEY_RIGHT)
    rotate_y += 5;

  //  Left arrow - decrease rotation by 5 degree
  else if (key == GLUT_KEY_LEFT)
    rotate_y -= 5;

  else if (key == GLUT_KEY_UP)
    rotate_x += 5;

  else if (key == GLUT_KEY_DOWN)
    rotate_x -= 5;



  //  Request display update
  glutPostRedisplay();

}

void windowKey(unsigned char key,int x,int y)
{
  /*  Exit on ESC */
  if (key =='b')
     rotate_b += 5;
  else if (key == 'a')
    rotate_a += 5;


    if (key =='p')
     rotate_p += 5;
  else if (key == 'q')
    rotate_q += 5;

  if (key =='c')
     rotate_c+= 5;
  else if (key == 'd')
    rotate_d += 5;



  glutPostRedisplay();
}
/* Main function: GLUT runs as a console application starting at main() */
int main(int argc, char** argv) {
   glutInit(&argc, argv);            // Initialize GLUT
   glutInitDisplayMode(GLUT_DOUBLE); // Enable double buffered mode
   glutInitWindowSize(640, 480);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutCreateWindow(title);          // Create window with the given title
/*
  glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  glEnable(GL_LIGHTING);
  glEnable(GL_LIGHT0);
*/
   glutDisplayFunc(display);       // Register callback handler for window re-paint event
   glutSpecialFunc(specialKeys);

   glutKeyboardFunc(windowKey);
   glutReshapeFunc(reshape);       // Register callback handler for window re-size event
   initGL();                       // Our own OpenGL initialization
   glutMainLoop();                 // Enter the infinite event-processing loop
   return 0;
}
