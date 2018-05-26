#include "prototypes.h"
#include <stdio.h>

int main()
{
	int i = 1, level = 2, choice = 0, bot = 1, otladka = 1;
	int height = 0, widht = 0; // КООРДИНАТЫ
	char tableGame[TABLE_Y][TABLE_Y];	//Хранение доски и ходов игроков

	while (i == 1) {
		int hodBot = 0; // перменные для бота
		int settings = 0;
		int menu = 0;
		int playerScore = 0;
		menu = main_menu();
	
		if(menu == 1){// ИГРА
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


				print_gameboard(tableGame);

				
				if(otladka == 1 && bot == 1){
					debugging_player(hightStepPlayer, weightStepPlayer, playerScoreGorizont,  playerScoreVertikal, playerScoreLeftDiagonal, playerScoreRightDiagonal, playerScoreGorizontLeft,  playerScoreVertikalLeft, playerScoreLeftDiagonalLeft, playerScoreRightDiagonalLeft);
					debugging_bot(hightAtakBot, weightAtakBot, botScoreGorizont,  botScoreVertikal, botScoreLeftDiagonal, botScoreRightDiagonal, botScoreGorizontLeft,  botScoreVertikalLeft, botScoreLeftDiagonalLeft, botScoreRightDiagonalLeft);
					printf("\nplayerScore %d", playerScore);
					printf("\nbotScore %d", botScore);
				}
				

				if(winX == 1){
					printf("\n\n\t\t\tХ - ПОБЕДИЛ\a");
					winExit = 1;
				}else if(winO == 1){
					printf("\n\n\t\t\tO - ПОБЕДИЛ");
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

					if(level == 2 && choice == 1 && dopusk == 0){
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
			menu = 10;
			printf("\n\t\t\t[1] - Вернуться в меню\n\t\t\t[2] - Выйти из игры\n");
			menu = correct_entering(menu, settings);// ФУНКЦИЯ ПРОВЕРКИ ВВОДИМЫХ ЗНАЧЕНИЙ
			if(menu == 0)
				break;
		}

		if(menu == 2){// НАСТРОЙКИ
			game_settings(menu, &settings, &level, &choice, &bot, &otladka);
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