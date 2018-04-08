#include<bits/stdc++.h>
#include <windows.h>
#include <GL/glut.h>

#define pi (2*acos(0.0))

double cameraHeight;
double cameraAngle;
int drawgrid;
int drawaxes;
double angle;

double map_angle;
double Block_size=40;
double Block_distance=38,size_cube=38;
int slices_spehere=30, stacks_spehere=30;
int segments_cylinder=24;
double temp=0;
double move_pos=2;
double ar=0,ar1=0,ar2=0,ar3=0;
//static int cnum = 0; /// to check circle number to specify planes.

struct point
{
	double x,y,z;
};

point l,u,r,pos;







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

void drawSquare(double a)
{
    ///glColor3f(1.0,0.0,0.0);
	glBegin(GL_QUADS);{
		glVertex3f( a, a,0);
		glVertex3f( a,-a,0);
		glVertex3f(-a,-a,0);
		glVertex3f(-a, a,0);
	}glEnd();
}


void drawCircle(double radius,int segments,int cnum)
{
    int i;
    struct point points[100];
    glColor3f(1.0,0.0,1.0);
    //generate points
    for(i=0;i<=segments;i++)
    {
        points[i].x=radius*cos(((double)i/(double)segments)*2*pi);
        points[i].y=radius*sin(((double)i/(double)segments)*2*pi);
    }
    //draw segments using generated points

    if(cnum==0){
        for(i=0;i<segments;i++)
        {

            glBegin(GL_LINES);
            {
                glColor3f(1.0,1.0,1.0);
                glVertex3f(points[i].x,points[i].y,0);
                glVertex3f(points[i+1].x,points[i+1].y,0);
            }
            glEnd();
        }
    }
    if( cnum==1){
        glColor3f(1.0,0.0,0.0);
        for(i=0;i<segments;i++)
        {
            glBegin(GL_LINES);
            {
                glVertex3f(points[i].x,points[i].y,0);
                glVertex3f(points[i+1].x,points[i+1].y,0);
            }
            glEnd();
        }
    }
    else if(cnum==2){
        glColor3f(0.0,1.0,0.0);
        for(i=0;i<segments;i++)
        {
            glBegin(GL_LINES);
            {
                glVertex3f(0,points[i].x,points[i].y);
                glVertex3f(0,points[i+1].x,points[i+1].y);
            }
            glEnd();
        }
    }
    else if(cnum==3){
        glColor3f(0.0,0.0,1.0);
        for(i=0;i<segments;i++)
        {
            glBegin(GL_LINES);
            {
                glVertex3f(points[i].x,0,points[i].y);
                glVertex3f(points[i+1].x,0,points[i+1].y);
            }
            glEnd();
        }
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
	//gluLookAt(200*cos(cameraAngle), 200*sin(cameraAngle), cameraHeight,		0,0,0,		0,0,1);
	//gluLookAt(0,0,200,	0,0,0,	0,1,0);
	gluLookAt(pos.x, pos.y, pos.z,     pos.x + l.x,pos.y + l.y, pos.z + l.z,     u.x, u.y, u.z);


	//again select MODEL-VIEW
	glMatrixMode(GL_MODELVIEW);


	/****************************
	/ Add your objects from here
	****************************/
	//add objects

	drawAxes();
//	drawGrid();

    glPushMatrix();
    {
        glColor3f(1.0,0.0,0.0);
        glRotatef(ar,0,0,1);
        glTranslatef(10,0,0);
        drawSquare(10);
        ar+=.5;
    }glPopMatrix();

    drawCircle(30,24,0);

    glPushMatrix();
    {
        glColor3f(0.0,1.0,0.0);
        glRotatef(ar1,1,0,0);
        glTranslatef(0,40,0);
        drawSquare(10);
        ar1+=.06;
    }glPopMatrix();

    glPushMatrix();
    {
        glColor3f(0.0,0.0,1.0);
        glRotatef(ar2,0,1,0);
        glTranslatef(60,0,0);
        drawSquare(10);
        ar2+=.05;
    }glPopMatrix();


   /* glPushMatrix();
    {
        glRotatef(ar,0,0,1);
        drawCircle(20,24,1);
        ar+=.05;

    }glPopMatrix();
    glPushMatrix();
    {
        glRotatef(ar1,1,0,0);
        drawCircle(30,24,2);
        ar1+=.05;

    }glPopMatrix();

    glPushMatrix();
    {
        glRotatef(ar2,0,1,0);
        drawCircle(25,24,3);
        ar2+=.05;

    }glPopMatrix();

*/
   // drawSS();



    //drawCone(20,50,24);

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
	cameraHeight=150.0;
	cameraAngle=1.0;
	angle=0;

	u.x=0;
    u.y=0;
    u.z=1;


    r.x=-1/sqrt(2);
    r.y=1/sqrt(2);
    r.z=0;

    l.x=-1/sqrt(2) ;
    l.y=-1/sqrt(2) ;
    l.z=0;

    pos.x=100;
    pos.y=100;
    pos.z=0;


	map_angle=90;

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
void specialKeyListener(int key, int x,int y){
	switch(key){
		case GLUT_KEY_DOWN:		//down arrow key
			//cameraHeight -= 3.0;
			pos.x-=l.x*move_pos;
			pos.y-=l.y*move_pos;
			pos.z-=l.z*move_pos;

			break;
		case GLUT_KEY_UP:		// up arrow key
			//cameraHeight += 3.0;
			pos.x+=l.x*move_pos;
			pos.y+=l.y*move_pos;
			pos.z+=l.z*move_pos;
			break;

		case GLUT_KEY_RIGHT:
			//cameraAngle += 0.03;
			pos.x+=r.x*move_pos;
			pos.y+=r.y*move_pos;
			pos.z+=r.z*move_pos;
			break;
		case GLUT_KEY_LEFT:
			//cameraAngle -= 0.03;
			pos.x-=r.x*move_pos;
			pos.y-=r.y*move_pos;
			pos.z-=r.z*move_pos;

			break;

		case GLUT_KEY_PAGE_UP:
		    pos.x+=u.x*move_pos;
			pos.y+=u.y*move_pos;
			pos.z+=u.z*move_pos;
			break;
		case GLUT_KEY_PAGE_DOWN:
            pos.x-=u.x*move_pos;
			pos.y-=u.y*move_pos;
			pos.z-=u.z*move_pos;
			break;

		case GLUT_KEY_INSERT:
			break;

		case GLUT_KEY_HOME:
		    if(Block_size>0)
            {
                Block_size-=5;
                temp+=5;
            }
			break;
		case GLUT_KEY_END:
            if(Block_size<size_cube)
            {
                Block_size+=5;
                temp-=5;
            }
			break;

		default:
			break;
	}
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

//	glutKeyboardFunc(keyboardListener);
	glutSpecialFunc(specialKeyListener);
	//glutMouseFunc(mouseListener);


	glutMainLoop();		//The main loop of OpenGL

	return 0;
}
