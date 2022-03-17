#include<Windows.h>
#include<gl/glut.h>
#include<math.h>
#include<iostream>
#include <string.h>
#include "Maze.h"
#include <thread>
using namespace std;


void drawInitialForm();

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glViewport(0, 0, 1300.0, 650.0);
	glLoadIdentity();
	gluOrtho2D(0.0, 1300.0, 0.0, 650.0);
}

Point pos;
Maze maze = Maze();
Pacman pacman = Pacman();
void special(int key, int, int)
{

	switch (key)
	{
	case GLUT_KEY_LEFT:
		maze.NEW_DIRECTION = LEFT;
		
		break;
	case GLUT_KEY_UP:
		maze.NEW_DIRECTION = UP;
		break;
	case GLUT_KEY_RIGHT:
		maze.NEW_DIRECTION = RIGHT;
	

		break;
	case GLUT_KEY_DOWN:
		maze.NEW_DIRECTION = DOWN;
	
		break;
	}
}

void gameOverSpecial(int key, int, int)

{
	drawInitialForm();
}


void refresh(int extra) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	maze.movePacman();
	maze.drawMaze();
	glFlush();

	if (!maze.GAME_OVER && !maze.WIN)
	{
		glutTimerFunc(140, refresh, 0);
	}
	else {
		maze.SCORE = 0;
		glutSpecialFunc(gameOverSpecial);
		maze.WIN = false;
		maze.GAME_OVER = false;
	}
}

void drawInitialForm()
{
	pacman.i = 7;
	pacman.j = 14;
	glutSpecialFunc(special);


	maze.initMaze(pacman);
	glutTimerFunc(140, refresh, 0);
}

void main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(1300, 650);
	glutCreateWindow("Maze");
	init();
	glutSpecialFunc(special);
	glutDisplayFunc(drawInitialForm);
	glutMainLoop();
}