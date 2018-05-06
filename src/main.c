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
		}

		if(menu == 5){

		}

	}

	return 0;
}