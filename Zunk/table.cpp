#include <bits/stdc++.h>
#include <Windows.h>
#include <GL/glut.h>



void rot() {
	glRotated(50, 0, 1, 0);
	glRotated(10, -1, 0, 0);
	glRotated(11.7, 0, 0, -1);
}

void obj(double tx, double ty, double tz, double sx, double sy, double sz)
{
	rot();

	glTranslated(tx, ty, tz);
	glScaled(sx, sy, sz);
	glutSolidCube(1);
	glLoadIdentity();
}

void disp() {
	glViewport(0, 0, 700, 700);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(0, 0, 0, .3);

	//walls
	//obj(0, 0, .5, 1, 1, .04);
	//obj(0, -.5, 0, 1, .04, 1);
	//obj(-.5, 0, 0, .04, 1, 1);

	//legs
	obj(0, -.3, 0, 0.02, 0.2, 0.02);
	obj(0, -.3, -.4, 0.02, 0.2, 0.02);
	obj(.4, -.3, 0, 0.02, 0.2, 0.02);
	obj(.4, -.3, -.4, 0.02, 0.2, 0.02);

	//tt
	obj(0.2, -.18, -0.2, .6, .02, -.6);

	//rot();

	glTranslated(0.3, -.1, -.3);
	//glutSolidTeapot(.09);

	glFlush();
	glLoadIdentity();
}

int main(int argc, char **argv) {
	float ambient[] = { 1,1,1,1 };
	float light[] = { 27,80,2,3 };

	glutInit(&argc, argv);
	glutInitWindowSize(1000, 1000);
	glutCreateWindow("tp");
	glutDisplayFunc(disp);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glMaterialfv(GL_FRONT, GL_AMBIENT, ambient);
	glLightfv(GL_LIGHT0, GL_POSITION, light);
	glutMainLoop();
}
