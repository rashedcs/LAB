#include<bits/stdc++.h>
#include <windows.h>
#include <GL/glut.h>
using namespace std;
#define pi  3.141659

double cameraHeight;
double cameraAngle;
int drawgrid;
int drawaxes;
int radius;
double angle;

double translate;
struct vec{
  double x,y;
}frontVector;

struct wheelPos
{
    double x,y;
}wheelPosition;

double rotation_theta;
double rotate_angle=0;

struct point
{
	double x,y,z;
};


void drawAxes()
{
	if(drawaxes==1)
	{

		glBegin(GL_LINES);{
              	glColor3f(1,1,1);	//grey
			glVertex3f( 100,0,0);
			glVertex3f(-100,0,0);

            glColor3f(1,0,0);	//grey
			glVertex3f(0,-100,0);
			glVertex3f(0, 100,0);

	       	glColor3f(1,1,1);	//grey
			glVertex3f(0,0, 100);
			glVertex3f(0,0,-100);

		}glEnd();
	}
}


void drawGrid()
{
	if(drawgrid==1)
	{
		glColor3f(0.9, 0.7, 0.2);	//grey
		glBegin(GL_LINES);
        {
			for(int i=-18;i<=18;i++)
            {
				glVertex3f(i*10, -2*90, 0);
				glVertex3f(i*10,  2*90, 0);

				//lines parallel to X-axis
				glVertex3f(-2*90, i*10, 0);
				glVertex3f( 2*90, i*10, 0);
			}
		}
		glEnd();
	}
}


void drawWheel(double radius,int segments)
{
    int i;
    double shade;
    struct point points[100];

    glTranslatef(translate,0,0);
    glRotatef(rotate_angle,0,0,1);


    glRotatef(rotation_theta,0,1,0);


    for(int i=0;i<=segments;i++)
    {
        points[i].x=radius*cos(((double)i/(double)segments)*2*pi);
        points[i].z=radius*sin(((double)i/(double)segments)*2*pi);
    }

    for(int i=0;i<segments;i++)
    {
            if(i<segments/2)              shade=2*(double)i/(double)segments;
            else                                shade=2*(1.0-(double)i/(double)segments);
            glColor3f(shade,shade,shade);

            glBegin(GL_POLYGON);
            {
                glVertex3f(points[i].x,     -radius, points[i].z);
                glVertex3f(points[i].x,      radius, points[i].z);
                glVertex3f(points[i+1].x,  radius, points[i+1].z);
                glVertex3f(points[i+1].x, -radius, points[i+1].z);
            }
            glEnd();
    }

    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    {
        glVertex3f(points[0].x,-radius,points[0].z);
        glVertex3f(points[0].x,radius,points[0].z);
        glVertex3f(points[segments/2].x,radius,points[segments/2].z);
        glVertex3f(points[segments/2].x,-radius,points[segments/2].z);
    }
    glEnd();
    glRotatef(90,0,1,0);

    glColor3f(0.5,0.8,0.7);
    glBegin(GL_POLYGON);
    {
        glVertex3f(points[0].x,-radius,points[0].z);
        glVertex3f(points[0].x,radius,points[0].z);
        glVertex3f(points[segments/2].x,radius,points[segments/2].z);
        glVertex3f(points[segments/2].x,-radius,points[segments/2].z);
    }
    glEnd();

}

void keyboardListener(unsigned char key, int x,int y)
{
	switch(key){
        double v_x;
        double v_y;

         case 'w':
            translate+=2;
            wheelPosition.x += 2*frontVector.x;
            wheelPosition.y += 2*frontVector.y;
            double rotation_radian;
            rotation_radian=translate/radius;
            rotation_theta=(180.0/pi)*rotation_radian;
            break;


         case 's':
            translate-=2;
            wheelPosition.x -= 2*frontVector.x;
            wheelPosition.y -= 2*frontVector.y;
            double rotation_radian1;
            rotation_radian1=translate/radius;
            rotation_theta=(180.0/pi)*rotation_radian1;
            break;

        case 'a':
            rotate_angle+=3;
			v_x = sqrt(pow(wheelPosition.x-frontVector.x, 2) +  pow(wheelPosition.y-frontVector.y, 2));
			v_y = sqrt(pow(wheelPosition.x+frontVector.y, 2) + pow(wheelPosition.y-frontVector.x, 2) );
			frontVector.x = v_x *cos(3*pi/180);
			frontVector.y = v_y*sin(3*pi/180);

			break;
        case 'd':
            rotate_angle-=3;
            v_x = sqrt(pow(wheelPosition.x-frontVector.x,2)+pow(wheelPosition.y-frontVector.y,2));
            v_y = sqrt(pow(wheelPosition.x+frontVector.y,2)+pow(wheelPosition.y-frontVector.x,2));
			frontVector.x = v_x*cos(3*pi/180);
			frontVector.y = v_y*sin(3*pi/180);
			break;

		default:
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



void display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	/********************set-up camera here********************/
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(200*cos(cameraAngle), 200*sin(cameraAngle), cameraHeight,		0,0,0,		0,0,1);
	//gluLookAt(100,100,100,	0,0,0,	0,1,0);


	glMatrixMode(GL_MODELVIEW);  //again select MODEL-VIEW


	/**************************** Add your objects from here ****************************/
	glPushMatrix();
        glTranslatef(0,0,-30);
        drawGrid();
	glPopMatrix();

    glColor3f(1,0,0);
    drawAxes();
    drawWheel(30,24);

	glutSwapBuffers();
}


void animate()
{
	angle+=0.05;
	glutPostRedisplay();
}

void init()
{
	drawgrid=1;
	drawaxes=1;
	cameraHeight=150.0;
	cameraAngle=1.0;
	radius=10;
	translate=0.0;
	angle=0;


    frontVector.x=-1.0;
    frontVector.y=0.0;

    wheelPosition.x=0.0;
    wheelPosition.y=0.0;

    rotation_theta=0.0 ;//
	glClearColor(0,0,0,0);

	/************************ set-up projection here ************************/
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(80,	1,	1,	1000.0);

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
