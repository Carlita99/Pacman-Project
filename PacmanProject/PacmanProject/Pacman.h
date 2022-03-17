#pragma once
#include "Structs.h"
#include "Geometry.h"


class Pacman
{
public:
	int i;
	int j;
	int Direction = 3;
	bool isopen = false;
	float* allCircleVerticesClosed;
	float* allCircleVerticesOpen;
	int numberOfVertices;
	Point eye;
	void initPacman(float r, GLint num_sides);
	void DrawPacman(Point center);
	void rotatePacman(float angle);
};

