#include <stdio.h>
#include "prototypes.h"

int main()
{
	int menu = 0;
	int settings = 0;

	while (1) {
		menu = main_menu();
	
		if(menu == 1){

		}

		if(menu == 2){

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

		}

		if(menu == 5){

		}

	}

	return 0;
}