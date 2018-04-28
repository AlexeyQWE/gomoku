#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h"

int main()
{
	int i = 1, menu = 0, level = 0, vibor = 1, bot = 1;
	int height = 0, widht = 0;
	char tableGame[TABLE_Y][TABLE_Y];	//Хранение доски и ходов игроков

	while (i == 1) {
		int settings = 0, winExit = 0;
		menu = main_menu();
	
		if(menu == 1){
			fill_gameboard(tableGame);
			do{
				print_gameboard(tableGame);
				entering_coord(vibor, winExit, &height, &widht, tableGame);
			}while(winExit != 1);
		}

		if(menu == 2){
			game_settings(&menu, &settings, &level, &vibor, &bot);
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