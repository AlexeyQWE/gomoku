#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h"

int main()
{
	int i = 1, menu = 0, level = 0, choice = 1, bot = 1;
	int height = 0, widht = 0;
	char tableGame[TABLE_Y][TABLE_Y];	//Хранение доски и ходов игроков

	while (i == 1) {
		int settings = 0, winExit = 0, winX = 0, winO = 0;
		menu = main_menu();
	
		if(menu == 1){
			fill_gameboard(tableGame);
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
				check_to_win(tableGame, choice, widht, height, winExit, &winX, &winO);
				if(choice == 1){// ЗДЕСЬ ОПРЕДЕЛЯЕТСЯ ОЧЕРЕДНОСТЬ ХОДОВ
					choice = 0;
				}else if(choice == 0){
					choice = 1;
				}
			}while(winExit != 1);
		}

		if(menu == 2){
			game_settings(&menu, &settings, &level, &choice, &bot);
		}

		if(menu == 3){
		
		}

		if(menu == 4){

		}

		if(menu == 5){
			break;
		}
		/*i = 0;*/

	}

	return 0;
}