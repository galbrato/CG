/*
	Gabriel Simmel Nascimento - 9050232
	Victor Luiz Roquete Forbes - 9293394
	Marcos Cesar Ribeiro de Camargo - 9278045
	José Augusto Noronha de Menezes Neto - 9293049
*/

#include <math.h>
#include <GL/glut.h>

#include "draw.hpp"

#define HIGHLIGHTED 0.7f, 0.3f, 1.0f
#define NOT_HIGHLIGHTED 0.2f, 0.2f, 0.2f

// Color
GLfloat color[] = {0.0f, 0.0f, 0.0f, 1.0f};

void applyTransform(Transform *obj){
	glTranslatef(obj->position->x, obj->position->y + 0.7, obj->position->z);
	glScalef(obj->scale->x + 1.0, obj->scale->y + 1.0, obj->scale->z + 1.0);

	glRotatef(obj->rotation->x, 1.0f, 0.0f, 0.0f);
	glRotatef(obj->rotation->y, 0.0f, 1.0f, 0.0f);
	glRotatef(obj->rotation->z, 0.0f, 0.0f, 1.0f);
}

void drawTorus(Transform *torus, bool selected){
	applyTransform(torus);

	glNormal3d(0, 1, 0);
	color[0] = 1.0;
	color[1] = 1.2;
	color[2] = 1.3;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);

	glRotatef(90.0, 1.0, 0.0, 0.0);

	selected ? glColor3f(HIGHLIGHTED) : glColor3f(NOT_HIGHLIGHTED);
	glutSolidTorus(0.4, 0.7, 20.0, 20.0);
}

void drawCube(Transform *cube, bool selected){
	applyTransform(cube);

	glNormal3d(0, 1, 0);
	color[0] = 1.0;
	color[1] = 1.2;
	color[2] = 1.3;
	glMaterialfv(GL_FRONT, GL_DIFFUSE, color);

	selected ? glColor3f(HIGHLIGHTED) : glColor3f(NOT_HIGHLIGHTED);
	glutSolidCube(1.5);
}

void drawSky(){
	glColor3f(0.0, 0.0, 1.0);
	glutSolidTeapot(70.0);
}

void drawGround(double height){
	glBegin(GL_QUADS);

	glColor3f(255.0, 255.0, 255.0);
	glVertex3f(-30.0, height, -30.0);

	glColor3f(255.0, 0.0, 255.0);
	glVertex3f(-30.0, height, 30.0);

	glColor3f(255.0, 255.0, 0.0);
	glVertex3f( 30.0, height, 30.0);

	glColor3f(0.0, 255.0, 255.0);
	glVertex3f(30.0, height, -30.0);

	glEnd();

	drawSky();
}

void drawTeapot(Transform *teapot, bool selected){
	glPushMatrix();

	// Apllies transformations
	applyTransform(teapot);

	// Draws obj
	selected? glColor3f(HIGHLIGHTED): glColor3f(NOT_HIGHLIGHTED);
	glutSolidTeapot(0.7f);

	glPopMatrix();
}