#pragma once
#include <GL/glut.h>
#include "GlobalVariables.h"
#include "Pacman.h"
#include "Monster.h"



class Maze
{
public:
	Point startingPoint;
	Pacman pacman;
	bool GAME_OVER;
	bool WIN;
	int SCORE = 0;
	void checkWin();
	int NEW_DIRECTION = RIGHT;
	int map[NUM_ROW][NUM_COL];
	void initMaze(Pacman pacman);
	void drawMaze();
	void movePacman();
	void drawFood(Point p);
	void drawPortal(Point p1, Point p2);
	void drawMonsters(GLfloat x, GLfloat y, GLfloat radius);
	void moveMonsters(Monster * monster);
	void initMonsters();
	Monster * monsters[3];
};

