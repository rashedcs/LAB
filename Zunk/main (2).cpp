#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <GL/glut.h>
#include <math.h>
#define pi 3.14159265358979323846264

#include "imageloader.h"
#include "text3d.h"

double rotate_y=0;
double rotate_x=0;


using namespace std;

//function
void myFunction(double x,double y,double z,double height,double width,double mota)
{
    glBegin(GL_QUADS);
    glColor3f(1.0f,0.0f,0.0f);

    //font
    glVertex3f(x,y,z);
    glVertex3f(x,y+height,z);
    glVertex3f(x+width,y+height,z);
    glVertex3f(x+width,y,z);

    //back
     glColor3f(0.0f,0.0f,1.0f);
     glVertex3f(x,y,z-mota);
    glVertex3f(x,y+height,z-mota);
    glVertex3f(x+width,y+height,z-mota);
    glVertex3f(x+width,y,z-mota);

    //top
 glColor3f(1.0f,0.0f,1.0f);
     glVertex3f(x,y+height,z);
    glVertex3f(x,y+height,z-mota);
    glVertex3f(x+width,y+height,z-mota);
    glVertex3f(x+width,y+height,z);

    //left
     glColor3f(0.0f,1.0f,0.0f);
     glVertex3f(x,y,z);
    glVertex3f(x,y+height,z);
    glVertex3f(x,y+height,z-mota);
    glVertex3f(x,y,z-mota);

    //right
     glColor3f(0.0f,1.0f,1.0f);
     glVertex3f(x+width,y+height,z);
    glVertex3f(x+width,y+height,z-mota);
    glVertex3f(x+width,y,z-mota);
    glVertex3f(x+width,y,z);

    //botom
     glColor3f(1.0f,1.0f,1.0f);

     glVertex3f(x,y,z);
    glVertex3f(x,y,z-mota);
    glVertex3f(x+width,y,z-mota);
    glVertex3f(x+width,y,z);
    glEnd();
}

float angle = 150.0f;
float posL1=0.8f;
float posL2=0.8f;
float posL3=0.8f;
float R=0,G=0.4,B=1.0;
int night = 0;
int flower_flag = 0;
int rotate_Flag = 0;
int sun_moon_flag = 0;
double PI = acos(-1);

float _angle = -30.0f;
float _scale;
float skyAngle = 360;
//The four strings that are drawn
const char* STRS[2] = {"we will never", "forget you."};

GLuint _textureIdGrass; //The id of the grass texture
GLuint _textureIdRedTile1; //The id of the Red Tile texture
GLuint _textureIdRedBreak;
GLuint _textureIdSkyDay;
GLuint _textureIdSkyNight;


//Computes a scaling value so that the strings
float computeScale(const char* strs[2]) {
	float maxWidth = 0;
	for(int i = 0; i < 2; i++) {
		float width = t3dDrawWidth(strs[i]);
		if (width > maxWidth) {
			maxWidth = width;
		}
	}

	return 2.6f / maxWidth;
}



void cleanup() {
	t3dCleanup();
}

void keyboardkey(int key, int x, int y)
{

	if(key==GLUT_KEY_DOWN)
    {
        R = 0.0; G = 0.4; B = 1.0;
        posL1=0.8f; posL2=0.8f; posL3=0.8f;
            night = 0;
    }
	else if(key==GLUT_KEY_UP)
    {
        R = 0.0; G = 0.0; B = 0.0;
        posL1=0.2f; posL2=0.2f; posL3=0.2f;
              night = 1;
    }
    else if (key == GLUT_KEY_LEFT)
    rotate_x += 2;

  else if (key == GLUT_KEY_RIGHT)
    rotate_x -= 2;

    glutPostRedisplay();
}


void handleKeypress(unsigned char key, int x, int y) {
	switch (key) {
		case 27: //Escape key
			exit(0);
            break;
        case 'r':
        case 'R':
            angle += 3.0f;
            if (angle > 360) {
                angle -= 360;
            }
            break;
       //
        case 'd':
        case 'D':
            R = 0.0; G = 0.4; B = 1.0;
            posL1=0.8f; posL2=0.8f; posL3=0.8f;
            night = 0;
            break;
        case 'n':
        case 'N':
            R = 0.0; G = 0.0; B = 0.0;
            posL1=0.2f; posL2=0.2f; posL3=0.2f;
            night = 1;
            break;
        case 'f':
        case 'F':
            if (flower_flag == 0) {
                flower_flag = 1;
            } else {
                flower_flag = 0;
            }
            break;

        case 's':
        case 'S':
        case 'm':
        case 'M':
            if (sun_moon_flag == 0) {
                sun_moon_flag = 1;
            } else {
                sun_moon_flag = 0;
            }
            break;
        case ' ':
            if (rotate_Flag == 0) {
                rotate_Flag = 1;
            } else {
                rotate_Flag = 0;
            }
            break;


	}
	glutPostRedisplay();
}

void drawScene()
{


    GLUquadric *quadric;
    quadric = gluNewQuadric();

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clear before draw somethings
    glClearColor(R,G,B,1); // for background -- day night
	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity();

	glTranslatef(0.5f, 0.0f, -10.0f);



    // Light 0
    GLfloat lightColor0[] = {posL1, posL2, posL3, 1.0f};
	GLfloat lightPos0[] = {0.0f, 8.0f, -8.0f, 1.0f};
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor0);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos0);


	glRotatef(10, 1.0f, 0.0f, 0.0f);
	//glRotatef(-10, 0.0f, 0.0f, 1.0f);
	glRotatef(angle,0.0f, 1.0f, 0.0f);



	//Draw the strings along the sides of a square
	glPushMatrix();
    glScalef(_scale*1.2, _scale*1.2, _scale*1.2);
    glColor3f(0.1f, 1.0f, 0.1f);
    for(int i = 0; i < 2; i++) {
        glPushMatrix();
        glRotatef(130.0,0.0,1.0,0.0);
        glTranslatef(6, -i*1+6.0, -7+1.5f / _scale);
        if (flower_flag == 1) {
            t3dDraw3D(STRS[i], 0, 0, 0.2f);
        }
        glPopMatrix();
    }
    glPopMatrix();


        glPushMatrix();
        glRotatef(0.0,0.0,0.0,1.0); // orbits the planet around the sun
        glTranslatef(1.40,0.0,0.0);        // sets the radius of the orbit
        glRotatef(skyAngle,0.0,1.0,1.0); // revolves the planet on its axis
        glColor3f(4.0, 4.0, 4.0);          // green

        glEnable(GL_TEXTURE_2D);
        if (night == 1) {
            glBindTexture(GL_TEXTURE_2D, _textureIdSkyNight);
        } else {
            glBindTexture(GL_TEXTURE_2D, _textureIdSkyDay);
        }

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        gluQuadricTexture(quadric, 1);
        //glutWireSphere(0.16,20,20);        // Earth
        gluSphere(quadric,40,20,20);
        glDisable(GL_TEXTURE_2D);


        glPopMatrix();


    // 2nd left

	glBegin(GL_QUADS);

    glColor3f(1,1,1);



    // 2nd left

    // front
    glNormal3f(0.0, 0.0f, -1.0f);
    glVertex3f(-.20f, 1.10f, 1.0f);
	glVertex3f(-.10f, 1.10f, 1.0f);
	glVertex3f(-.10f, -1.10f, 1.0f);
    glVertex3f(-.20f, -1.10f, 1.0f);

    // back
    glNormal3f(0.0, 0.0f, 1.0f);
    glVertex3f(-.20f, 1.10f, 0.9f);
	glVertex3f(-.10f, 1.10f, 0.9f);
	glVertex3f(-.10f, -1.10f, 0.9f);
    glVertex3f(-.20f, -1.10f, 0.9f);


    // right
    glNormal3f(-1.0, 0.0f, 0.0f);
    glVertex3f(-.10f, 1.10f, 0.9f);
    glVertex3f(-.10f, 1.10f, 1.0f);
    glVertex3f(-.10f, -1.10f, 1.0f);
    glVertex3f(-.10f, -1.10f, 0.9f);

    // left
    glNormal3f(1.0, 0.0f, 0.0f);
    glVertex3f(-.20f, 1.10f, 0.9f);
    glVertex3f(-.20f, 1.10f, 1.0f);
    glVertex3f(-.20f, -1.10f, 1.0f);
    glVertex3f(-.20f, -1.10f, 0.9f);




    //  2nd right

    // front
    glNormal3f(0.0, 0.0f, -1.0f);
    glVertex3f(.20f, 1.10f, 1.2f);
	glVertex3f(.10f, 1.10f, 1.2f);
	glVertex3f(.10f, -1.10f, 1.2f);
    glVertex3f(.20f, -1.10f, 1.2f);

    // back
    glNormal3f(0.0, 0.0f, 1.0f);
    glVertex3f(.20f, 1.10f, 1.1f);
	glVertex3f(.10f, 1.10f, 1.1f);
	glVertex3f(.10f, -1.10f, 1.1f);
    glVertex3f(.20f, -1.10f, 1.1f);

    // left
    glNormal3f(1.0, 0.0f, 0.0f);
    glVertex3f(.10f, 1.10f, 1.1f);
    glVertex3f(.10f, 1.10f, 1.2f);
    glVertex3f(.10f, -1.10f, 1.2f);
    glVertex3f(.10f, -1.10f, 1.1f);

    // right
    glNormal3f(-1.0, 0.0f, 0.0f);
    glVertex3f(.20f, 1.10f, 1.1f);
    glVertex3f(.20f, 1.10f, 1.2f);
    glVertex3f(.20f, -1.10f, 1.2f);
    glVertex3f(.20f, -1.10f, 1.1f);



    // 2nd top

    // front
    glNormal3f(0.0, 0.0f, -1.0f);
    glVertex3f(-.20f, 1.20f, 1.0f);
	glVertex3f(.20f, 1.20f, 1.2f);
	glVertex3f(.20f, 1.10f, 1.2f);
    glVertex3f(-.20f, 1.10f, 1.0f);

    // back
    glNormal3f(0.0, 0.0f, 1.0f);
    glVertex3f(-.20f, 1.20f, 0.9f);
	glVertex3f(.20f, 1.20f, 1.1f);
	glVertex3f(.20f, 1.10f, 1.1f);
    glVertex3f(-.20f, 1.10f, 0.9f);

    // left
    glNormal3f(1.0, 0.0f, 0.0f);
    glVertex3f(-.20f, 1.20f, 0.9f);
	glVertex3f(-.20f, 1.20f, 1.0f);
	glVertex3f(-.20f, 1.10f, 1.0f);
    glVertex3f(-.20f, 1.10f, 0.9f);

    // right
    glNormal3f(-1.0, 0.0f, 0.0f);
    glVertex3f(.20f, 1.20f, 1.1f);
	glVertex3f(.20f, 1.20f, 1.2f);
	glVertex3f(.20f, 1.10f, 1.2f);
    glVertex3f(.20f, 1.10f, 1.1f);


    // top
    glNormal3f(0.0, -1.0f, 0.0f);
    glVertex3f(-.20f, 1.20f, 0.9f);
	glVertex3f(.20f, 1.20f, 1.1f);
	glVertex3f(.20f, 1.20f, 1.2f);
	glVertex3f(-.20f, 1.20f, 1.0f);


    glEnd();





    // left 4th

    /// right big child
    glBegin(GL_QUADS);

    glColor3f(1,1,1);

    // 4th top
    // front
    glNormal3f(0.0, 0.0f, -1.0f);
    glVertex3f(1.20f, 1.20f, 1.2f);
	glVertex3f(1.60f, 1.20f, 1.0f);
	glVertex3f(1.60f, 1.10f, 1.0f);
    glVertex3f(1.20f, 1.10f, 1.2f);



    // back
    glNormal3f(0.0, 0.0f, 1.0f);
    glVertex3f(1.20f, 1.20f, 1.1f);
	glVertex3f(1.60f, 1.20f, 0.9f);
	glVertex3f(1.60f, 1.10f, 0.9f);
    glVertex3f(1.20f, 1.10f, 1.1f);

    // left
    glNormal3f(1.0, 0.0f, 0.0f);
    glVertex3f(1.20f, 1.20f, 1.1f);
	glVertex3f(1.20f, 1.20f, 1.2f);
	glVertex3f(1.20f, 1.10f, 1.2f);
    glVertex3f(1.20f, 1.10f, 1.1f);

    // right
    glNormal3f(-1.0, 0.0f, 0.0f);
    glVertex3f(1.60f, 1.20f, 0.9f);
	glVertex3f(1.60f, 1.20f, 1.0f);
	glVertex3f(1.60f, 1.10f, 1.0f);
    glVertex3f(1.60f, 1.10f, 0.9f);


    // top
    glNormal3f(0.0, -1.0f, 0.0f);
    glVertex3f(1.20f, 1.20f, 1.2f);
	glVertex3f(1.60f, 1.20f, 1.0f);
	glVertex3f(1.60f, 1.20f, 0.9f);
	glVertex3f(1.20f, 1.20f, 1.1f);





	/// 4th left


    // back
    glNormal3f(0.0, 0.0f, 1.0f);
    glVertex3f(1.20f, 1.10f, 1.1f);
	glVertex3f(1.30f, 1.10f, 1.1f);
	glVertex3f(1.30f, -1.10f, 1.1f);
    glVertex3f(1.20f, -1.10f, 1.1f);

    // front
    glNormal3f(0.0, 0.0f, -1.0f);
    glVertex3f(1.20f, 1.10f, 1.2f);
	glVertex3f(1.30f, 1.10f, 1.2f);
	glVertex3f(1.30f, -1.10f, 1.2f);
    glVertex3f(1.20f, -1.10f, 1.2f);

    // left
    glNormal3f(1.0, 0.0f, 0.0f);
    glVertex3f(1.20f, 1.10f, 1.1f);
    glVertex3f(1.20f, 1.10f, 1.2f);
    glVertex3f(1.20f, -1.10f, 1.2f);
    glVertex3f(1.20f, -1.10f, 1.1f);

    // right
    glNormal3f(-1.0, 0.0f, 0.0f);
    glVertex3f(1.30f, 1.10f, 1.1f);
    glVertex3f(1.30f, 1.10f, 1.2f);
    glVertex3f(1.30f, -1.10f, 1.2f);
    glVertex3f(1.30f, -1.10f, 1.1f);

    // 4th right

    // back
    glNormal3f(0.0, 0.0f, 1.0f);
    glVertex3f(1.60f, 1.10f, 0.9f);
	glVertex3f(1.50f, 1.10f, 0.9f);
	glVertex3f(1.50f, -1.10f, 0.9f);
    glVertex3f(1.60f, -1.10f, 0.9f);

    // front
    glNormal3f(0.0, 0.0f, -1.0f);
    glVertex3f(1.60f, 1.10f, 1.0f);
	glVertex3f(1.50f, 1.10f, 1.0f);
	glVertex3f(1.50f, -1.10f, 1.0f);
    glVertex3f(1.60f, -1.10f, 1.0f);

    // left
    glNormal3f(1.0, 0.0f, 0.0f);
    glVertex3f(1.50f, 1.10f, 0.9f);
    glVertex3f(1.50f, 1.10f, 1.0f);
    glVertex3f(1.50f, -1.10f, 1.0f);
    glVertex3f(1.50f, -1.10f, 0.9f);

    // right
    glNormal3f(-1.0, 0.0f, 0.0f);
    glVertex3f(1.60f, 1.10f, 0.9f);
    glVertex3f(1.60f, 1.10f, 1.0f);
    glVertex3f(1.60f, -1.10f, 1.0f);
    glVertex3f(1.60f, -1.10f, 0.9f);


    glEnd();






    // left 1st
    /// little child
    glBegin(GL_QUADS);

    glColor3f(1,1,1);



    // 1st left

    // back
    glNormal3f(0.0, 0.0f, 1.0f);
    glVertex3f(-.80f, .50f, 0.8f);
	glVertex3f(-.70f, .50f, 0.8f);
	glVertex3f(-.70f, -1.10f, 0.8f);
    glVertex3f(-.80f, -1.10f, 0.8f);

    // front
    glNormal3f(0.0, 0.0f, -1.0f);
    glVertex3f(-.80f, .50f, 0.9f);
	glVertex3f(-.70f, .50f, 0.9f);
	glVertex3f(-.70f, -1.10f, 0.9f);
    glVertex3f(-.80f, -1.10f, 0.9f);

    // right
    glNormal3f(-1.0, 0.0f, 0.0f);
    glVertex3f(-.70f, .50f, 0.8f);
    glVertex3f(-.70f, .50f, 0.9f);
    glVertex3f(-.70f, -1.10f, 0.9f);
    glVertex3f(-.70f, -1.10f, 0.8f);

    // left
    glNormal3f(1.0, 0.0f, 0.0f);
    glVertex3f(-.80f, .50f, 0.8f);
    glVertex3f(-.80f, .50f, 0.9f);
    glVertex3f(-.80f, -1.10f, 0.9f);
    glVertex3f(-.80f, -1.10f, 0.8f);


    // 1st right

    // back
    glNormal3f(0.0, 0.0f, 1.0f);
    glVertex3f(-.40f, .50f, 1.0f);
	glVertex3f(-.50f, .50f, 1.0f);
	glVertex3f(-.50f, -1.10f, 1.0f);
    glVertex3f(-.40f, -1.10f, 1.0f);


    // front
    glNormal3f(0.0, 0.0f, -1.0f);
    glVertex3f(-.40f, .50f, 1.1f);
	glVertex3f(-.50f, .50f, 1.1f);
	glVertex3f(-.50f, -1.10f, 1.1f);
    glVertex3f(-.40f, -1.10f, 1.1f);

    // left
    glNormal3f(1.0, 0.0f, 0.0f);
    glVertex3f(-.50f, .50f, 1.0f);
    glVertex3f(-.50f, .50f, 1.1f);
    glVertex3f(-.50f, -1.10f, 1.1f);
    glVertex3f(-.50f, -1.10f, 1.0f);

    // right
    glNormal3f(-1.0, 0.0f, 0.0f);
    glVertex3f(-.40f, .50f, 1.0f);
    glVertex3f(-.40f, .50f, 1.1f);
    glVertex3f(-.40f, -1.10f, 1.1f);
    glVertex3f(-.40f, -1.10f, 1.0f);


    // 1st top

    // front
    glNormal3f(0.0, 0.0f, -1.0f);
    glVertex3f(-.80f, .60f, 0.9f);
	glVertex3f(-.40f, .60f, 1.1f);
	glVertex3f(-.40f, .50f, 1.1f);
    glVertex3f(-.80f, .50f, 0.9f);

    // back
    glNormal3f(0.0, 0.0f, 1.0f);
    glVertex3f(-.80f, .60f, 0.8f);
	glVertex3f(-.40f, .60f, 1.0f);
	glVertex3f(-.40f, .50f, 1.0f);
    glVertex3f(-.80f, .50f, 0.8f);


    // left
    glNormal3f(1.0, 0.0f, 0.0f);
    glVertex3f(-.80f, .50f, 0.8f);
	glVertex3f(-.80f, .60f, 0.8f);
	glVertex3f(-.80f, .60f, 0.9f);
	glVertex3f(-.80f, .50f, 0.9f);

    // right
    glNormal3f(-1.0, 0.0f, 0.0f);
    glVertex3f(-.40f, .50f, 1.0f);
	glVertex3f(-.40f, .60f, 1.0f);
	glVertex3f(-.40f, .60f, 1.1f);
	glVertex3f(-.40f, .50f, 1.1f);

	// top
    glNormal3f(0.0, -1.0f, 0.0f);
	glVertex3f(-.80f, .60f, 0.8f);
	glVertex3f(-.40f, .60f, 1.0f);
	glVertex3f(-.40f, .60f, 1.1f);
	glVertex3f(-.80f, .60f, 0.9f);


    glEnd();


    //left 5th



    glBegin(GL_QUADS);

    glColor3f(1,1,1);


    // 5th left


    // back
    glNormal3f(0.0, 0.0f, 1.0f);
    glVertex3f(1.70f, .50f, 1.0f);
	glVertex3f(1.80f, .50f, 1.0f);
	glVertex3f(1.80f, -1.10f, 1.0f);
    glVertex3f(1.70f, -1.10f, 1.0f);

    // front
    glNormal3f(0.0, 0.0f, -1.0f);
    glVertex3f(1.70f, .50f, 1.1f);
	glVertex3f(1.80f, .50f, 1.1f);
	glVertex3f(1.80f, -1.10f, 1.1f);
    glVertex3f(1.70f, -1.10f, 1.1f);

    // left
    glNormal3f(1.0, 0.0f, 0.0f);
    glVertex3f(1.70f, .50f, 1.0f);
    glVertex3f(1.70f, .50f, 1.1f);
    glVertex3f(1.70f, -1.10f, 1.1f);
    glVertex3f(1.70f, -1.10f, 1.0f);


    // right
    glNormal3f(-1.0, 0.0f, 0.0f);
    glVertex3f(1.80f, .50f, 1.0f);
    glVertex3f(1.80f, .50f, 1.1f);
    glVertex3f(1.80f, -1.10f, 1.1f);
    glVertex3f(1.80f, -1.10f, 1.0f);




    // 5th right
    // back
    glNormal3f(0.0, 0.0f, 1.0f);
    glVertex3f(2.10f, .50f, 0.8f);
	glVertex3f(2.00f, .50f, 0.8f);
	glVertex3f(2.00f, -1.10f, 0.8f);
    glVertex3f(2.10f, -1.10f, 0.8f);

    // front
    glNormal3f(0.0, 0.0f, -1.0f);
    glVertex3f(2.10f, .50f, 0.9f);
	glVertex3f(2.00f, .50f, 0.9f);
	glVertex3f(2.00f, -1.10f, 0.9f);
    glVertex3f(2.10f, -1.10f, 0.9f);

    // left
    glNormal3f(1.0, 0.0f, 0.0f);
    glVertex3f(2.00f, .50f, 0.8f);
    glVertex3f(2.00f, .50f, 0.9f);
    glVertex3f(2.00f, -1.10f, 0.9f);
    glVertex3f(2.00f, -1.10f, 0.8f);

    // right
    glNormal3f(-1.0, 0.0f, 0.0f);
    glVertex3f(2.10f, .50f, 0.8f);
    glVertex3f(2.10f, .50f, 0.9f);
    glVertex3f(2.10f, -1.10f, 0.9f);
    glVertex3f(2.10f, -1.10f, 0.8f);



    // 5th top
    // back
    glNormal3f(0.0, 0.0f, 1.0f);
    glVertex3f(1.70f, .60f, 1.0f);
	glVertex3f(2.10f, .60f, 0.8f);
	glVertex3f(2.10f, .50f, 0.8f);
    glVertex3f(1.70f, .50f, 1.0f);

    // front
    glNormal3f(0.0, 0.0f, -1.0f);
    glVertex3f(1.70f, .60f, 1.1f);
	glVertex3f(2.10f, .60f, 0.9f);
	glVertex3f(2.10f, .50f, 0.9f);
    glVertex3f(1.70f, .50f, 1.1f);

	// left
    glNormal3f(1.0, 0.0f, 0.0f);
    glVertex3f(1.7f, .50f, 1.0f);
	glVertex3f(1.7f, .60f, 1.0f);
	glVertex3f(1.7f, .60f, 1.1f);
	glVertex3f(1.7f, .50f, 1.1f);

    // right
    glNormal3f(-1.0, 0.0f, 0.0f);
    glVertex3f(2.1f, .50f, 0.8f);
	glVertex3f(2.1f, .60f, 0.8f);
	glVertex3f(2.1f, .60f, 0.9f);
	glVertex3f(2.1f, .50f, 0.9f);

	// top
	glNormal3f(0.0, -1.0f, 0.0f);
	glVertex3f(1.70f, .60f, 1.0f);
	glVertex3f(2.10f, .60f, 0.8f);
	glVertex3f(2.10f, .60f, 0.9f);
	glVertex3f(1.70f, .60f, 1.1f);


    glEnd();




    // left 3rd -- center


    /// Mother
    glColor3f(1.0f,1.0f, 1.0f);

    glBegin(GL_QUADS);


    // bottom

    // mother bottom left
    // back
    glNormal3f(0.0, 0.0f, 1.0f);
    glVertex3f(.35f, 1.20f, 1.0f);
	glVertex3f(.45f, 1.20f, 1.0f);
	glVertex3f(.45f, -1.01f, 1.0f);
    glVertex3f(.35f, -1.01f, 1.0f);


    // front
    glNormal3f(0.0, 0.0f, -1.0f);
    glVertex3f(.35f, 1.20f, 1.1f);
	glVertex3f(.45f, 1.20f, 1.1f);
	glVertex3f(.45f, -1.01f, 1.1f);
    glVertex3f(.35f, -1.01f, 1.1f);

    //left
    glNormal3f(1.0, 0.0f, 0.0f);
    glVertex3f(.35f, 1.20f, 1.0f);
    glVertex3f(.35f, 1.20f, 1.1f);
    glVertex3f(.35f, -1.01f, 1.1f);
    glVertex3f(.35f, -1.01f, 1.0f);

    //right
    glNormal3f(-1.0, 0.0f, 0.0f);
    glVertex3f(.45f, 1.20f, 1.0f);
    glVertex3f(.45f, 1.20f, 1.1f);
    glVertex3f(.45f, -1.01f, 1.1f);
    glVertex3f(.45f, -1.01f, 1.0f);

    // end mother bottom left






    // mother bottom center

    // front
    glNormal3f(0.0, 0.0f, -1.0f);
    glVertex3f(.75f, 1.20f, 1.1f);
	glVertex3f(.65f, 1.20f, 1.1f);
	glVertex3f(.65f, -1.01f, 1.1f);
    glVertex3f(.75f, -1.01f, 1.1f);

    // right
    glNormal3f(-1.0, 0.0f, 0.0f);
    glVertex3f(.75f, 1.20f, 1.0f);
    glVertex3f(.75f, 1.20f, 1.1f);
    glVertex3f(.75f, -1.01f, 1.1f);
    glVertex3f(.75f, -1.01f, 1.0f);

    // left
    glNormal3f(1.0, 0.0f, 0.0f);
    glVertex3f(.65f, 1.20f, 1.0f);
    glVertex3f(.65f, 1.20f, 1.1f);
    glVertex3f(.65f, -1.01f, 1.1f);
    glVertex3f(.65f, -1.01f, 1.0f);

    // back
    glNormal3f(0.0, 0.0f, 1.0f);
    glVertex3f(.75f, 1.20f, 1.0f);
	glVertex3f(.65f, 1.20f, 1.0f);
	glVertex3f(.65f, -1.01f, 1.0f);
    glVertex3f(.75f, -1.01f, 1.0f);

    // end mother bottom center




    // mother bottom right

    // back
    glNormal3f(0.0, 0.0f, 1.0f);
    glVertex3f(1.05f, 1.20f, 1.0f);
	glVertex3f(.95f, 1.20f, 1.0f);
	glVertex3f(.95f, -1.01f, 1.0f);
    glVertex3f(1.05f, -1.01f, 1.0f);

    // front
    glNormal3f(0.0, 0.0f, -1.0f);
    glVertex3f(1.05f, 1.20f, 1.1f);
	glVertex3f(.95f, 1.20f, 1.1f);
	glVertex3f(.95f, -1.01f, 1.1f);
    glVertex3f(1.05f, -1.01f, 1.1f);


    // left
    glNormal3f(1.0, 0.0f, 0.0f);
    glVertex3f(0.95f, 1.20f, 1.0f);
    glVertex3f(0.95f, 1.20f, 1.1f);
    glVertex3f(0.95f, -1.01f, 1.1f);
    glVertex3f(0.95f, -1.01f, 1.0f);

    // right
    glNormal3f(-1.0, 0.0f, 0.0f);
    glVertex3f(1.05f, 1.20f, 1.0f);
    glVertex3f(1.05f, 1.20f, 1.1f);
    glVertex3f(1.05f, -1.01f, 1.1f);
    glVertex3f(1.05f, -1.01f, 1.0f);

    // end mother bottom right






    // mother top


    // mother top left

    // back
    glNormal3f(0.0, 0.0f, 1.0f);
    glVertex3f(.35f, 1.20f, 1.0f);
	glVertex3f(.45f, 1.20f, 1.0f);
	glVertex3f(.45f, 1.60f, 0.6f);
    glVertex3f(.35f, 1.60f, 0.6f);

    // front
    glNormal3f(0.0, 0.0f, -1.0f);
    glVertex3f(.35f, 1.20f, 1.1f);
	glVertex3f(.45f, 1.20f, 1.1f);
	glVertex3f(.45f, 1.60f, 0.7f);
    glVertex3f(.35f, 1.60f, 0.7f);

    // left
    glNormal3f(1.0, 0.0f, 0.0f);
    glVertex3f(.35f, 1.20f, 1.0f);
    glVertex3f(.35f, 1.20f, 1.1f);
    glVertex3f(.35f, 1.60f, 0.7f);
    glVertex3f(.35f, 1.60f, 0.6f);

    // right
    glNormal3f(-1.0, 0.0f, 0.0f);
    glVertex3f(.45f, 1.20f, 1.0f);
    glVertex3f(.45f, 1.20f, 1.1f);
    glVertex3f(.45f, 1.60f, 0.7f);
    glVertex3f(.45f, 1.60f, 0.6f);

    // top
    glNormal3f(1.0, -1.0f, 0.0f);
    glVertex3f(.35f, 1.60f, 0.7f);
    glVertex3f(.45f, 1.60f, 0.7f);
    glVertex3f(.45f, 1.60f, 0.6f);
    glVertex3f(.35f, 1.60f, 0.6f);

    // end mother top left




    // mother top center

    // back
    glNormal3f(0.0, 0.0f, 1.0f);
    glVertex3f(.65f, 1.20f, 1.0f);
	glVertex3f(.75f, 1.20f, 1.0f);
	glVertex3f(.75f, 1.60f, 0.6f);
    glVertex3f(.65f, 1.60f, 0.6f);

    // front
    glNormal3f(0.0, 0.0f, -1.0f);
    glVertex3f(.65f, 1.20f, 1.1f);
	glVertex3f(.75f, 1.20f, 1.1f);
	glVertex3f(.75f, 1.60f, 0.7f);
    glVertex3f(.65f, 1.60f, 0.7f);

    // left
    glNormal3f(1.0, 0.0f, 0.0f);
    glVertex3f(.65f, 1.20f, 1.0f);
    glVertex3f(.65f, 1.20f, 1.1f);
    glVertex3f(.65f, 1.60f, 0.7f);
    glVertex3f(.65f, 1.60f, 0.6f);

    // right
    glNormal3f(-1.0, 0.0f, 0.0f);
    glVertex3f(.75f, 1.20f, 1.0f);
    glVertex3f(.75f, 1.20f, 1.1f);
    glVertex3f(.75f, 1.60f, 0.7f);
    glVertex3f(.75f, 1.60f, 0.6f);

    // top
    glNormal3f(1.0, -1.0f, 0.0f);
    glVertex3f(.65f, 1.60f, 0.7f);
    glVertex3f(.75f, 1.60f, 0.7f);
    glVertex3f(.75f, 1.60f, 0.6f);
    glVertex3f(.65f, 1.60f, 0.6f);

    // mother top center end




    // mother top right

    // back
    glNormal3f(0.0, 0.0f, 1.0f);
    glVertex3f(.95f, 1.20f, 1.0f);
	glVertex3f(1.05f, 1.20f, 1.0f);
	glVertex3f(1.05f, 1.60f, 0.6f);
    glVertex3f(.95f, 1.60f, 0.6f);

    // front
    glNormal3f(0.0, 0.0f, -1.0f);
    glVertex3f(.95f, 1.20f, 1.1f);
	glVertex3f(1.05f, 1.20f, 1.1f);
	glVertex3f(1.05f, 1.60f, 0.7f);
    glVertex3f(.95f, 1.60f, 0.7f);

    // left
    glNormal3f(1.0, 0.0f, 0.0f);
    glVertex3f(.95f, 1.20f, 1.0f);
    glVertex3f(.95f, 1.20f, 1.1f);
    glVertex3f(.95f, 1.60f, 0.7f);
    glVertex3f(.95f, 1.60f, 0.6f);

    // right
    glNormal3f(-1.0, 0.0f, 0.0f);
    glVertex3f(1.05f, 1.20f, 1.0f);
    glVertex3f(1.05f, 1.20f, 1.1f);
    glVertex3f(1.05f, 1.60f, 0.7f);
    glVertex3f(1.05f, 1.60f, 0.6f);


    // top
    glNormal3f(0.0, -1.0f, 0.0f);
    glVertex3f(.95f, 1.60f, 0.7f);
	glVertex3f(1.05f, 1.60f, 0.7f);
	glVertex3f(1.05f, 1.60f, 0.6f);
    glVertex3f(.95f, 1.60f, 0.76);

    // mother top right end




    // top top

    // back
    glNormal3f(0.0, 0.0f, 1.0f);
    glVertex3f(.35f, 1.60f, 0.6f);
    glVertex3f(1.05f, 1.60f, 0.6f);
    glVertex3f(1.05f, 1.50f, 0.7f);
    glVertex3f(.35f, 1.50f, 0.7f);

    // front
    glNormal3f(0.0, 0.0f, -1.0f);
    glVertex3f(.35f, 1.60f, 0.7f);
    glVertex3f(1.05f, 1.60f, 0.7f);
    glVertex3f(1.05f, 1.50f, 0.8f);
    glVertex3f(.35f, 1.50f, 0.8f);

    // left
    glNormal3f(1.0, 0.0f, 0.0f);
    glVertex3f(.35f, 1.60f, 0.7f);
    glVertex3f(.35f, 1.60f, 0.6);
    glVertex3f(.35f, 1.50f, 0.7f);
    glVertex3f(.35f, 1.50f, 0.8f);

    // right
    glNormal3f(-1.0, 0.0f, 0.0f);
    glVertex3f(1.05f, 1.60f, 0.7f);
    glVertex3f(1.05f, 1.60f, 0.6);
    glVertex3f(1.05f, 1.50f, 0.7f);
    glVertex3f(1.05f, 1.50f, 0.8f);

    // top
    glNormal3f(0.0, -1.0f, 0.0f);
    glVertex3f(.35f, 1.60f, 0.7f);
	glVertex3f(1.05f, 1.60f, 0.7f);
	glVertex3f(1.05f, 1.60f, 0.6f);
    glVertex3f(.35f, 1.60f, 0.76);



    glEnd();



    // red floor 1

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, _textureIdRedTile1);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);


	glPushMatrix();
	// top
	glTranslatef(0.0f, -0.81f, 0.0f);

    glColor3f(0.8,0.0,0.0);

    glBegin(GL_QUADS);


    glNormal3f(0.0, 1.0f, 0.0f);


    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-3.0f, 0.0f, 4.0f);
    glTexCoord2f(20.0f, 0.0f);
    glVertex3f(4.0f, 0.0f, 4.0f);
    glTexCoord2f(20.0f, 20.0f);
    glVertex3f(4.0f, 0.0f, -2.6f);
    glTexCoord2f(0.0f, 20.0f);
    glVertex3f(-3.0f, 0.0f, -2.6f);

    glEnd();

        // front

        glPushMatrix();
        glTranslatef(0.0f, 0.0f, 4.0f);

        glColor3f(0.8,0.0,0.0);

        glBegin(GL_QUADS);


        glNormal3f(0.0, 0.0f, -1.0f);


        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-3.0f, 0.0f, 0.0f);
        glTexCoord2f(20.0f, 0.0f);
        glVertex3f(4.0f, 0.0f, 0.0f);
        glTexCoord2f(20.0f, 0.5f);
        glVertex3f(4.0f, -0.10f, 0.0f);
        glTexCoord2f(0.0f, 0.5f);
        glVertex3f(-3.0f, -0.10f, 0.0f);

        glEnd();
        glPopMatrix();

        // back

        glPushMatrix();
        glTranslatef(0.0f, 0.0f, -2.6f);

        glColor3f(0.8,0.0,0.0);

        glBegin(GL_QUADS);


        glNormal3f(0.0, 0.0f, 1.0f);


        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-3.0f, 0.0f, 0.0f);
        glTexCoord2f(20.0f, 0.0f);
        glVertex3f(4.0f, 0.0f, 0.0f);
        glTexCoord2f(20.0f, 0.5f);
        glVertex3f(4.0f, -0.10f, 0.0f);
        glTexCoord2f(0.0f, 0.5f);
        glVertex3f(-3.0f, -0.10f, 0.0f);

        glEnd();
        glPopMatrix();

        // left


        glPushMatrix();
        glTranslatef(-3.0f, 0.0f, 0.0f);

        glColor3f(0.8,0.0,0.0);

        glBegin(GL_QUADS);


        glNormal3f(1.0, 0.0f, 0.0f);


        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, 4.0f);
        glTexCoord2f(20.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, -2.6f);
        glTexCoord2f(20.0f, 0.5f);
        glVertex3f(0.0f, -0.10f, -2.6f);
        glTexCoord2f(0.0f, 0.5f);
        glVertex3f(0.0f, -0.10f, 4.0f);

        glEnd();
        glPopMatrix();

        // right


        glPushMatrix();
        glTranslatef(4.0f, 0.0f, 0.0f);

        glColor3f(0.8,0.0,0.0);

        glBegin(GL_QUADS);


        glNormal3f(-1.0, 0.0f, 0.0f);


        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, 4.0f);
        glTexCoord2f(20.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, -2.6f);
        glTexCoord2f(20.0f, 0.5f);
        glVertex3f(0.0f, -0.10f, -2.6f);
        glTexCoord2f(0.0f, 0.5f);
        glVertex3f(0.0f, -0.10f, 4.0f);

        glEnd();
        glPopMatrix();



    glPopMatrix();
    glDisable(GL_TEXTURE_2D);


    // red floor 2

	glPushMatrix();
	// top
	glTranslatef(0.0f, -0.91f, 0.0f);

    glColor3f(0.8,0.0,0.0);

    glBegin(GL_QUADS);


    glNormal3f(0.0, 1.0f, 0.0f);


    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-3.0f, 0.0f, 4.0f);
    glTexCoord2f(20.0f, 0.0f);
    glVertex3f(4.0f, 0.0f, 4.0f);
    glTexCoord2f(20.0f, 20.0f);
    glVertex3f(4.0f, 0.0f, -2.8f);
    glTexCoord2f(0.0f, 20.0f);
    glVertex3f(-3.0f, 0.0f, -2.8f);

    glEnd();

        // front

        glPushMatrix();
        glTranslatef(0.0f, 0.0f, 4.0f);

        glColor3f(0.8,0.0,0.0);

        glBegin(GL_QUADS);


        glNormal3f(0.0, 0.0f, -1.0f);


        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-3.0f, 0.0f, 0.0f);
        glTexCoord2f(20.0f, 0.0f);
        glVertex3f(4.0f, 0.0f, 0.0f);
        glTexCoord2f(20.0f, 0.5f);
        glVertex3f(4.0f, -0.10f, 0.0f);
        glTexCoord2f(0.0f, 0.5f);
        glVertex3f(-3.0f, -0.10f, 0.0f);

        glEnd();
        glPopMatrix();

        // back

        glPushMatrix();
        glTranslatef(0.0f, 0.0f, -2.8f);

        glColor3f(0.8,0.0,0.0);

        glBegin(GL_QUADS);


        glNormal3f(0.0, 0.0f, 1.0f);


        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-3.0f, 0.0f, 0.0f);
        glTexCoord2f(20.0f, 0.0f);
        glVertex3f(4.0f, 0.0f, 0.0f);
        glTexCoord2f(20.0f, 0.5f);
        glVertex3f(4.0f, -0.10f, 0.0f);
        glTexCoord2f(0.0f, 0.5f);
        glVertex3f(-3.0f, -0.10f, 0.0f);

        glEnd();
        glPopMatrix();

        // left


        glPushMatrix();
        glTranslatef(-3.0f, 0.0f, 0.0f);

        glColor3f(0.8,0.0,0.0);

        glBegin(GL_QUADS);


        glNormal3f(1.0, 0.0f, 0.0f);


        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, 4.0f);
        glTexCoord2f(20.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, -2.8f);
        glTexCoord2f(20.0f, 0.5f);
        glVertex3f(0.0f, -0.10f, -2.8f);
        glTexCoord2f(0.0f, 0.5f);
        glVertex3f(0.0f, -0.10f, 4.0f);

        glEnd();
        glPopMatrix();

        // right


        glPushMatrix();
        glTranslatef(4.0f, 0.0f, 0.0f);

        glColor3f(0.8,0.0,0.0);

        glBegin(GL_QUADS);


        glNormal3f(-1.0, 0.0f, 0.0f);


        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, 4.0f);
        glTexCoord2f(20.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, -2.8f);
        glTexCoord2f(20.0f, 0.5f);
        glVertex3f(0.0f, -0.10f, -2.8f);
        glTexCoord2f(0.0f, 0.5f);
        glVertex3f(0.0f, -0.10f, 4.0f);

        glEnd();
        glPopMatrix();



    glPopMatrix();
    glDisable(GL_TEXTURE_2D);



    // red floor 3


	glPushMatrix();
	// top
	glTranslatef(0.0f, -1.01f, 0.0f);

    glColor3f(0.8,0.0,0.0);

    glBegin(GL_QUADS);


    glNormal3f(0.0, 1.0f, 0.0f);


    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-3.0f, 0.0f, 4.0f);
    glTexCoord2f(20.0f, 0.0f);
    glVertex3f(4.0f, 0.0f, 4.0f);
    glTexCoord2f(20.0f, 20.0f);
    glVertex3f(4.0f, 0.0f, -3.0f);
    glTexCoord2f(0.0f, 20.0f);
    glVertex3f(-3.0f, 0.0f, -3.0f);

    glEnd();

        // front

        glPushMatrix();
        glTranslatef(0.0f, 0.0f, 4.0f);

        glColor3f(0.8,0.0,0.0);

        glBegin(GL_QUADS);


        glNormal3f(0.0, 0.0f, -1.0f);


        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-3.0f, 0.0f, 0.0f);
        glTexCoord2f(20.0f, 0.0f);
        glVertex3f(4.0f, 0.0f, 0.0f);
        glTexCoord2f(20.0f, 0.5f);
        glVertex3f(4.0f, -0.10f, 0.0f);
        glTexCoord2f(0.0f, 0.5f);
        glVertex3f(-3.0f, -0.10f, 0.0f);

        glEnd();
        glPopMatrix();

        // back

        glPushMatrix();
        glTranslatef(0.0f, 0.0f, -3.0f);

        glColor3f(0.8,0.0,0.0);

        glBegin(GL_QUADS);


        glNormal3f(0.0, 0.0f, 1.0f);


        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(-3.0f, 0.0f, 0.0f);
        glTexCoord2f(20.0f, 0.0f);
        glVertex3f(4.0f, 0.0f, 0.0f);
        glTexCoord2f(20.0f, 0.5f);
        glVertex3f(4.0f, -0.10f, 0.0f);
        glTexCoord2f(0.0f, 0.5f);
        glVertex3f(-3.0f, -0.10f, 0.0f);

        glEnd();
        glPopMatrix();

        // left


        glPushMatrix();
        glTranslatef(-3.0f, 0.0f, 0.0f);

        glColor3f(0.8,0.0,0.0);

        glBegin(GL_QUADS);


        glNormal3f(1.0, 0.0f, 0.0f);


        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, 4.0f);
        glTexCoord2f(20.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, -3.0f);
        glTexCoord2f(20.0f, 0.5f);
        glVertex3f(0.0f, -0.10f, -3.0f);
        glTexCoord2f(0.0f, 0.5f);
        glVertex3f(0.0f, -0.10f, 4.0f);

        glEnd();
        glPopMatrix();

        // right


        glPushMatrix();
        glTranslatef(4.0f, 0.0f, 0.0f);

        glColor3f(0.8,0.0,0.0);

        glBegin(GL_QUADS);


        glNormal3f(-1.0, 0.0f, 0.0f);


        glTexCoord2f(0.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, 4.0f);
        glTexCoord2f(20.0f, 0.0f);
        glVertex3f(0.0f, 0.0f, -3.0f);
        glTexCoord2f(20.0f, 0.5f);
        glVertex3f(0.0f, -0.10f, -3.0f);
        glTexCoord2f(0.0f, 0.5f);
        glVertex3f(0.0f, -0.10f, 4.0f);

        glEnd();
        glPopMatrix();



    glPopMatrix();
    glDisable(GL_TEXTURE_2D);




    //Grass texture floor

    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, _textureIdGrass);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glPushMatrix();
	glTranslatef(0.5f, -1.11f, 0.0f);

    glColor3f(0.0,1.0,0.0);
    glBegin(GL_QUADS);

    glNormal3f(0.0, 1.0f, 0.0f);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-20.0f, 0.0f, 20.0f);
    glTexCoord2f(40.0f, 0.0f);
    glVertex3f(20.0f, 0.0f, 20.0f);
    glTexCoord2f(40.0f, 40.0f);
    glVertex3f(20.0f, 0.0f, -20.0f);
    glTexCoord2f(0.0f, 40.0f);
    glVertex3f(-20.0f, 0.0f, -20.0f);

    glEnd();

    glPopMatrix();
    glDisable(GL_TEXTURE_2D);

    // wall
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, _textureIdRedBreak);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glPushMatrix();
	glTranslatef(0.5f, -1.11f, 0.0f);

	glColor3f(1.0,0.0,0.0);
	glBegin(GL_QUADS);

    glNormal3f(0.0, 0.0f, -1.0f);

    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-20.0f, 0.0f, 20.0f);
    glTexCoord2f(6.0f, 0.0f);
    glVertex3f(20.0f, 0.0f, 20.0f);
    glTexCoord2f(6.0f, 1.0f);
    glVertex3f(20.0f, 2.0f, 20.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-20.0f, 2.0f, 20.0f);


    glNormal3f(0.0, 0.0f, 1.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-20.0f, 0.0f, -20.0f);
    glTexCoord2f(6.0f, 0.0f);
    glVertex3f(20.0f, 0.0f, -20.0f);
    glTexCoord2f(6.0f, 1.0f);
    glVertex3f(20.0f, 2.0f, -20.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-20.0f, 2.0f, -20.0f);

    glNormal3f(1.0, 0.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(-20.0f, 0.0f, -20.0f);
    glTexCoord2f(6.0f, 0.0f);
    glVertex3f(-20.0f, 0.0f, 20.0f);
    glTexCoord2f(6.0f, 1.0f);
    glVertex3f(-20.0f, 2.0f, 20.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(-20.0f, 2.0f, -20.0f);

    glNormal3f(-1.0, 0.0f, 0.0f);
    glTexCoord2f(0.0f, 0.0f);
    glVertex3f(20.0f, 0.0f, -20.0f);
    glTexCoord2f(6.0f, 0.0f);
    glVertex3f(20.0f, 0.0f, 20.0f);
    glTexCoord2f(6.0f, 1.0f);
    glVertex3f(20.0f, 2.0f, 20.0f);
    glTexCoord2f(0.0f, 1.0f);
    glVertex3f(20.0f, 2.0f, -20.0f);


	glEnd();

    glPopMatrix();
    glDisable(GL_TEXTURE_2D);



///tree
glPushMatrix();

    glColor3f(1,1,1);
    glTranslated(-1.27,0.5,-3.49);
    glRotatef( rotate_x, 0.0, 1.0, 0.0 );

    glutSolidSphere(0.45,10,10);
    //new
    //glPushMatrix();
    glColor3f(0,0,0);
    glTranslated(-0.0,0.1,0.05);
    glutSolidSphere(0.43,10,10);

    glTranslated(-0.16,0.0,-0.5);
    glutSolidSphere(0.09,10,10);
    glTranslated(.40,0.0,-0.0);
    glutSolidSphere(0.09,10,10);

    glTranslated(-0.34,-0.40,-1.2);

    glBegin(GL_QUADS);
    glVertex3f(0.2f, 0.10f, 1.3f);
	glVertex3f(.10f, 0.10f, 1.3f);
	glVertex3f(.10f, .30f, 1.1f);
    glVertex3f(.2f, .30f, 1.1f);

    glVertex3f(.10f, .30f, 1.1f);
    glVertex3f(.2f, .30f, 1.1f);
    glVertex3f(.2f, .40f, 1.5f);
    glVertex3f(.10f, .40f, 1.5f);
    glEnd();

    glTranslated(-.1,-.10,0.1);
    glBegin(GL_QUADS);
    glVertex3f(0.38f, 0.12f, 1.25f);
	glVertex3f(0.08f, 0.10f, 1.25f);
	glVertex3f(0.08f, 0.20f, 1.1f);
    glVertex3f(0.38f,  0.20f, 1.15f);


      glEnd();


      //glPopMatrix();
     glTranslated(-1.15,-0.0,.75);



     myFunction(1,-0.7,1,0.7,.7,.4);
     myFunction(1.1,-1.0,0.8,0.4,0.15,0.2);
     myFunction(1.4,-1.0,0.8,0.4,0.15,0.2);


 glTranslated(0.2,-0.0,-.2);
     myFunction(0.65,-0.1,1,0.1,0.4,0.1);
      glTranslated(-0.45,-0.0,.0);
   myFunction(1.7,-0.1,1,0.1,0.4,0.1);
         glTranslated(0.05,-.2,0.0);
    glColor3f(0,0,0);

        myFunction(1.95,-0.3,1,0.4,0.1,0.1);
                 glTranslated(0.35,0.0,0.0);

             myFunction(0.7,-0.3,1,0.4,0.1,0.1);



     //end
   glPopMatrix();

///2nd man

glPushMatrix();
     glTranslated(4.0,0.0,-1.0);
    glColor3f(1,1,1);
    glTranslated(-1.27,0.5,-3.49);
    glRotatef( rotate_x, 0.0, 1.0, 0.0 );

    glutSolidSphere(0.45,10,10);
    //new
    //glPushMatrix();
    glColor3f(0,0,0);
    glTranslated(-0.0,0.1,0.07);
    glutSolidSphere(0.43,10,10);

    glTranslated(-0.16,0.0,-0.5);
    glutSolidSphere(0.09,10,10);
    glTranslated(.40,0.0,-0.0);
    glutSolidSphere(0.09,10,10);

    glTranslated(-0.34,-0.40,-1.2);

    glBegin(GL_QUADS);
    glVertex3f(0.2f, 0.10f, 1.3f);
	glVertex3f(.10f, 0.10f, 1.3f);
	glVertex3f(.10f, .30f, 1.1f);
    glVertex3f(.2f, .30f, 1.1f);

    glVertex3f(.10f, .30f, 1.1f);
    glVertex3f(.2f, .30f, 1.1f);
    glVertex3f(.2f, .40f, 1.5f);
    glVertex3f(.10f, .40f, 1.5f);
    glEnd();

    glTranslated(-.1,-.10,0.1);
    glBegin(GL_QUADS);
    glVertex3f(0.38f, 0.12f, 1.25f);
	glVertex3f(0.08f, 0.10f, 1.25f);
	glVertex3f(0.08f, 0.20f, 1.1f);
    glVertex3f(0.38f,  0.20f, 1.15f);


      glEnd();


      //glPopMatrix();
     glTranslated(-1.15,-0.0,.75);



     myFunction(1,-0.7,1,0.7,.7,.4);
     myFunction(1.1,-1.0,0.8,0.4,0.15,0.2);
     myFunction(1.4,-1.0,0.8,0.4,0.15,0.2);


 glTranslated(0.2,-0.0,-.2);
     myFunction(0.65,-0.1,1,0.1,0.4,0.1);
      glTranslated(-0.45,-0.0,.0);
   myFunction(1.7,-0.1,1,0.1,0.4,0.1);
         glTranslated(0.05,-.2,0.0);
    glColor3f(0,0,0);

        myFunction(1.95,-0.3,1,0.4,0.1,0.1);
                 glTranslated(0.35,0.0,0.0);

             myFunction(0.7,-0.3,1,0.4,0.1,0.1);



     //end
   glPopMatrix();



///2nd man end


glPushMatrix();
    glColor3f(0,1,0);
    glTranslated(-4.97,-0.55,6.49);
    glutSolidSphere(0.25,10,10);
    glPopMatrix();
glPushMatrix();
    glColor3f(0,1,0);
    glTranslated(4.97,-0.55,6.49);
    glutSolidSphere(0.25,10,10);
    glPopMatrix();
glPushMatrix();
    glColor3f(0,1,0);
    glTranslated(7.97,-0.55,-7.49);
    glutSolidSphere(0.25,10,10);
    glPopMatrix();

glPushMatrix();
    glColor3f(0,1,0);
    glTranslated(-7.97,-0.55,-5.55);
    glutSolidSphere(0.25,10,10);
    glPopMatrix();




    if(night==0 && sun_moon_flag == 1) {
    ///sun
        glPushMatrix();
    glColor3f(1,1,.5);
    glTranslated(4.97,4.55,10.49);
    glutSolidSphere(0.5,10,10); // *** ???
    glPopMatrix();
    }
    if(night==1 && sun_moon_flag == 1) {
            ///moon
    glPushMatrix();
    glColor3f(1,1,1);
    glTranslated(-4.97,4.55,10.49);
    glutSolidSphere(0.5,10,10); // *** ???
    glPopMatrix();
    }





    // back red circle

    // front
    glPushMatrix();
    glNormal3f(0.0, 0.0f, -1.0f);
    glColor3f(1,0,0);
    glTranslatef(0.735f, 0.5f, 1.3f); //Move forward 5 units
    glBegin(GL_POLYGON);
    float radius = 0.7f;
    for(double i = 0; i < 2 * PI; i += PI / 10) //<-- Change this Value
    glVertex3f(cos(i) * radius, sin(i) * radius, 0.0);
    glEnd();
    glPopMatrix();

    // back
    glPushMatrix();
    glNormal3f(0.0, 0.0f, 1.0f);
    glColor3f(1,0,0);
    glTranslatef(0.735f, 0.5f, 1.29f); //Move forward 5 units
    glBegin(GL_POLYGON);
    radius = 0.7f;
    for(double i = 0; i < 2 * PI; i += PI / 10) //<-- Change this Value
    glVertex3f(cos(i) * radius, sin(i) * radius, 0.0);
    glEnd();
    glPopMatrix();



	glutSwapBuffers();
}

void timer(int value) {
	if (rotate_Flag == 1) angle += 0.25f;
	if (angle > 360) {
		angle -= 360;
	}

	skyAngle += 0.03;
	if (skyAngle > 360) {
		skyAngle -= 360;
	}


	glutPostRedisplay();
	glutTimerFunc(25, timer, 0);
}

//Makes the image into a texture, and returns the id of the texture
GLuint loadTexture(Image* image) {
	GLuint textureId;
	glGenTextures(1, &textureId); //Make room for our texture
	glBindTexture(GL_TEXTURE_2D, textureId); //Tell OpenGL which texture to edit
	//Map the image to the texture
	glTexImage2D(GL_TEXTURE_2D,                //Always GL_TEXTURE_2D
				 0,                            //0 for now
				 GL_RGB,                       //Format OpenGL uses for image
				 image->width, image->height,  //Width and height
				 0,                            //The border of the image
				 GL_RGB, //GL_RGB, because pixels are stored in RGB format
				 GL_UNSIGNED_BYTE, //GL_UNSIGNED_BYTE, because pixels are stored
				                   //as unsigned numbers
				 image->pixels);               //The actual pixel data
	return textureId; //Returns the id of the texture
}


void handleResize(int w, int h) {
    glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

void initRendering() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);


	Image* image = loadBMP("D:\\Class\\4.2\\Lab\\Computer Graphics\\Project\\ShohidMinar\\grass_texture.bmp");
	_textureIdGrass = loadTexture(image);
	delete image;


	image = loadBMP("D:\\Class\\4.2\\Lab\\Computer Graphics\\Project\\ShohidMinar\\red_tile_2.bmp");
	_textureIdRedTile1 = loadTexture(image);
	delete image;

	image = loadBMP("D:\\Class\\4.2\\Lab\\Computer Graphics\\Project\\ShohidMinar\\red_break.bmp");
	_textureIdRedBreak = loadTexture(image);
	delete image;

	image = loadBMP("D:\\Class\\4.2\\Lab\\Computer Graphics\\Project\\ShohidMinar\\sky_day.bmp");
	_textureIdSkyDay = loadTexture(image);
	delete image;

	image = loadBMP("D:\\Class\\4.2\\Lab\\Computer Graphics\\Project\\ShohidMinar\\sky_night.bmp");
	_textureIdSkyNight = loadTexture(image);
	delete image;


	t3dInit();
}




int main(int argc, char** argv) {

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(650, 350);

    R = 0.0; G = 0.4; B = 1.0;

	glutCreateWindow("SHAHID MINAR");
	initRendering();

	_scale = computeScale(STRS);

	glutDisplayFunc(drawScene);
	glutReshapeFunc(handleResize);
	glutSpecialFunc(keyboardkey);
	glutKeyboardFunc(handleKeypress);

	glutTimerFunc(25, timer, 0);
	glutMainLoop();
	return 0;
}
