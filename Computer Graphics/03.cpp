#include<bits/stdc++.h>
#include <windows.h>
#include <GL/glut.h>

#define pi  3.14159

double cameraHeight;
double cameraAngle;
int drawgrid;
int drawaxes;
double angle;

double fullHand_angle=0.0;
double backMove_angle=0.0;


//double upperPart_angle;
double lowerPart_angle=0.0;
double palm_angle; //hater talu



void drawAxes()
{

		glBegin(GL_LINES);
		glColor3f(1.0, 1.0, 0.0);
			glVertex3f( 100,0,0);
			glVertex3f(-100,0,0);

            glColor3f(1.0, 1.0, 1.0);
			glVertex3f(0,-100,0);
			glVertex3f(0, 100,0);

	glColor3f(1.0, 1.0, 1.0);
			glVertex3f(0,0, 100);
			glVertex3f(0,0,-100);
		glEnd();

}


/*** 1st portion of hand ***/
void firstPortion(int radius)
{
    glPushMatrix();
        glRotatef(fullHand_angle, 0,1,0);
        glRotatef(backMove_angle, 1,0,0);
        glTranslatef(0.0,0, -(5*radius));
        glScalef(1, 1, 5);

        glutWireSphere(10,16,16);
    glPopMatrix();

}

/*** 2nd portion of hand ***/
void secondPortion(int radius)
{
    glPushMatrix();
       /** Allocate first portion **/
        glRotatef(fullHand_angle,0,1,0);
        glRotatef(backMove_angle,1,0,0);
        glTranslatef(0.0,0, -(2*(5*radius)));

        /**start second portion **/
        glRotatef(lowerPart_angle,0,1,0);
        glTranslatef(0,0,-5*(radius-4)); ///(0,0) te niye asha hoyeche

        glScalef(1,1,5);
        glutWireSphere(6,16,16);
    glPopMatrix();

}


/*** 3rd portion of hand ***/
void thirdPortion(int radius)
{
    glPushMatrix();
        glRotatef(backMove_angle, 1, 0, 0);
        glRotatef(fullHand_angle, 0, 1, 0);

        glTranslatef(0.0,0, - (2*(5*radius)));    ///length of upper part   = 2 * upper part
        glRotatef(lowerPart_angle,0,1,0);

        glTranslatef(0,0, -2*5*(radius-4));       ///length of lower part    = 2 * lower part


    ///translate = - (length of upper and lower part + height of triangle)

    /**start third portion **/
        glTranslatef(0,0,-30);  // (0,0) point a niye ashlam
        /*
        glBegin(GL_POLYGON);
            glVertex3f(0,20,0);  //base=2*20
            glVertex3f(0,-20,0);
            glVertex3f(0,0,30);  //Palm Height=30
        glEnd();
    glPopMatrix();
    */
     glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);
	   glVertex3f (0, 20, 0.0);
	   glVertex3f (0, -20, 0.0);
	   glVertex3f (0, -20, 0);
	   glVertex3f (0, 0, 30);
	   glVertex3f (0, 0, 30);
	   glVertex3f (0, 20, 0.0);
	   glEnd();
}

void drawFullHand()
{
    int radius=10;
   // int scale=5;
   // int translate = -scale*radius;
  //glTranslatef(0,0,-160);

    firstPortion(radius);
    secondPortion(radius);
    thirdPortion(radius);
}


void keyboardListener(unsigned char key, int x,int y)
{
	switch(key)
	{
		case '1':
		    fullHand_angle-=2;
		    if (fullHand_angle>45)            fullHand_angle = 45;
            else if (fullHand_angle<-45)    fullHand_angle = -45;
			break;

        case '2':
            fullHand_angle+=2;
            if (fullHand_angle>45)            fullHand_angle = 45;
            else if (fullHand_angle<-45)    fullHand_angle = -45;
            break;

        case '3':
            lowerPart_angle-=2;
            if(lowerPart_angle<-90)           lowerPart_angle =-90;
            else if(lowerPart_angle>0)      lowerPart_angle=0;
            break;

        case '4':
            lowerPart_angle+=2;
            if(lowerPart_angle<-90)          lowerPart_angle=-90;
            else if(lowerPart_angle>0)      lowerPart_angle=0;
            break;
	}
}


void specialKeyListener(int key, int x,int y)
{
	switch(key){
		case GLUT_KEY_DOWN:		//down arrow key
			cameraHeight -= 3.0;
			break;
		case GLUT_KEY_UP:		// up arrow key
			cameraHeight += 3.0;
			break;

		case GLUT_KEY_RIGHT:
			cameraAngle += 0.03;
			break;
		case GLUT_KEY_LEFT:
			cameraAngle -= 0.03;
			break;

		case GLUT_KEY_INSERT:
			break;

		case GLUT_KEY_HOME:
			break;

		default:
			break;
	}
}





void display()
{

	/********************  clean the display  ********************/
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0,0,0,0);	//color black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	/********************  set-up camera here  ********************/
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(200*cos(cameraAngle), 200*sin(cameraAngle), cameraHeight,		0,0,0,		0,0,1);
	glMatrixMode(GL_MODELVIEW);


	/********************  add object ********************/
	drawAxes();
    glColor3f(0.5,0.5,0.5);
    drawFullHand();


	glutSwapBuffers();
}


void animate()
{
	angle+=0.05;
	glutPostRedisplay();
}

void init()
{
	drawaxes=1;
	cameraHeight=80.0;
	cameraAngle=1.0;
	angle=0;

	glClearColor(0,0,0,0);

	/************************ set-up projection here ********************/
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80,	1,	1,	1000.0);
}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);	//Depth, Double buffer, RGB color

	glutCreateWindow("Lab 3");

	init();

	glEnable(GL_DEPTH_TEST);	//enable Depth Testing

	glutDisplayFunc(display);	//display callback function
	glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)

	glutKeyboardFunc(keyboardListener);
	glutSpecialFunc(specialKeyListener);

	glutMainLoop();		//The main loop of OpenGL

	return 0;
}
