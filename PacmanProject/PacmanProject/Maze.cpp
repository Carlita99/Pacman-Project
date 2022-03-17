#include<Windows.h>
#include "Maze.h"
#include <string.h>
#include <iostream>
using namespace std;
void Maze::initMonsters() {
	for (GLint k = 0;k < 3;k++) {
		this->monsters[k] = new Monster();

	}
	monsters[0]->i = 16;
	monsters[0]->j = 13;
	monsters[1]->i = 16;
	monsters[1]->j = 13;
	monsters[2]->i = 16;
	monsters[2]->j = 13;
}

void Maze::initMaze(Pacman pacman) {
	this->initMonsters();
	this->pacman = pacman;
	this->startingPoint = { 50,20 };
	pacman.i = 7;
	pacman.j = 14;
	int temp[NUM_ROW][NUM_COL] = {
		//      00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, //30
				{1, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 3, 3, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 1}, //29
				{1, 7, 1, 1, 1, 1, 7, 1, 1, 1, 1, 1, 7, 3, 3, 7, 1, 1, 1, 1, 1, 7, 1, 1, 1, 1, 7, 1}, //28
				{1, 7, 1, 0, 0, 1, 7, 1, 0, 0, 0, 1, 7, 3, 3, 7, 1, 0, 0, 0, 1, 7, 1, 0, 0, 1, 7, 1}, //27
				{1, 7, 1, 1, 1, 1, 7, 1, 1, 1, 1, 1, 7, 1, 3, 7, 1, 1, 1, 1, 1, 7, 1, 1, 1, 1, 7, 1}, //26
				{1, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 1}, //25
				{1, 7, 2, 2, 2, 2, 7, 1, 1, 7, 1, 2, 2, 1, 1, 2, 2, 1, 7, 1, 1, 7, 2, 2, 2, 2, 7, 1}, //24
				{1, 7, 1, 2, 2, 1, 7, 3, 3, 7, 1, 2, 2, 4, 2, 2, 2, 1, 7, 3, 3, 7, 1, 2, 2, 1, 7, 1}, //23
				{1, 7, 7, 7, 7, 7, 7, 3, 3, 7, 7, 7, 7, 3, 3, 7, 7, 7, 7, 3, 3, 7, 7, 7, 7, 7, 7, 1}, //22
				{1, 1, 1, 1, 1, 1, 7, 3, 1, 2, 2, 2, 7, 3, 3, 7, 1, 2, 2, 3, 3, 7, 1, 1, 1, 1, 1, 1}, //21
				{0, 0, 0, 0, 0, 1, 7, 3, 2, 2, 2, 1, 7, 1, 1, 7, 1, 2, 2, 4, 3, 7, 1, 0, 0, 0, 0, 0}, //20
				{0, 0, 0, 0, 0, 1, 7, 3, 3, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 3, 3, 7, 1, 0, 0, 0, 0, 0}, //19
				{0, 0, 0, 0, 0, 1, 7, 3, 3, 7, 1, 1, 8, 8, 8, 8, 1, 1, 7, 3, 3, 7, 1, 0, 0, 0, 0, 0}, //18
				{1, 1, 1, 1, 1, 1, 7, 1, 1, 7, 1, 0, 0, 0, 0, 0, 0, 1, 7, 1, 1, 7, 1, 1, 1, 1, 1, 1}, //17
				{7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 1, 0, 0, 6, 0, 0, 0, 1, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7}, //16
				{1, 1, 1, 1, 1, 1, 7, 1, 1, 7, 1, 0, 0, 0, 0, 0, 0, 1, 7, 1, 1, 7, 1, 1, 1, 1, 1, 1}, //15
				{0, 0, 0, 0, 0, 1, 7, 3, 3, 7, 1, 1, 1, 1, 1, 1, 1, 1, 7, 3, 3, 7, 1, 0, 0, 0, 0, 0}, //14
				{0, 0, 0, 0, 0, 1, 7, 3, 3, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 3, 3, 7, 1, 0, 0, 0, 0, 0}, //13
				{0, 0, 0, 0, 0, 1, 7, 3, 3, 7, 1, 2, 2, 1, 1, 2, 2, 1, 7, 3, 3, 7, 1, 0, 0, 0, 0, 0}, //12
				{1, 1, 1, 1, 1, 1, 7, 1, 1, 7, 1, 2, 2, 4, 2, 2, 2, 1, 7, 1, 1, 7, 1, 1, 1, 1, 1, 1}, //11
				{1, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 3, 3, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 1}, //10
				{1, 7, 1, 2, 2, 1, 7, 1, 2, 2, 2, 1, 7, 3, 3, 7, 1, 2, 2, 2, 1, 7, 1, 2, 2, 1, 7, 1}, //09
				{1, 7, 1, 2, 4, 1, 7, 1, 2, 2, 2, 1, 7, 1, 1, 7, 1, 2, 2, 2, 1, 7, 3, 2, 2, 1, 7, 1}, //08
				{1, 7, 7, 7, 3, 3, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 3, 3, 7, 7, 7, 1}, //07
				{1, 2, 1, 7, 3, 3, 7, 1, 1, 7, 1, 2, 2, 1, 1, 2, 2, 1, 7, 1, 1, 7, 3, 3, 7, 1, 2, 1}, //06
				{2, 2, 1, 7, 1, 1, 7, 3, 3, 7, 1, 2, 2, 4, 2, 2, 2, 1, 7, 3, 3, 7, 1, 1, 7, 1, 2, 2}, //05
				{1, 7, 7, 7, 7, 7, 7, 3, 3, 7, 7, 7, 7, 3, 3, 7, 7, 7, 7, 3, 3, 7, 7, 7, 7, 7, 7, 1}, //04
				{1, 7, 1, 2, 2, 2, 2, 3, 1, 2, 2, 1, 7, 3, 3, 7, 2, 2, 2, 3, 1, 2, 2, 2, 2, 1, 7, 1}, //03
				{1, 7, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 7, 1, 1, 7, 1, 2, 2, 2, 2, 2, 2, 2, 2, 1, 7, 1}, //02
				{1, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 1}, //01
				{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}  //00
	};

	for (int i = 0; i < NUM_ROW; i++)
		for (int j = 0; j < NUM_COL; j++)
			this->map[NUM_ROW - 1 - i][j] = temp[i][j];

	this->map[this->pacman.i][this->pacman.j] = PACMAN_NUM;
	this->pacman.initPacman(10, 20);

}

void Maze::drawFood(Point p) {
	glColor3f(1.0, 1.0, 1.0);
	glPointSize(3);
	glBegin(GL_POINTS);
	glVertex2f(p.x, p.y);
	glEnd();
	//glFlush();
}

void Maze::drawPortal(Point p1, Point p2) {
	glLineWidth(3);
	glColor3f(0.54, 0.47, 0.46);
	glBegin(GL_LINES);
	glVertex2f(p1.x, p1.y);
	glVertex2f(p2.x, p2.y);
	glEnd();
	glLineWidth(1);
}

void Maze::checkWin() {
	for (GLint i = 0;i < NUM_ROW;i++)
		for (GLint j = 0;i < NUM_COL;j++)
			if (this->map[i][j] == FOOD_NUM)
				return;
	this->WIN = true;

}

void Maze::drawMonsters(GLfloat x, GLfloat y, GLfloat radius) {
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


void Maze::drawMaze() {
	for (int i = 0; i < NUM_ROW; i++)
		for (int j = 0; j < NUM_COL; j++) {
			if (this->map[i][j] == FOOD_NUM) {
				drawFood({ this->startingPoint.x + STEP_SIZE * j,  this->startingPoint.y + STEP_SIZE * i });
				continue;
			}
			if (this->map[i][j] == PORTAL_NUM) {
				this->drawPortal({ this->startingPoint.x + STEP_SIZE * (j - 1), this->startingPoint.y + STEP_SIZE * i },
					{ this->startingPoint.x + STEP_SIZE * (j + 1), this->startingPoint.y + STEP_SIZE * i });
				continue;
			}
			if (this->map[i][j] == PACMAN_NUM) {
				this->pacman.DrawPacman({ this->startingPoint.x + STEP_SIZE * j, this->startingPoint.y + STEP_SIZE * i });
				continue;
			}
			if (this->map[i][j] == MONSTER_NUM) {
				this->drawMonsters(this->startingPoint.x + STEP_SIZE * j, this->startingPoint.y + STEP_SIZE * i, 10);
				continue;
			}
			if (this->map[i][j] == WALL_NUM || this->map[i][j] == HORIZ_WALL_NUM) {
				if (j != NUM_COL - 1 && (this->map[i][j + 1] == WALL_NUM || this->map[i][j + 1] == HORIZ_WALL_NUM || this->map[i][j + 1] == VERT_WALL_NUM || this->map[i][j + 1] == POINT_WALL_NUM)) {
					drawLine({ this->startingPoint.x + STEP_SIZE * j,  this->startingPoint.y + STEP_SIZE * i },
						{ this->startingPoint.x + STEP_SIZE * (j + 1),  this->startingPoint.y + STEP_SIZE * i });
				}
			}
			if (this->map[i][j] == WALL_NUM || this->map[i][j] == VERT_WALL_NUM) {
				if (i != NUM_ROW - 1 && (this->map[i + 1][j] == WALL_NUM || this->map[i + 1][j] == HORIZ_WALL_NUM || this->map[i + 1][j] == VERT_WALL_NUM || this->map[i + 1][j] == POINT_WALL_NUM)) {
					drawLine({ this->startingPoint.x + STEP_SIZE * j,  this->startingPoint.y + STEP_SIZE * i },
						{ this->startingPoint.x + STEP_SIZE * j,  this->startingPoint.y + STEP_SIZE * (i + 1) });
				}
			}
		}
	char score[6];
	char scoreText[200];
	int charCounter = 0;
	int tempScore;
	tempScore = SCORE;
	score[5] = '\0';
	int num;
	while (tempScore != 0) {
		num = tempScore % 10;
		score[4 - charCounter] = '0' + num;
		tempScore /= 10;
		charCounter++;
	}
	for (int i = 0; i < 5 - charCounter; i++) {
		score[i] = '0';
	}
	if (this->GAME_OVER)
		strcpy_s(scoreText, "GAME OVER \n Press any key to try again \n SCORE: ");
	else if (this->WIN) {
		cout << "WON" << endl;
		strcpy_s(scoreText, "YOU WON! SCORE: ");
	}
	else
		strcpy_s(scoreText, "SCORE: ");

	strcat_s(scoreText, score);

	glRasterPos2f(700, 450); //position of text
	for (int i = 0; i < strlen(scoreText); i++)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, scoreText[i]);
	}
}

void Maze::moveMonsters(Monster* monster) {
	if (this->map[monster->i][monster->j] == PACMAN_NUM)
	{
		this->GAME_OVER = true;
		return;
	}
	if (monster->previousValue == FOOD_NUM)
		this->map[monster->i][monster->j] = monster->previousValue;
	else 	if (monster->previousValue == MONSTER_NUM)
	{
		this->map[monster->i][monster->j] = FOOD_NUM;

	}
	else
	{
		this->map[monster->i][monster->j] = EMPTY_NUM;

	}

	if (monster->NEW_DIRECTION == UP) {
		if (!((this->map[monster->i + 1][monster->j] >= 1 && this->map[monster->i + 1][monster->j] <= 4))) {
			monster->i++;
		}
		else {
			GLint random = rand() % 2;
			if (random == 1)
				monster->NEW_DIRECTION = LEFT;
			else
				monster->NEW_DIRECTION = RIGHT;

		}

	}
	else if (monster->NEW_DIRECTION == DOWN) {
		if (!((this->map[monster->i - 1][monster->j] >= 1 && this->map[monster->i - 1][monster->j] <= 4))) {

			monster->i--;
		}
		else {
			GLint random = rand() % 2;
			if (random == 1)
				monster->NEW_DIRECTION = LEFT;
			else
				monster->NEW_DIRECTION = RIGHT;
		}
	}
	if (monster->NEW_DIRECTION == LEFT) {
		if (!((this->map[monster->i][monster->j - 1] >= 1 && this->map[monster->i][monster->j - 1] <= 4))) {
			monster->j--;
		}
		else {
			GLint random = rand() % 2;
			if (random == 1)
				monster->NEW_DIRECTION = UP;
			else
				monster->NEW_DIRECTION = DOWN;
		}

	}
	if (monster->NEW_DIRECTION == RIGHT) {
		if (!((this->map[monster->i][monster->j + 1] >= 1 && this->map[monster->i][monster->j + 1] <= 4))) {

			monster->j++;
		}
		else {
			GLint random = rand() % 2;
			if (random == 1)
				monster->NEW_DIRECTION = UP;
			else
				monster->NEW_DIRECTION = DOWN;
		}
	}
	monster->previousValue = this->map[monster->i][monster->j];
	if (this->map[monster->i][monster->j] == PACMAN_NUM)
	{
		this->GAME_OVER = true;
		return;
	}
	this->map[monster->i][monster->j] = MONSTER_NUM;



}

void Maze::movePacman() {

	this->pacman.isopen = !this->pacman.isopen;
	this->map[this->pacman.i][this->pacman.j] = EMPTY_NUM;
	float angle = (NEW_DIRECTION - this->pacman.Direction) * M_PI / 2;

	if (angle != 0) {
		this->pacman.rotatePacman(angle);
	}
	this->pacman.Direction = NEW_DIRECTION;
	if (this->pacman.Direction == UP) {
		if (this->pacman.i == NUM_ROW - 1) {
			if (this->map[0][this->pacman.j] == FOOD_NUM)
				SCORE += 50;
			this->pacman.i = 0;
		}
		else if (!((this->map[this->pacman.i + 1][this->pacman.j] >= 1 && this->map[this->pacman.i + 1][this->pacman.j] <= 4) || this->map[this->pacman.i + 1][this->pacman.j] == PORTAL_NUM)) {
			if (this->map[this->pacman.i + 1][this->pacman.j] == FOOD_NUM)
				SCORE += 50;
			this->pacman.i++;
		}
	}
	else if (this->pacman.Direction == DOWN) {
		if (this->pacman.i == 0) {
			if (this->map[NUM_ROW - 1][this->pacman.j] == FOOD_NUM)
				SCORE += 50;
			this->pacman.i = NUM_ROW - 1;
		}
		else if (!((this->map[this->pacman.i - 1][this->pacman.j] >= 1 && this->map[this->pacman.i - 1][this->pacman.j] <= 4) || this->map[this->pacman.i - 1][this->pacman.j] == PORTAL_NUM)) {
			if (this->map[this->pacman.i - 1][this->pacman.j] == FOOD_NUM)
				SCORE += 50;
			this->pacman.i--;
		}
	}
	else if (this->pacman.Direction == LEFT) {
		if (this->pacman.j == 0) {
			if (this->map[this->pacman.i][NUM_COL - 1] == FOOD_NUM)
				SCORE += 50;
			this->pacman.j = NUM_COL - 1;
		}
		else if (!((this->map[this->pacman.i][this->pacman.j - 1] >= 1 && this->map[this->pacman.i][this->pacman.j - 1] <= 4) || this->map[this->pacman.i][this->pacman.j - 1] == PORTAL_NUM)) {
			if (this->map[pacman.i][pacman.j - 1] == FOOD_NUM)
				SCORE += 50;
			this->pacman.j--;
		}
	}
	else if (this->pacman.Direction == RIGHT) {
		if (this->pacman.j == NUM_COL - 1) {
			if (this->map[this->pacman.i][0] == FOOD_NUM)
				SCORE += 50;
			this->pacman.j = 0;
		}
		else if (!((this->map[this->pacman.i][this->pacman.j + 1] >= 1 && this->map[this->pacman.i][this->pacman.j + 1] <= 4) || this->map[this->pacman.i][this->pacman.j + 1] == PORTAL_NUM)) {
			if (this->map[this->pacman.i][this->pacman.j + 1] == FOOD_NUM)
				SCORE += 50;
			this->pacman.j++;
		}
	}
	this->map[this->pacman.i][this->pacman.j] = PACMAN_NUM;
	this->checkWin();
	for (Monster* monster : this->monsters)
	{
		moveMonsters(monster);

	}
}
