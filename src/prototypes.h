#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

//Copyright. Конслольный вывод цветов и библиотека "term.h" реализованы на основе данного проекта: https://github.com/dlinyj/terminal_controller

#include "term.h"

/*ANSI/VT100 Terminal using example */


#define home() 			 printf(ESC "[H") //Move cursor to the indicated row, column (origin at 1,1)
#define clrscr()		 printf(ESC "[2J") //lear the screen, move to (1,1)
#define gotoxy(x,y)		 printf(ESC "[%d;%dH", y, x);
#define visible_cursor() printf(ESC "[?251");
/* 
Set Display Attribute Mode	<ESC>[{attr1};...;{attrn}m
*/
#define resetcolor()				printf(ESC "[0m")
#define set_display_atrib(color) 	printf(ESC "[%dm",color)

#define TABLE_Y 16

	struct winner{// ИСПОЛЬЗУЕТСЯ ДЛЯ ВЫВОДА ТАБЛИЦЫ ЛИДЕРОВ НА СТРАНИЦЕ ТАБЛИЦА ЛИДЕРОВ
    	char name[20];// ХРАНИТ ИМЕНА ПОБЕДИТЕЛЕЙ ИЗ ФАЙЛА
    	unsigned num_moves;// ХРАНИТ КОЛИЧЕСТВО ХОДОВ ЗА КОТОРОЕ ПОБЕДИЛ ПОБЕДИТЕЛЬ
	};

	struct Replica{// ИСПОЛЬЗУЕТСЯ ВО ВРЕМЯ ИГРЫ
    	char replics[100];// ХРАНИТ РЕПЛИКИ БОТА
	};

	struct afterVictory{// ИСПОЛЬЗУЕТСЯ ВО ВРЕМЯ ИГРЫ
		char name[20];// ХРАНИТ ИМЯ ПОБЕДИТЕЛЯ
		int num_moves;// ХРАНИТ КОЛИЧЕСТВО ХОДОВ ПОБЕДИТЕЛЯ
	};

	int correct_entering(int menu, int settings);

	int main_menu(void);

	void fill_gameboard(char gameboard_mass[TABLE_Y][TABLE_Y]);	

	void print_gameboard(char gameboard_mass[TABLE_Y][TABLE_Y],int limitMovesO, int limitMovesX);

	void entering_coord(int choice, int winExit, int *height, int *widht, char tableGame[TABLE_Y][TABLE_Y]);

	void prioritization(int level, int *playerScoreGorizont, int *playerScoreVertikal, int *playerScoreLeftDiagonal, int *playerScoreRightDiagonal, int  *playerScoreGorizontLeft, int *playerScoreVertikalLeft, int *playerScoreLeftDiagonalLeft, int *playerScoreRightDiagonalLeft, int *playerScore,  int *hightStepPlayer, int *weightStepPlayer, int dopusk, int *outPutReplics);

	void check_to_win(char tableGame[TABLE_Y][TABLE_Y], int choice, int widht, int height, int winExit, int *winX, int *winO, int *playerScoreGorizont, int *playerScoreVertikal, int *playerScoreLeftDiagonal, int *playerScoreRightDiagonal, int  *playerScoreGorizontLeft, int *playerScoreVertikalLeft, int *playerScoreLeftDiagonalLeft, int *playerScoreRightDiagonalLeft, int *hightStepPlayer, int *weightStepPlayer);

	void check_to_win_bot(char tableGame[TABLE_Y][TABLE_Y], int choice, int widht, int height, int winExit, int *winX, int *winO, int *playerScoreGorizont, int *playerScoreVertikal, int *playerScoreLeftDiagonal, int *playerScoreRightDiagonal, int  *playerScoreGorizontLeft, int *playerScoreVertikalLeft, int *playerScoreLeftDiagonalLeft, int *playerScoreRightDiagonalLeft, int *hightStepPlayer, int *weightStepPlayer);

	void move_bot_attacking(char tableGame[TABLE_Y][TABLE_Y], int botScore, int playerScore, int choice,  int *botScoreGorizont, int *botScoreVertikal, int *botScoreLeftDiagonal, int *botScoreRightDiagonal, int  *botScoreGorizontLeft, int *botScoreVertikalLeft, int *botScoreLeftDiagonalLeft, int *botScoreRightDiagonalLeft, int *hightAtakBot, int *weightAtakBot, int height, int widht, int *hodBot);

	void move_bot_defender(char tableGame[TABLE_Y][TABLE_Y], int *playerScoreGorizont, int *playerScoreVertikal, int *playerScoreLeftDiagonal, int *playerScoreRightDiagonal, int  *playerScoreGorizontLeft, int *playerScoreVertikalLeft, int *playerScoreLeftDiagonalLeft, int *playerScoreRightDiagonalLeft, int *hodBot, int choice, int height, int widht, int *hightAtakBot, int *weightAtakBot);

	void move_bot_easy(int level, char tableGame[TABLE_Y][TABLE_Y], int choice, int *hightAtakBot, int *weightAtakBot, int *hodBot, int *winX, int *winO, int height, int widht);
	
	char move_bot_gotizont(int choice, char tableGame[TABLE_Y][TABLE_Y], int *i, int height, int *hodBot, int exit, int *widht);

	char move_bot_vertical(int choice, char tableGame[TABLE_Y][TABLE_Y], int *i, int widht, int *hodBot, int exit, int *height);

	char move_bot_diagonal_minus(int j, int choice, char tableGame[TABLE_Y][TABLE_Y], int *i, int *widht, int *hodBot, int exit, int *height);

	char move_bot_diagonal_plus(int j, int choice, char tableGame[TABLE_Y][TABLE_Y], int *i, int *widht, int *hodBot, int exit, int *height);

	char step_attack_bot_gorizont(int vibor, char tableGame[TABLE_Y][TABLE_Y], int *i, int hight, int *hodBot, int exit, int *weight);

	char step_attack_bot_vertical(int vibor, char tableGame[TABLE_Y][TABLE_Y], int *i, int weight, int *hodBot, int exit, int *hight);

	char step_attack_bot_diagonal_plus(int j, int vibor, char tableGame[TABLE_Y][TABLE_Y], int *i, int *weight, int *hodBot, int exit, int *hight);
	
	char step_attack_bot_diagonal_minus(int j, int vibor, char tableGame[TABLE_Y][TABLE_Y], int *i, int *weight, int *hodBot, int exit, int *hight);
	
	void control(int exit, int i, int choice, char tableGame[TABLE_Y][TABLE_Y], int coord, int *score, int *spaceFinder, int hightCoordLeft, int hightCoordRight, int weightCoordLeft, int weightCoordRight, int *check, int checkTwo, int *zamok);

	int checkWin(int score, int choice, int *winX, int *winO);

	void game_settings(int menu, int *settings, int *level, int *choice, int *bot);
	
	void rules(int menu, int settings);
	
	void table_name(int menu, int settings, struct winner tablname[15]);

	void easter_egg(int menu, int settings);
