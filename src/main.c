#include "prototypes.h"
#include <stdio.h>

int main()
{
	int i = 1, level = 2, choice = 0, bot = 1, otladka = 1;
	int height = 0, widht = 0; // КООРДИНАТЫ
	char tableGame[TABLE_Y][TABLE_Y];	//Хранение доски и ходов игроков
	int outPutReplics = 0;
	int limitMovesX, limitMovesO;
	struct winner tablname[15];
	struct afterVictory result[11];

	while (i == 1) {
		int hodBot = 0; // перменные для бота
		int settings = 0;
		int menu = 0;
		int playerScore = 0;
		menu = main_menu();
		if(menu == 1){// ИГРА
			struct Replica repl[67];
			result[1].num_moves = 0;
			result[2].num_moves = 0;
			result[3].num_moves = 0;
			FILE *replic;
			replic = fopen("data/replic/replics.txt", "r");
			i = 1;
			for(int i = 1; i <= 68; i++)
				fgets (repl[i].replics, 65, replic);

			fclose(replic);
				/*массивы для анализа ботом*/
			int botScoreGorizont[9] = {'\0'};
			int botScoreVertikal[9] = {'\0'};
			int botScoreLeftDiagonal[9] = {'\0'};
			int botScoreRightDiagonal[9] = {'\0'};
			int botScoreGorizontLeft[9] = {'\0'};
			int botScoreVertikalLeft[9] = {'\0'};
			int botScoreLeftDiagonalLeft[9] = {'\0'};
			int botScoreRightDiagonalLeft[9] = {'\0'};
			int hightStepPlayer[9] = {'\0'};
			int weightStepPlayer[9] = {'\0'};
			int hightAtakBot[9] = {'\0'};
			int weightAtakBot[9] = {'\0'};
			int playerScoreGorizont[9] = {'\0'};
			int playerScoreVertikal[9] = {'\0'};
			int playerScoreLeftDiagonal[9] = {'\0'};
			int playerScoreRightDiagonal[9] = {'\0'};
			int playerScoreGorizontLeft[9] = {'\0'};
			int playerScoreVertikalLeft[9] = {'\0'};
			int playerScoreLeftDiagonalLeft[9] = {'\0'};
			int playerScoreRightDiagonalLeft[9] = {'\0'};

			fill_gameboard(tableGame);
			int winExit = 0, winX = 0, winO = 0, scoreHandPlayer = 0, botScore = 0;
			int dopusk = 0;

			do{
				if(choice == 0 && bot == 1 && settings == 0){// ЕСЛИ БОТ ХОДИТ ПЕРВЫМ, ТО ОН ХОДИТ В РАНДОМНУЮ ТОЧКУ ИГРОВОГО ПОЛЯ
					tableGame[7][8] = 'X';
					settings = 20;
					for(int i = 0; i < 9; i++){
						hightAtakBot[i] = 7;
						weightAtakBot[i] = 8;
					}
				}

				if(choice == 1 && bot == 1){
					limitMovesX = 50 - result[1].num_moves;
					limitMovesO = 50 - result[3].num_moves;
				}else if(choice == 0 && bot == 1){
					limitMovesX = 50 - result[3].num_moves;
					limitMovesO = 50 - result[2].num_moves;
				}else if(bot == 0){
					limitMovesX = 50 - result[1].num_moves;
					limitMovesO = 50 - result[2].num_moves;
				}

				
				if(otladka == 1 && bot == 1){
					debugging_player(hightStepPlayer, weightStepPlayer, playerScoreGorizont,  playerScoreVertikal, playerScoreLeftDiagonal, playerScoreRightDiagonal, playerScoreGorizontLeft,  playerScoreVertikalLeft, playerScoreLeftDiagonalLeft, playerScoreRightDiagonalLeft);
					debugging_bot(hightAtakBot, weightAtakBot, botScoreGorizont,  botScoreVertikal, botScoreLeftDiagonal, botScoreRightDiagonal, botScoreGorizontLeft,  botScoreVertikalLeft, botScoreLeftDiagonalLeft, botScoreRightDiagonalLeft);
					printf("\nplayerScore %d", playerScore);
					printf("\nbotScore %d", botScore);
				}
				
				print_gameboard(tableGame, limitMovesO, limitMovesX);

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
					set_display_atrib(BRIGHT);
					set_display_atrib(F_YELLOW);
					printf("\n\n\t\t\tХ - ПОБЕДИЛ\a");
					resetcolor();
					winExit = 1;
				}else if(winO == 1){
					set_display_atrib(BRIGHT);
					set_display_atrib(F_YELLOW);
					printf("\n\n\t\t\tO - ПОБЕДИЛ");
					resetcolor();
					winExit = 1;
				}
				if(winExit != 1){
					entering_coord(choice, winExit, &height, &widht, tableGame);
				}

				if(((choice == 0 || choice == 1) && (level == 1 || level == 0 || level == 2) && settings != 300) && bot == 1){
					hightStepPlayer[8] = height;
					weightStepPlayer[8] = widht;
					settings = 300;
				}
	
				if(bot == 1){
					if(scoreHandPlayer != 8){
						hightStepPlayer[scoreHandPlayer] = height;
						weightStepPlayer[scoreHandPlayer] = widht;
					}else if(scoreHandPlayer == 8){
						scoreHandPlayer = 0;
					}
					scoreHandPlayer++;
				}

				// ПОДСЧЕТ ХОДОВ ИГРОКА
				if(choice == 1){
					tableGame[height][widht] = 'X';
					result[1].num_moves++;
					if(result[1].num_moves > 50)
						winO = 1;
				}else{
					tableGame[height][widht] = 'O';
					result[2].num_moves++;
					if(result[2].num_moves > 50)
						winX = 1;
				}

				if(winExit == 0){
					print_gameboard(tableGame);
					printf("\n\t\t");

					sleep(1);
				}

				if((choice == 1 || choice == 0) && winExit != 1){
					check_to_win(tableGame, choice, widht, height, winExit, &winX, &winO, playerScoreGorizont, playerScoreVertikal, playerScoreLeftDiagonal, playerScoreRightDiagonal, playerScoreGorizontLeft, playerScoreVertikalLeft, playerScoreLeftDiagonalLeft, playerScoreRightDiagonalLeft, hightStepPlayer, weightStepPlayer);
				}

				if((level == 2 || level == 0) && bot == 0){
					prioritization(level, playerScoreGorizont, playerScoreVertikal, playerScoreLeftDiagonal, playerScoreRightDiagonal, playerScoreGorizontLeft, playerScoreVertikalLeft, playerScoreLeftDiagonalLeft, playerScoreRightDiagonalLeft, &playerScore, hightStepPlayer, weightStepPlayer, dopusk);
				}

				if(otladka == 1 && bot == 1){
					debugging_player(hightStepPlayer, weightStepPlayer, playerScoreGorizont,  playerScoreVertikal, playerScoreLeftDiagonal, playerScoreRightDiagonal, playerScoreGorizontLeft,  playerScoreVertikalLeft, playerScoreLeftDiagonalLeft, playerScoreRightDiagonalLeft);
				}
				

				if((choice == 1 || choice == 0) && winExit != 1 && level == 2){
					if(choice == 1){
						choice = 0;
					}else if(choice == 0){
						choice = 1;
					}
					check_to_win_bot(tableGame, choice, widht, height, winExit, &winX, &winO, botScoreGorizont, botScoreVertikal, botScoreLeftDiagonal, botScoreRightDiagonal, botScoreGorizontLeft, botScoreVertikalLeft, botScoreLeftDiagonalLeft, botScoreRightDiagonalLeft, hightAtakBot, weightAtakBot);
					if(choice == 1){
						choice = 0;
					}else if(choice == 0){
						choice = 1;
					}
				}

				if((level == 2 || level == 0) && bot == 0){
					prioritization(level, botScoreGorizont, botScoreVertikal, botScoreLeftDiagonal, botScoreRightDiagonal, botScoreGorizontLeft, botScoreVertikalLeft, botScoreLeftDiagonalLeft, botScoreRightDiagonalLeft, &botScore, hightAtakBot, weightAtakBot, dopusk);
				}

				if(otladka == 1 && bot == 1){
					debugging_bot(hightAtakBot, weightAtakBot, botScoreGorizont,  botScoreVertikal, botScoreLeftDiagonal, botScoreRightDiagonal, botScoreGorizontLeft,  botScoreVertikalLeft, botScoreLeftDiagonalLeft, botScoreRightDiagonalLeft);
					printf("\nplayerScore %d", playerScore);
					printf("\nbotScore %d", botScore);
				}

				if(winExit != 1 && bot == 1 && winO != 1 && winX != 1){
					if(level == 2){
						move_bot_attacking(tableGame, botScore, playerScore, choice, botScoreGorizont, botScoreVertikal, botScoreLeftDiagonal, botScoreRightDiagonal, botScoreGorizontLeft, botScoreVertikalLeft, botScoreLeftDiagonalLeft, botScoreRightDiagonalLeft, hightAtakBot, weightAtakBot, height, widht, &hodBot);
					}

					height = hightStepPlayer[8];
					widht = weightStepPlayer[8];

					if(level == 0 || (level == 2 && hodBot == 0)){
						move_bot_defender(tableGame, playerScoreGorizont, playerScoreVertikal, playerScoreLeftDiagonal, playerScoreRightDiagonal, playerScoreGorizontLeft, playerScoreVertikalLeft, playerScoreLeftDiagonalLeft, playerScoreRightDiagonalLeft, &hodBot, choice, height, widht, hightAtakBot, weightAtakBot);
					}
					if(level == 1 || hodBot == 0){// ЕСЛИ БОТ НЕ СДЕЛАЛ ХОД, ТО ОН ПЕРЕХОДИТ К ЛЕГКОМУ БОТУ
						move_bot_easy(level, tableGame, choice, hightAtakBot, weightAtakBot, &hodBot, &winX, &winO, height, widht);
					}
					
					if(hodBot == 1){
					    result[3].num_moves++;
					    if(choice == 1 && result[3].num_moves > 50){
						winX = 1;
					    }else if(choice == 0 && result[3].num_moves > 50){
						winO = 1;
					    }
					}

					if(hodBot == 1){
						result[3].num_moves++;
						if(choice == 1 && result[3].num_moves > 50){
							winX = 1;
						}else if(choice == 0 && result[3].num_moves > 50){
							winO = 1;
						}
					}

					if((level == 2 || level == 0) && choice == 1 && dopusk == 0){
						int triger = 0;
						for(int p = 1; p < 9; p++){
							if(hightAtakBot[p] == 0){
								triger++;
							}
							if(triger != 0){
								for(int l = 1; l < 9; l++){
									hightAtakBot[l] = hightAtakBot[0];
									weightAtakBot[l] = weightAtakBot[0];
								}
								p = 9;
							}
						}
					}
					dopusk++;
				}

				botScoreGorizont[8] = 0;
				botScoreVertikal[8] = 0;
				botScoreLeftDiagonal[8] = 0;
				botScoreRightDiagonal[8] = 0;

				if(winExit != 1 && bot == 1 && winO != 1 && winX != 1){
					if(choice == 1){
						choice = 0;
					}else if(choice == 0){
						choice = 1;
					}
					check_to_win_bot(tableGame, choice, widht, height, winExit, &winX, &winO, botScoreGorizont, botScoreVertikal, botScoreLeftDiagonal, botScoreRightDiagonal, botScoreGorizontLeft, botScoreVertikalLeft, botScoreLeftDiagonalLeft, botScoreRightDiagonalLeft, hightAtakBot, weightAtakBot);
					if(choice == 1){
						choice = 0;
					}else if(choice == 0){
						choice = 1;
					}
				}

				if((level == 2 || level == 1) && bot == 1){
					prioritization(level, botScoreGorizont, botScoreVertikal, botScoreLeftDiagonal, botScoreRightDiagonal, botScoreGorizontLeft, botScoreVertikalLeft, botScoreLeftDiagonalLeft, botScoreRightDiagonalLeft, &botScore, hightAtakBot, weightAtakBot, dopusk);

				}

				hodBot = 0;

				if(choice == 1 && bot != 1){// ЗДЕСЬ ОПРЕДЕЛЯЕТСЯ ОЧЕРЕДНОСТЬ ХОДОВ
					choice = 0;
				}else if(choice == 0 && bot != 1){
					choice = 1;
				}

			}while(winExit != 1);
			if(outPutReplics == 4 && bot == 1){
					set_display_atrib(BRIGHT);
					set_display_atrib(F_YELLOW);
					printf("\n\tBot: %s", repl[59 + rand()%(67 - 59 + 1)].replics);
					resetcolor();
			}
			if(choice == 1 && bot == 1 && winO == 1){
				    set_display_atrib(BRIGHT);
					set_display_atrib(F_YELLOW);
					printf("\n\tBot: %s", repl[51 + rand()%(58 - 51 + 1)].replics);
					resetcolor();
			}else if(choice == 0 && bot == 1 && winX == 1){
					set_display_atrib(BRIGHT);
					set_display_atrib(F_YELLOW);
					printf("\n\tBot: %s", repl[51 + rand()%(58 - 51 + 1)].replics);
					resetcolor();
			}
			if(bot == 1 && ((choice == 1 && winX == 1) || (choice == 0 && winO == 1))){
				FILE *winTabl;
				if(level == 0){
					winTabl = fopen("data/hall/tabl_easy_bot", "r");
				}else if(level == 1){
					winTabl = fopen("data/hall/tabl_medium_bot", "r");
				}else{
					winTabl = fopen("data/hall/tabl_hard_bot", "r");
				}
				i = 1;
				while(fscanf (winTabl, "%s%u", tablname[i].name, &(tablname[i].num_moves)) != EOF)
					i++;
				for(int k = 1; k <= 10; k++){
					if(choice == 0){
						result[1].num_moves = result[2].num_moves;
					}
					if(result[1].num_moves < tablname[k].num_moves){
						tablname[k].num_moves = result[1].num_moves;
						fclose(winTabl);
						if(k == 1){
							set_display_atrib(BRIGHT);
							set_display_atrib(F_YELLOW);
							printf("\n\t\t\tТы - Чемпион!\n\t\t\tТебе нет равных!");
							resetcolor();
						}else if(k == 2){
							set_display_atrib(BRIGHT);
							set_display_atrib(F_YELLOW);
							printf("\n\t\t\tМолодец!\n\t\t\tТы занял 2 место, но надо еще потренироваться!");
							resetcolor();
						}else if(k == 3){
							set_display_atrib(BRIGHT);
							set_display_atrib(F_YELLOW);
							printf("\n\t\t\tОго, ты вошел в тройку лучших из лучших!\n\t\t\tТы занимаешь почетное 3 место!");
							resetcolor();
						}
						set_display_atrib(BRIGHT);
						set_display_atrib(F_YELLOW);
						printf("\n\t\t\tВведи свое имя, победитель, дабы история запомнила тебя!\n\t\t\t");
						resetcolor();
						scanf("%14s", tablname[k].name);
						if(level == 0){
							winTabl = fopen("data/hall/tabl_easy_bot", "r+");
						}else if(level == 1){
							winTabl = fopen("data/hall/tabl_medium_bot", "r+");
						}else{
						winTabl = fopen("data/hall/tabl_hard_bot", "r+");
						}
						for(int j = 1; j <= 10; j++){
							fprintf(winTabl, "%s %u\n", tablname[j].name, tablname[j].num_moves);
						}
						k = 11;
						fclose(winTabl);
					}
				}
			}else if(bot == 1){
				set_display_atrib(BRIGHT);
				set_display_atrib(F_YELLOW);
				printf("\n\t\t\tТы жалок, тебя выиграл бот");
				resetcolor();
			}
			menu = 10;
			set_display_atrib(BLINK);
			set_display_atrib(F_YELLOW);
			printf("\n\t\t\t[1] - Вернуться в меню\n\t\t\t[2] - Выйти из игры\n");
			resetcolor();
			menu = correct_entering(menu, settings);// ФУНКЦИЯ ПРОВЕРКИ ВВОДИМЫХ ЗНАЧЕНИЙ
			if(menu == 0)
				break;
		}

		if(menu == 2){// НАСТРОЙКИ
			game_settings(menu, &settings, &level, &choice, &bot, &otladka);
		}
		
		if(menu == 3){// ПРАВИЛА
			rules(menu, settings);
		}

		if(menu == 4){// ЗАЛ СЛАВЫ
			table_name(menu, settings);
		}

		if(menu == 5){// ВЫХОД
			break;
		}
		
		if(menu == 6){// ПАСХАЛКА
			easter_egg(menu, settings);
		}
	
	}
	return 0;
}