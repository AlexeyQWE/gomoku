#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

#include "term.h"

/*ANSI/VT100 Terminal using example */


#define home() 			printf(ESC "[H") //Move cursor to the indicated row, column (origin at 1,1)
#define clrscr()		printf(ESC "[2J") //lear the screen, move to (1,1)
#define gotoxy(x,y)		printf(ESC "[%d;%dH", y, x);
#define visible_cursor() printf(ESC "[?251");
/* 
Set Display Attribute Mode	<ESC>[{attr1};...;{attrn}m
*/
#define resetcolor() printf(ESC "[0m")
#define set_display_atrib(color) 	printf(ESC "[%dm",color)

#define TABLE_Y 16

	void neoWords(const char * str);

	int correct_entering(int menu, int settings);

	int main_menu(void);

	void fill_gameboard(char gameboard_mass[TABLE_Y][TABLE_Y]);	

	void print_gameboard(char gameboard_mass[TABLE_Y][TABLE_Y]);

	void entering_coord(int choice, int winExit, int *height, int *widht, char tableGame[TABLE_Y][TABLE_Y]);

	void check_to_win(char tableGame[TABLE_Y][TABLE_Y], int choice, int widht, int height, int winExit, int *winX, int *winO, int *gorizontScore, int *vertikalScore, int *leftDiagonalScore, int *rightDiagonalScore, int *gorizontScoreLeft, int *vertikalScoreLeft, int *leftDiagonalScoreLeft, int *rightDiagonalScoreLeft, int *left, int *right, int *up, int *down);

	void move_bot(char tableGame[TABLE_Y][TABLE_Y], int level, int gorizontScore, int vertikalScore, int leftDiagonalScore, int rightDiagonalScore, int gorizontScoreLeft, int vertikalScoreLeft, int leftDiagonalScoreLeft, int rightDiagonalScoreLeft, int hodBot, int left, int right, int down, int up, int choice, int *height, int *widht);

	char move_bot_gotizont(int choice, char tableGame[TABLE_Y][TABLE_Y], int *i, int height, int *hodBot, int exit, int *widht);

	char move_bot_vertical(int choice, char tableGame[TABLE_Y][TABLE_Y], int *i, int widht, int *hodBot, int exit, int *height);

	char move_bot_diagonal_minus(int j, int choice, char tableGame[TABLE_Y][TABLE_Y], int *i, int *widht, int *hodBot, int exit, int *height);

	char move_bot_diagonal_plus(int j, int choice, char tableGame[TABLE_Y][TABLE_Y], int *i, int *widht, int *hodBot, int exit, int *height);

	void control(int exit, int i, int choice, char tableGame[TABLE_Y][TABLE_Y], int coord, int *score, int *spaceFinder, int hightCoordLeft, int hightCoordRight, int weightCoordLeft, int weightCoordRight, int *check, int checkTwo);

	int checkWin(int score, int choice, int *winX, int *winO);

	void game_settings(int menu, int *settings, int *level, int *choice, int *bot);
