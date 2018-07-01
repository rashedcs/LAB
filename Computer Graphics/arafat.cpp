#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>

#include <windows.h>
#include <GL/glut.h>

#define pi (2*acos(0.0))

double cameraHeight;
double cameraAngle;
int drawaxes;
double angle;

double map_angle;
double Block_size=40;
double Block_distance=38,size_cube=38;
double temp=0;
double move_pos=2;
double ar=0;

class point
{
public:
    double x,y,z;
    point()
    {

    }
    point(double a, double b, double c)
    {
        x=a; y=b; z=c;
    }
};

point o(0,0,0);
point l,u,r,pos;

void drawAxes()
{
	if(drawaxes==1)
	{
		glBegin(GL_LINES);{
		    glColor3f(0, 0, 0);
			glVertex3f( 100,0,0);
			glVertex3f(-100,0,0);

            glColor3f(1.0, 0, 0);
			glVertex3f(0,-100,0);
			glVertex3f(0, 100,0);

            glColor3f(0, 0, 1.0);
			glVertex3f(0,0, 100);
			glVertex3f(0,0,-100);
		}glEnd();
	}
}

void drawTriangle(point p1, point p2, point p3)
{
	glBegin(GL_TRIANGLES);{
		glVertex3f( p1.x, p1.y, p1.z);
		glVertex3f( p2.x, p2.y, p2.z);
		glVertex3f( p3.x, p3.y, p3.z);
	}glEnd();
}
void drawRectangle(point p1, point p2, point p3, point p4)
{
	glBegin(GL_QUADS);{
		glVertex3f( p1.x, p1.y, p1.z);
		glVertex3f( p2.x, p2.y, p2.z);
		glVertex3f( p3.x, p3.y, p3.z);
		glVertex3f( p4.x, p4.y, p4.z);
	}glEnd();
}

void drawCone(double radius,int segments, point p, point o=o)
{
    int i;
    point points[100];
    glColor3f(1.0,0.0,1.0);
    for(i=0;i<=segments;i++)
    {
        points[i].x=o.x+radius*cos(((double)i/(double)segments)*2*pi);
        points[i].y=o.y+radius*sin(((double)i/(double)segments)*2*pi);
        points[i].z=o.z+0;
    }
    for(i=0;i<segments; i++)
    {
        glColor3f(0,0,1);
        drawTriangle(points[i], points[i+1], p);
        glColor3f(1.0,0.0,0);
        drawTriangle(points[i], points[i+1], o);
    }
}

void drawCylinder(double radius, int segments, point p, point o=o)
{
    int i;
    point points[100], points2[100];
    glColor3f(1.0,0.0,1.0);
    for(i=0;i<=segments;i++)
    {
        points[i].x=o.x+radius*cos(((double)i/(double)segments)*2*pi);
        points[i].y=o.y+radius*sin(((double)i/(double)segments)*2*pi);
        points[i].z=o.z+0;

        points2[i].x=p.x+radius*cos(((double)i/(double)segments)*2*pi);
        points2[i].y=p.y+radius*sin(((double)i/(double)segments)*2*pi);
        points2[i].z=p.z+0;
    }

    for(i=0;i<segments; i++)
    {
        glColor3f(0,0,1);
        drawTriangle(points[i], points[i+1], o);
        glColor3f(0,0,1);
        drawTriangle(points2[i], points2[i+1], p);

        glColor3f(1, 0, 0);
        drawRectangle(points[i], points[i+1], points2[i+1], points2[i]);
    }
}

void display()
{
	//set the display
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0.87,0.93,1.0,0);	//color black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	/********************
	/ set-up camera here
	********************/
	//load the correct matrix -- MODEL-VIEW matrix
	glMatrixMode(GL_MODELVIEW);

	//initialize the matrix
	glLoadIdentity();

	//now give three info
	//1. where is the camera (viewer)? 2. where is the camera looking? 3. Which direction is the camera's UP direction?

	gluLookAt(pos.x, pos.y, pos.z,   pos.x + l.x,pos.y + l.y, pos.z + l.z,   u.x, u.y, u.z);

	//again select MODEL-VIEW
	glMatrixMode(GL_MODELVIEW);

	// Add objects from here
	drawAxes();
	point pp(20,-10,60);
	point s(20,-10,10);
    drawCone(20,50,pp, s);
    point ppp(-20,10,60);
	point ss(-20,10,10);
    drawCylinder(20,50,ppp, ss);
    //drawSquare();

	//Double Buffer
	glutSwapBuffers();
}


void animate()
{
	angle+=0.01;
	//codes for any changes in Models, Camera
	glutPostRedisplay();
}
void init()
{
	//codes for initialization
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
    pos.z=40;

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
void specialKeyListener(int key, int x,int y)
{
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


int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitWindowSize(720, 640);
	glutInitWindowPosition(20, 20);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);	//Depth, Double buffer, RGB color

	glutCreateWindow("Lab Assignment-2");

	init();

	glEnable(GL_DEPTH_TEST);	//enable Depth Testing

	glutDisplayFunc(display);	//display callback function
	glutIdleFunc(animate);		//what you want to do in the idle time (when no drawing is occuring)

	glutSpecialFunc(specialKeyListener);

	glutMainLoop();		//The main loop of OpenGL

	return 0;
}
