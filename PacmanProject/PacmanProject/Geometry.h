#pragma once
#include <GL/glut.h>
#include "Structs.h"
#include <math.h>
#include "GlobalVariables.h"
inline void drawLine(Point p1, Point p2) {
	glColor3f(0.12, 0.30, 1.45);
	glBegin(GL_LINES);
	glVertex2f(p1.x, p1.y);
	glVertex2f(p2.x, p2.y);
	glEnd();
}
inline void dessinerPoint(Point point) {
	glColor3f(0.0, 0.0, 0.0);
	glPointSize(2.0f);
	glBegin(GL_POINTS);
	glVertex2i(point.x, point.y);
	glEnd();
}


inline void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius) {
	GLint i;
	GLint triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * 3.14;

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y); // center of circle
	for (i = 0; i <= triangleAmount; i++) {
		glVertex2f(
			x + (radius * cos(i * twicePi / triangleAmount)),
			y + (radius * sin(i * twicePi / triangleAmount))
		);
	}
	glEnd();
}


inline void drawEllipse(GLfloat x, GLfloat y, GLfloat radiusX, GLfloat radiusY)
{
	GLint i;
	GLint triangleAmount = 20; //# of triangles used to draw circle

	//GLfloat radius = 0.8f; //radius
	GLfloat twicePi = 2.0f * 3.14;

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x, y); // center of circle
	for (i = 0; i <= triangleAmount; i++) {
		glVertex2f(
			x + (radiusX * cos(i * twicePi / triangleAmount)),
			y + (radiusY * sin(i * twicePi / triangleAmount))
		);
	}
	glEnd();
}

inline void drawRectangle(GLfloat x, GLfloat y, GLfloat width, GLfloat height) {

	glBegin(GL_QUADS);
	glVertex2f(x - width / 2, y + height / 2);
	glVertex2f(x - width / 2, y - height / 2);
	glVertex2f(x + width / 2, y - height / 2);
	glVertex2f(x + width / 2, y + height / 2);
	glEnd();
}


inline GLdouble** getRotationMatrix(GLdouble theta)
{
	GLdouble** R = new GLdouble * [3];
	for (int i = 0; i < 3; ++i)
		R[i] = new GLdouble[3];
	R[0][0] = cos(theta);
	R[0][1] = -sin(theta);
	R[0][2] = 0;
	R[1][0] = sin(theta);
	R[1][1] = cos(theta);
	R[1][2] = 0;
	R[2][0] = 0;
	R[2][1] = 0;
	R[2][2] = 1;
	return R;
}

inline GLdouble* produitMatriceVecteur(GLdouble** M, GLdouble* V)
{
	GLdouble* Vp = new GLdouble[3];
	for (int i = 0; i < 3; i++)
		Vp[i] = 0;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			Vp[i] += M[i][j] * V[j];
	}
	return Vp;
}
