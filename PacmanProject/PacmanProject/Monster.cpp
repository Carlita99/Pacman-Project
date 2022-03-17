#include "Monster.h"
#include <GL/glut.h>
void Monster::drawMonsters(GLfloat x, GLfloat y, GLfloat radius) {
	glColor3f(0, 0, 128);

	//draw the body
	drawFilledCircle(x, y, radius);
	drawRectangle(x, y - radius / 2, radius * 2, radius);
	//draw the legs
	drawEllipse(x - radius / 3 * 2.2, y - radius, radius / 4, radius / 3);
	drawEllipse(x, y - radius, radius / 4, radius / 3);
	drawEllipse(x + radius / 3 * 2.2, y - radius, radius / 4, radius / 3);
	//draw the eyes
	glColor3f(255, 255, 255);
	drawEllipse(x - radius / 2, y + radius / 6, radius / 4, radius / 6 * 2);
	drawEllipse(x + radius / 2, y + radius / 6, radius / 4, radius / 6 * 2);

	glColor3f(0, 0, 0);
	drawEllipse(x - radius / 2, y + radius / 6, radius / 6, radius / 6);
	drawEllipse(x + radius / 2, y + radius / 6, radius / 6, radius / 6);

	//glFlush();
}