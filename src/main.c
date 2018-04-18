#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h"

#define TABLE_Y 17	// РАЗМЕР ДОСКИ

int main()
{
	int menu = 0;
	int i = 1;
	char tableGame[TABLE_Y][TABLE_Y];	//Хранение доски и ходов игроков

	while (i == 1) {
		menu = main_menu();
	
		if(menu == 1){
			fill_gameboard(TABLE_Y,tableGame);
			print_gameboard(TABLE_Y,tableGame);
		}

		if(menu == 2){

		}

		if(menu == 3){
		
		}

		if(menu == 4){

		}

		if(menu == 5){

		}
		i = 0;

	}

	return 0;
}