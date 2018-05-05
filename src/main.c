#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h"

int main()
{
	int i = 1, level = 0, choice = 1, bot = 1;
	int height = 0, widht = 0; // КООРДИНАТЫ
	char tableGame[TABLE_Y][TABLE_Y];	//Хранение доски и ходов игроков

	while (i == 1) {
		int gorizontScore, vertikalScore, leftDiagonalScore, rightDiagonalScore, gorizontScoreLeft, vertikalScoreLeft, leftDiagonalScoreLeft, rightDiagonalScoreLeft, hodBot = 0; // перменные для бота
		int left, right, up, down;
		int settings = 0;
		int menu = 0;
		menu = main_menu();
	
		if(menu == 1){// ИГРА
			fill_gameboard(tableGame);
			int winExit = 0, winX = 0, winO = 0;

			do{
				print_gameboard(tableGame);

				if(winX == 1){
					printf("\n\n\t\t\tХ - ПОБЕДИЛ\a");
					winExit = 1;
				}else if(winO == 1){
					printf("\n\n\t\t\tO - ПОБЕДИЛ");
					winExit = 1;
				}

				entering_coord(choice, winExit, &height, &widht, tableGame);

				if((choice == 1 || choice == 0) && winExit != 1){
					check_to_win(tableGame, choice, widht, height, winExit, &winX, &winO, &gorizontScore, &vertikalScore, &leftDiagonalScore, &rightDiagonalScore, &gorizontScoreLeft, &vertikalScoreLeft, &leftDiagonalScoreLeft, &rightDiagonalScoreLeft, &left, &right, &up, &down);
				}

				if(winExit != 1 && bot == 1 && winO != 1 && winX != 1){
					gorizontScore = 6;
					printf("%d\n", gorizontScore);
					printf("%d\n", vertikalScore);
					printf("%d\n", leftDiagonalScore);
					printf("%d\n", rightDiagonalScore);
					scanf("%d", &winO);
					move_bot(tableGame, level, gorizontScore, vertikalScore, leftDiagonalScore, rightDiagonalScore, gorizontScoreLeft, vertikalScoreLeft, leftDiagonalScoreLeft, rightDiagonalScoreLeft, hodBot, &left, &right, choice, height, widht);
				}

				if(choice == 1 && bot != 1){// ЗДЕСЬ ОПРЕДЕЛЯЕТСЯ ОЧЕРЕДНОСТЬ ХОДОВ
					choice = 0;
				}else if(choice == 0 && bot != 1){
					choice = 1;
				}
				gorizontScore = 1, vertikalScore = 1, leftDiagonalScore = 1, rightDiagonalScore = 1, gorizontScoreLeft = 5, vertikalScoreLeft = 1, leftDiagonalScoreLeft = 1, rightDiagonalScoreLeft = 1;

			}while(winExit != 1);
		}

		if(menu == 2){// НАСТРОЙКИ
			game_settings(menu, &settings, &level, &choice, &bot);
		}

		if(menu == 3){// ПРАВИЛА ИГРЫ
		
		}

		if(menu == 4){// ЗАЛ СЛАВЫ

		}

		if(menu == 5){// ВЫХОД
			break;
		}
	}

	return 0;
}