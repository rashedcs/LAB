#include <windows.h>
#include <bits/stdc++.h>
#include <GL/glut.h>
using namespace std;

struct Color
{
  int r;
  int g;
  int b;
};
    Color oldColor = {1, 0, 0};
	Color newColor = {1, 1, 0};


void setPixelColor(int x, int y, Color color) {
	glColor3f(color.r, color.g, color.b);
	glBegin(GL_POINTS);
		glVertex2i(x, y);
	glEnd();
	glFlush();
}
void delay(float ms){
    clock_t goal = ms + clock();
    while(goal>clock());
}

void init(){
    glClearColor(0.0,0.0,0.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0,640,0,480);
}

void floodFill(int x, int y, Color oldColor, Color newColor)
{
        Color color;
        glReadPixels(x,y,1.0,1.0,GL_RGB,GL_FLOAT,&color);
        if(color.r == oldColor.r && color.g == oldColor.g && color.b == oldColor.b)
        {
            setPixelColor(x, y, newColor);
            floodFill(x+1, y, oldColor, newColor);
            floodFill(x, y+1, oldColor, newColor);
            floodFill(x-1, y, oldColor, newColor);
            floodFill(x, y-1, oldColor, newColor);
        }
}

void mouse(int btn, int state, int x, int y){
    if(btn==GLUT_LEFT_BUTTON)
    {
        if(state==GLUT_DOWN)
        {
            glReadPixels(15,20,1.0,1.0,GL_RGB,GL_FLOAT, &oldColor);
            floodFill(x,y, oldColor, newColor);
        }
    }
}

void world(){
    glPointSize(2);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
        glVertex2i(15,10);
        glVertex2i(155,200);
        glVertex2i(305,10);
    glEnd();
    glFlush();
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(200,200);
    glutCreateWindow("Many Amaze Very GL WOW");
    glutDisplayFunc(world);
    glutMouseFunc(mouse);
    init();
    glutMainLoop();
    return 0;
}
