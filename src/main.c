#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h"

int main()
{
	int i = 1, level = 1, choice = 1, bot = 1;
	int height = 0, widht = 0; // КООРДИНАТЫ
	char tableGame[TABLE_Y][TABLE_Y];	//Хранение доски и ходов игроков
	int outPutReplics = 0;
	int limitMovesX, limitMovesO;

	while (i == 1) {
		int gorizontScore, vertikalScore, leftDiagonalScore, rightDiagonalScore, gorizontScoreLeft, vertikalScoreLeft, leftDiagonalScoreLeft, rightDiagonalScoreLeft, hodBot = 0; // перменные для бота
		int left, right, up, down;
		int settings = 0;
		int menu = 0;
		menu = main_menu();

		if(menu == 1){// ИГРА

			struct Replica repl[67];
			result[1].num_moves = 0;
			result[2].num_moves = 0;
			result[3].num_moves = 0;
			FILE *replic;
			replic = fopen("data/replic/replic.txt", "r");
			i = 1;
			for(int i = 1; i <= 68; i++)
				fgets (repl[i].replics, 65, replic);

			fclose(replic);

			fill_gameboard(tableGame);
			int winExit = 0, winX = 0, winO = 0;

			do{
				print_gameboard(tableGame);
				
				if(vibor == 1 && bot == 1){
					limitMovesX = 50 - result[1].num_moves;
					limitMovesO = 50 - result[3].num_moves;
				}else if(vibor == 0 && bot == 1){
					limitMovesX = 50 - result[3].num_moves;
					limitMovesO = 50 - result[2].num_moves;
				}else if(bot == 0){
					limitMovesX = 50 - result[1].num_moves;
					limitMovesO = 50 - result[2].num_moves;
				}
				
				if(bot == 1){
					if((result[1].num_moves == 0 || result[2].num_moves == 0) && result[3].num_moves == 0){
						printf("\n\tBot: %s", repl[1 + rand()%(5 - 1 + 1)].replics);
					}else if(outPutReplics == 0){
						printf("\n\tBot: %s", repl[6 + rand()%(17 - 6 + 1)].replics);
					}else if(outPutReplics == 1){
						printf("\n\tBot: %s", repl[18 + rand()%(28 - 18 + 1)].replics);
					}else if(outPutReplics == 2){
						printf("\n\tBot: %s", repl[29 + rand()%(39 - 29 + 1)].replics);
					}else if(outPutReplics == 3){
						printf("\n\tBot: %s", repl[40 + rand()%(50 - 40 + 1)].replics);
					}
				}
				outPutReplics = 0;
		
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
					move_bot(tableGame, level, gorizontScore, vertikalScore, leftDiagonalScore, rightDiagonalScore, gorizontScoreLeft, vertikalScoreLeft, leftDiagonalScoreLeft, rightDiagonalScoreLeft, hodBot, left, right, down, up, choice, height, widht);
				}

				if(choice == 1 && bot != 1){// ЗДЕСЬ ОПРЕДЕЛЯЕТСЯ ОЧЕРЕДНОСТЬ ХОДОВ
					choice = 0;
				}else if(choice == 0 && bot != 1){
					choice = 1;
				}
				gorizontScore = 1, vertikalScore = 1, leftDiagonalScore = 1, rightDiagonalScore = 1, gorizontScoreLeft = 5, vertikalScoreLeft = 1, leftDiagonalScoreLeft = 1, rightDiagonalScoreLeft = 1;

			}while(winExit != 1);
			printf("\n\t\t\t[1] - Вернуться в меню\n\t\t\t[0] - Выйти из игры\n");
			input_nubmers_test(&menu);// ФУНКЦИЯ ПРОВЕРКИ ВВОДИМЫХ ЗНАЧЕНИЙ
			if(menu == 0)
				break;
		}

		if(menu == 2){// НАСТРОЙКИ
			game_settings(menu, &settings, &level, &choice, &bot);
		}

		if(menu == 3){
		    while(menu == 3){
			    system("clear");
			    printf("\t\t\t\t   ________\n");
			    printf("\t\t\t\t   |    | |\n");
			    printf("\t\t\t\t   |    | |\n");
			    printf("\t\t\t\t   |    | |\n");
			    printf("\t\t\t\t   \\    / /\n");
			    printf("\t\t\t\t    \\__/_/\n");
			    printf("\t\t\t\t     ____\n");
			    printf("\t\t\t\t    /  \\ \\\n");
			    printf("\t\t\t\t    \\__/_/\n");
			    printf("\n\n\t\t\t\tПРАВИЛА ИГРЫ\n\n\t\t\t\tВ гомоку играют\n\t\t\t\t2 игрока, в поле 9Х9\n\t\t\t\tили 19 Х 19 за Х и О\n\t\t\t\tу каждого из игроков\n\t\t\t\tцель собрать в ряд 5\n\t\t\t\tкрестов или нолей\n\n\t\t\t\t1.Выход в меню\n\t\t\t\t");
			    scanf("%d", &settings);
			    if(settings == 1)
				    menu = settings;
		    }
		}

		if(menu == 4){
		    while(menu == 4){
			    system("clear");
			    printf("\t\t\t\t       __\n");
			    printf("\t\t\t\t      / /\\\n");
			    printf("\t\t\t\t ____/_/  \\___\n");
			    printf("\t\t\t\t | |   ___   |\n");
			    printf("\t\t\t\t  \\ \\  \\_/  /\n");
			    printf("\t\t\t\t   \\_\\_   _/\n");
			    printf("\t\t\t\t     \\ \\ /\n");
			    printf("\t\t\t\t      || |\n");
			    printf("\t\t\t\t     ||___|\n");
			    FILE *winTabl;
			    i = 1;
			    winTabl = fopen("LeadTabl.txt", "r");
			    printf("\n\t\t\t\t№    Имя\tКоличество ходов");

			    for(int i = 1; i <= 10; i++){
				if(fscanf (winTabl, "%s%u", tablname[i].name, &(tablname[i].num_moves)) != EOF){
				    if(i < 10){
					    printf("\n\t\t\t\t%d  - %s\t\t%u", i, tablname[i].name, tablname[i].num_moves);
				    }else{
					    printf("\n\t\t\t\t%d - %s\t\t%u", i, tablname[i].name, tablname[i].num_moves); 
				    }
				}
			    }
			    fclose(winTabl);
			    printf("\n\n\t\t\t\t1.Выход в меню\n\t\t\t\t");
			    input_nubmers_test(&menu);
		    }

		if(menu == 5){// ВЫХОД
			break;
		}
	}

	return 0;
}