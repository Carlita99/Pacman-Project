#pragma once
#include "Monster.h"
#include <GL/glut.h>
#include "GlobalVariables.h"
void drawEllipse(GLfloat x, GLfloat y, GLfloat radiusX, GLfloat radiusY);
void drawFilledCircle(GLfloat x, GLfloat y, GLfloat radius);
void drawRectangle(GLfloat x, GLfloat y, GLfloat width, GLfloat height);
class Monster
{
public: 
	void drawMonsters(GLfloat x, GLfloat y, GLfloat radius);
	GLint i, j;
	GLint NEW_DIRECTION = UP;
	GLint previousValue=EMPTY_NUM;
};

