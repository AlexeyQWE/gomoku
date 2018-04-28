#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h"

#define TABLE_Y 17	// РАЗМЕР ДОСКИ

int main()
{
	int i = 1, menu = 0, settings = 0, level = 0, vibor = 1, bot = 1;
	char tableGame[TABLE_Y][TABLE_Y];	//Хранение доски и ходов игроков

	while (i == 1) {
		menu = main_menu();
	
		if(menu == 1){
			fill_gameboard(TABLE_Y,tableGame);
			print_gameboard(TABLE_Y,tableGame);
		}

		if(menu == 2){
			game_settings(&menu, &settings, &level, &vibor, &bot);
		}

		if(menu == 3){
		
		}

		if(menu == 4){

		}

		if(menu == 5){

		}
		/*i = 0;*/

	}

	return 0;
}