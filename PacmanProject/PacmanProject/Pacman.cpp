#include "Pacman.h"
#include <math.h>
#include <GL/glut.h>

void Pacman::initPacman(float r, GLint num_sides) {
	this->numberOfVertices = num_sides + 2;
	GLfloat doublePI = 2.0 * M_PI;
	GLfloat* circleVerticesX = new GLfloat[this->numberOfVertices];
	GLfloat* circleVerticesY = new GLfloat[this->numberOfVertices];
	GLfloat* circleVerticesZ = new GLfloat[this->numberOfVertices];

	circleVerticesX[0] = 0;
	circleVerticesY[0] = 0;
	circleVerticesZ[0] = 0;

	for (int i = 1; i < this->numberOfVertices; i++) {
		circleVerticesX[i] = (r * cos(i * doublePI / num_sides));
		circleVerticesY[i] = (r * sin(i * doublePI / num_sides));
		circleVerticesZ[i] = 0;
	}
	this->allCircleVerticesOpen = new GLfloat[this->numberOfVertices * 3];
	this->allCircleVerticesClosed = new GLfloat[this->numberOfVertices * 3];

	for (int i = 0; i < this->numberOfVertices; i++) {
		if (i > 17) {
			if (i == 20)
				continue;
			this->allCircleVerticesClosed[i * 3] = circleVerticesX[i];
			this->allCircleVerticesClosed[(i * 3) + 1] = circleVerticesY[i];
			this->allCircleVerticesClosed[(i * 3) + 2] = circleVerticesZ[i];
			continue;
		}
		this->allCircleVerticesOpen[i * 3] = this->allCircleVerticesClosed[i * 3] = circleVerticesX[i];
		this->allCircleVerticesOpen[(i * 3) + 1] = this->allCircleVerticesClosed[(i * 3) + 1] = circleVerticesY[i];
		this->allCircleVerticesOpen[(i * 3) + 2] = this->allCircleVerticesClosed[(i * 3) + 2] = circleVerticesZ[i];
	}
	this->eye.x = 4;
	this->eye.y = 7;

}

void Pacman::DrawPacman(Point center) {
	glColor3f(2.37, 2.34, 0.26);
	GLfloat* allCircleVertices = new float[this->numberOfVertices * 3];
	glEnableClientState(GL_VERTEX_ARRAY);
	if (this->isopen)
		for (int i = 0; i < this->numberOfVertices; i++) {
			allCircleVertices[i * 3] = this->allCircleVerticesOpen[i * 3] + center.x;
			allCircleVertices[i * 3 + 1] = this->allCircleVerticesOpen[i * 3 + 1] + center.y;
			allCircleVertices[i * 3 + 2] = this->allCircleVerticesOpen[i * 3 + 2];
		}
	else
		for (int i = 0; i < this->numberOfVertices; i++) {
			allCircleVertices[i * 3] = this->allCircleVerticesClosed[i * 3] + center.x;
			allCircleVertices[i * 3 + 1] = this->allCircleVerticesClosed[i * 3 + 1] + center.y;
			allCircleVertices[i * 3 + 2] = this->allCircleVerticesClosed[i * 3 + 2];
		}
	glVertexPointer(3, GL_FLOAT, 0, allCircleVertices);
	glDrawArrays(GL_TRIANGLE_FAN, 0, this->numberOfVertices);
	glDisableClientState(GL_VERTEX_ARRAY);
	dessinerPoint({ this->eye.x + center.x, this->eye.y + center.y });
}

void Pacman::rotatePacman(float angle) {

	GLdouble** R = getRotationMatrix(angle);
	GLdouble* P = new GLdouble[3];
	P[2] = 0;
	for (int i = 0; i < this->numberOfVertices; i++) {
		P[0] = this->allCircleVerticesClosed[i * 3];
		P[1] = this->allCircleVerticesClosed[i * 3 + 1];
		P = produitMatriceVecteur(R, P);
		this->allCircleVerticesClosed[i * 3] = P[0];
		this->allCircleVerticesClosed[i * 3 + 1] = P[1];

		P[0] = this->allCircleVerticesOpen[i * 3];
		P[1] = this->allCircleVerticesOpen[i * 3 + 1];
		P = produitMatriceVecteur(R, P);
		this->allCircleVerticesOpen[i * 3] = P[0];
		this->allCircleVerticesOpen[i * 3 + 1] = P[1];
	}
}

