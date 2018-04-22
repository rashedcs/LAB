
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#include <windows.h>
#include <GL/glut.h>

#define pi (2*acos(0.0))

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
double rigthFinger_angle=0.0;
double leftFinger_angle=0.0;
double middleFinger_angle=0.0;

struct point
{
	double x,y,z;
};


void drawAxes()
{
	if(drawaxes==1)
	{
		glColor3f(1.0, 1.0, 1.0);
		glBegin(GL_LINES);{
			glVertex3f( 100,0,0);
			glVertex3f(-100,0,0);

			glVertex3f(0,-100,0);
			glVertex3f(0, 100,0);

			glVertex3f(0,0, 100);
			glVertex3f(0,0,-100);

		}glEnd();
	}
}



void drawFullHand(){

    int radius=10;
    int scale=5;
    int translate = -scale*radius;

    glPushMatrix();
        glRotatef(fullHand_angle, 0,1,0);
        glRotatef(backMove_angle, 1,0,0);
        glTranslatef(0.0,0, translate);   ///translate=-(5*radius)=-50
        glScalef(1, 1,5);
        glutWireSphere(radius,16,16);
    glPopMatrix();


        //translate=-130;translate= -(diameter of upperPart+5*radius of lowerPart)
        //glTranslatef(2*50*sin(fullHand_angle),0,0);
       //glTranslatef(0,0,2*50*cos(fullHand_angle));
       //glRotatef(30,0,1,0);


    glPushMatrix();
        glRotatef(backMove_angle,1,0,0);
        glRotatef(fullHand_angle,0,1,0);
        glTranslatef(0.0,0,-(2*(5*radius)));
        glRotatef(lowerPart_angle,0,1,0);
        glTranslatef(0,0,-5*(radius-4)); //(0,0) te niye asha hoyeche
        glScalef(1,1,5);
        glutWireSphere(radius-4,16,16);
    glPopMatrix();


    glPushMatrix();
    glRotatef(backMove_angle,1,0,0);
    glRotatef(fullHand_angle,0,1,0);

    //glTranslatef(0,0,-160);   //translate=-length of upper and lower part+height of triangle
    glTranslatef(0.0,0,-(2*(5*radius))); //length of upper part
    glRotatef(lowerPart_angle,0,1,0);
    glTranslatef(0,0,-2*5*(radius-4)); //length of lower part

    glTranslatef(0,0,-30);  // (0,0) point a niye ashlam
    glBegin(GL_TRIANGLES);
        glVertex3f(0,20,0);  //base=2*20
        glVertex3f(0,0,30);  //Palm Height=30
        glVertex3f(0,-20,0);
    glEnd();
    glPopMatrix();

    glPushMatrix();
        //glRotatef(lowerPart_angle,0,1,0);
        glRotatef(backMove_angle,1,0,0);
        glRotatef(fullHand_angle,0,1,0);

        //glTranslated(0.0,0,-202); //translate=-length of upper and lower+height of triangle+ 3*radius of finger
        glTranslatef(0.0,0,-(2*(5*radius))); //length of upper part
        glRotatef(lowerPart_angle,0,1,0);
        glTranslatef(0,0,-2*5*(radius-4)); //length of lower part

        glTranslatef(0,0,-30);  // length of triangle
        glRotatef(middleFinger_angle,0,1,0);
        glTranslatef(0,0,-12); //(0,0) te niye ashlam
        glScalef(1,1,3);
        glutWireSphere(4,16,16);
   glPopMatrix();

   glPushMatrix();
        //glRotatef(lowerPart_angle,0,1,0);
        glRotatef(backMove_angle,1,0,0);
        glRotatef(fullHand_angle,0,1,0);

        glTranslatef(0.0,0,-(2*(5*radius))); //length of upper part
        glRotatef(lowerPart_angle,0,1,0);
        glTranslatef(0,0,-2*5*(radius-4)); //length of lower part

        glTranslatef(0,0,-30);  // length of triangle
        glRotatef(leftFinger_angle,0,1,0);
        glTranslatef(0,20,-12); //(0,20) te niye ashlam //left finger
        glScalef(1,1,3);
        glutWireSphere(4,16,16);
   glPopMatrix();

   glPushMatrix();
        //glRotatef(lowerPart_angle,0,1,0);
        glRotatef(backMove_angle, 1,0,0);
        glRotatef(fullHand_angle, 0,1,0);

        glTranslatef(0.0,0,-(2*(5*radius))); //length of upper part
        glRotatef(lowerPart_angle,0,1,0);
        glTranslatef(0,0,-2*5*(radius-4)); //length of lower part

        glTranslatef(0,0,-30);  // length of triangle
        glRotatef(rigthFinger_angle,0,1,0);
        glTranslatef(0,-20,-12); //(0,-20) te niye ashlam //right finger
        glScalef(1,1,3);
        glutWireSphere(4,16,16);
   glPopMatrix();




}


void keyboardListener(unsigned char key, int x,int y){
	switch(key){

		case '1':
		    fullHand_angle-=2;
		    if (fullHand_angle>45)
                fullHand_angle=45;
            if (fullHand_angle<-45)
                fullHand_angle=-45;

			break;
        case '2':
            fullHand_angle+=2;
            if (fullHand_angle>45)
                fullHand_angle=45;
            if (fullHand_angle<-45)
                fullHand_angle=-45;

            break;
        case '3':
            lowerPart_angle-=2;
            if(lowerPart_angle<-90)
                lowerPart_angle=-90;
            else if(lowerPart_angle>0)
                lowerPart_angle=0;

            break;
        case '4':
            lowerPart_angle+=2;
            if(lowerPart_angle<-90)
                lowerPart_angle=-90;
            else if(lowerPart_angle>0)
                lowerPart_angle=0;
            break;

        case '5':
            rigthFinger_angle-=2;
            if(rigthFinger_angle<-90)
                rigthFinger_angle=-90;
            else if(rigthFinger_angle>0)
                rigthFinger_angle=0;
            break;
        case '6':
            rigthFinger_angle+=2;
            if(rigthFinger_angle<-90)
                rigthFinger_angle=-90;
            else if(rigthFinger_angle>0)
                rigthFinger_angle=0;
            break;
        case '7':
            middleFinger_angle-=2;
            if(middleFinger_angle<-90)
                middleFinger_angle=-90;
            else if(middleFinger_angle>0)
                middleFinger_angle=0;
            break;
        case '8':
            middleFinger_angle+=2;
            if(middleFinger_angle<-90)
                middleFinger_angle=-90;
            else if(middleFinger_angle>0)
                middleFinger_angle=0;
            break;
        case '9':
            leftFinger_angle-=2;
            if(leftFinger_angle<-90)
                leftFinger_angle=-90;
            else if(leftFinger_angle>0)
                leftFinger_angle=0;
            break;
        case '0':
            leftFinger_angle+=2;
            if(leftFinger_angle<-90)
                leftFinger_angle=-90;
            else if(leftFinger_angle>0)
                leftFinger_angle=0;
            break;
        case 'q':
            backMove_angle+=2;
            if(backMove_angle>90)
                backMove_angle=90;
            if(backMove_angle<0)
                backMove_angle=0;

            break;
        case 'w':
            backMove_angle-=2;
            if(backMove_angle>90)
                backMove_angle=90;
            if(backMove_angle<0)
                backMove_angle=0;

            break;
		default:
			break;
	}
}


void specialKeyListener(int key, int x,int y){
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

		case GLUT_KEY_PAGE_UP:
			break;
		case GLUT_KEY_PAGE_DOWN:
			break;

		case GLUT_KEY_INSERT:
			break;

		case GLUT_KEY_HOME:
			break;
		case GLUT_KEY_END:
			break;

		default:
			break;
	}
}


void mouseListener(int button, int state, int x, int y){	//x, y is the x-y of the screen (2D)
	switch(button){
		case GLUT_LEFT_BUTTON:
			if(state == GLUT_DOWN){		// 2 times?? in ONE click? -- solution is checking DOWN or UP
				drawaxes=1-drawaxes;
			}
			break;

		case GLUT_RIGHT_BUTTON:
			//........
			break;

		case GLUT_MIDDLE_BUTTON:
			//........
			break;

		default:
			break;
	}
}



void display(){

	//clear the display
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0,0,0,0);	//color black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/********************
	/ set-up camera here
	********************/
	//load the correct matrix -- MODEL-VIEW matrix
	glMatrixMode(GL_MODELVIEW);

	//initialize the matrix
	glLoadIdentity();

	//now give three info
	//1. where is the camera (viewer)?
	//2. where is the camera looking?
	//3. Which direction is the camera's UP direction?

	//gluLookAt(100,100,100,	0,0,0,	0,0,1);
	gluLookAt(200*cos(cameraAngle), 200*sin(cameraAngle), cameraHeight,		0,0,0,		0,0,1);
	//gluLookAt(100,100,100,	0,0,0,	0,1,0);


	//again select MODEL-VIEW
	glMatrixMode(GL_MODELVIEW);


	/****************************
	/ Add your objects from here
	****************************/
	//add objects

	drawAxes();
	//drawGrid();

    glColor3f(0.5,0.5,0.5);
    //drawSquare(10);

    //drawSS();
    //drawWheel();
    //drawCircle(30,24);
   // glRotatef(lowerPart_angle,0,1,0);
    //glRotatef(backMove_angle,1,0,0);
    //glRotatef(fullHand_angle,0,1,0);
    drawFullHand();

    //drawCone(20,50,24);
    //drawCylinder(20,50,80);
	//drawSphere(30,24,20);




	//ADD this line in the end --- if you use double buffer (i.e. GL_DOUBLE)
	glutSwapBuffers();
}


void animate(){
	angle+=0.05;
	//codes for any changes in Models, Camera
	glutPostRedisplay();
}

void init(){
	//codes for initialization
	drawgrid=0;
	drawaxes=1;
	cameraHeight=80.0;
	cameraAngle=1.0;
	angle=0;

	//clear the screen
	glClearColor(0,0,0,0);

	/************************
	/ set-up projection here
	************************/
	//load the PROJECTION matrix
	glMatrixMode(GL_PROJECTION);

	//initialize the matrix
	glLoadIdentity();

	//give PERSPECTIVE parameters
	gluPerspective(80,	1,	1,	1000.0);
	//field of view in the Y (vertically)
	//aspect ratio that determines the field of view in the X direction (horizontally)
	//near distance
	//far distance
}

int main(int argc, char **argv){
	glutInit(&argc,argv);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);	//Depth, Double buffer, RGB color

	glutCreateWindow("My OpenGL Program");

	init();

	glEnable(GL_DEPTH_TEST);	//enable Depth Testing

	glutDisplayFunc(display);	//display callback function
	glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)

	glutKeyboardFunc(keyboardListener);
	glutSpecialFunc(specialKeyListener);
	glutMouseFunc(mouseListener);

	glutMainLoop();		//The main loop of OpenGL

	return 0;
}
