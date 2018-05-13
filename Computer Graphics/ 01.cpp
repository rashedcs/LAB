#include<bits/stdc++.h>
#include <windows.h>
#include <GL/glut.h>

#define pi  3.14159

double cameraHeight;
double cameraAngle;
int drawgrid;
int drawaxes;
double angle;

double map_angle;
double Block_size=40;
double Block_distance=39, size_cube=39;
int slices_spehere=30, stacks_spehere=30;
int segments_cylinder=24;
double temp=0;
double move_pos=2;
double var=0,  var1=0, var2=0;

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
	glBegin(GL_POLYGON);
		glVertex3f( a, a,0);
		glVertex3f( a,-a,0);
		glVertex3f(-a,-a,0);
		glVertex3f(-a, a,0);
	glEnd();
}



void Xaxisrotation()
{
    glPushMatrix();
        glColor3f(0,1,0);
        glRotatef(var1,1,0,0);
        glTranslatef(0,45,0);
        drawSquare(11);
        var1 = var1 +.50;
    glPopMatrix();
}

void Yaxisrotation()
{
    glPushMatrix();
        glColor3f(1,0,1);
        glRotatef(var2,0,1,0);
        glTranslatef(60, 0, 0);
        drawSquare(11);
        var2 = var2 + 0.50;
    glPopMatrix();
}

void Zaxisrotation()
{
    glPushMatrix();
        glColor3f(1,1,0);
        glRotatef(var, 0,0,1);
        glTranslatef(15,0,0);
        drawSquare(11);
        var = var + .50;
    glPopMatrix();
}




void drawShape()
{
    Xaxisrotation();
	Yaxisrotation();
	Zaxisrotation();
}


void display()
{
	/******************** clear the buffer ********************/
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0,0,0,0);	//color black
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	/******************** set-up camera here ********************/
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();


	gluLookAt(pos.x, pos.y, pos.z,     pos.x + l.x,pos.y + l.y, pos.z + l.z,     u.x, u.y, u.z);
	glMatrixMode(GL_MODELVIEW);  	//again select MODEL-VIEW


	/**************************** Add your objects from here ****************************/
	drawAxes();
    drawShape();


	glutSwapBuffers();
}


void animate()
{
	angle+=0.05;
	glutPostRedisplay();
}

void init()
{
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
	glClearColor(0,0,0,0);


	/************************  set-up projection here ************************/
	glMatrixMode(GL_PROJECTION); 	//load the PROJECTION matrix
	glLoadIdentity();                         	//initialize the matrix
	gluPerspective(80,	1,	1,	1000.0);  	//give PERSPECTIVE parameters
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
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
	glutCreateWindow("Lab 1");

	init();

	glEnable(GL_DEPTH_TEST);

	glutDisplayFunc(display);
	glutIdleFunc(animate);
	glutSpecialFunc(specialKeyListener);

	glutMainLoop();

	return 0;
}
