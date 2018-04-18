#include <stdio.h>
#include <stdlib.h> 
#include "prototypes.h"

int main_menu()
{
	int menu;

	system("clear");// УДАЛЯЕТ В ТЕРМИНАЛЕ ВСЕ НАПИСАННОЕ ВЫШЕ
	printf("\t\t __   __   ______   __        __         ______    \n");
	printf("\t\t/_/| /_/| /_____/| /_/|      /_/|       /______\\   \n");
	printf("\t\t|-|| |-|| |- ___|/ |-||      |-||      /- ___ -\\\\  \n");
	printf("\t\t|-||_|-|| |-||___  |-||      |-||      |-//  \\-||  \n");
	printf("\t\t|-|/_|-|| |-|___/| |-||      |-||      |-||  |-||   \n");
	printf("\t\t|- __ -|| |- ___|/ |-||      |-||      |-||  |-||   \n");
	printf("\t\t|-|| |-|| |-||___  |-||____  |-||____  |-||__|-||   \n");
	printf("\t\t|-|| |-|| |-|___/| |-|____/| |-|____/| |-\\___/-|/ \n");
	printf("\t\t|_|/ |_|/ |_____|/ |______|/ |______|/ \\_______/  \n");
	printf("\n\n\t\t\t\t   GOMOKU\n\n\t\t\t\t   1.Играть\n\t\t\t\t   2.Настройки\n\t\t\t\t   3.Правила игры\n\t\t\t\t   4.Таблица лидеров\n\t\t\t\t   5.Выход\n\t\t\t\t   ");
	printf("\n");
	printf("Выберите нужный вам пункт ");
	for(int i = 0; i < 1; i++){
		scanf("%d", &menu);
		if((menu < 1) || (menu > 5)){// ПРОВЕРКА НА КОРРЕКТНОСТЬ ВВОДА, БУКВЫ НЕ МОЖЕТ ПРОВЕРИТЬ
			printf("Эй, не шали, такого варианта нет!\n");
			--i;
		}	
	}
	return menu;
}

void fill_gameboard(int size_board, char gameboard_mass[size_board][size_board])
{
	system("clear");// ОЧИЩАЕМ ОБЛАСТЬ ВЫШЕ, В ДАЛЬНЕЙШЕМ, БУДЕТ ВЫГЯДИТЬ ТАК, ЧТО ДОСКА СТАТИЧНА
			for(int i = 0; i < size_board - 1; i++){// ЗАПОЛНЯЕМ МАССИВ (ИГРОВУЮ ДОСКУ), ТО ЕСТЬ ПРИВОДИМ К СМОТРИБЕЛЬНОМУ ВИДУ
				for(int j = 0; j < size_board - 1; j++){
					gameboard_mass[i][j] = '_';
				}
			}
}

void print_gameboard(int size_board, char gameboard_mass[size_board][size_board])
{
	system("clear"); 
				printf("\n\t\t ____   __      _    _      __    _   __ __   __\n");
				printf("\t\t(  __) /  \\    / \\  / \\    /  \\  ( )_/ / \\ \\_/ /\n");
				printf("\t\t) (   ( () )  / /\\\\//\\ \\  ( () ) )  _ |   \\_  /\n");
				printf("\t\t(_)    \\__/  (_)  --  (_)  \\__/  (_) \\_\\   /_/\n");	

				for(int i = 0; i < size_board - 1; i++){// ЗДЕСЬ ВЫВОДИТСЯ САМА ДОСКА
					printf("\n\t\t");
					for(int j = 0; j < size_board - 1; j++){
						if(i == 0){
							if(j == 0){// ВЫВОДЯТСЯ ОРИЕНТИРОВОЧНЫЕ КООРДИНАТЫ ПО БОКАМ ИГРОВОГО ПОЛЯ ПО ГОРИЗОНТАЛИ
								printf("   ");
							}else if(j < 10){
								printf(" %d ", j);
							}else if(j == 9){
								printf("%d ", j);
							}else{
								printf(" %d", j);
							}
						}else if(j == 0){// ТЕ ЖЕ САМЫЕ КООРДИНАТЫ, ТОЛЬКО ПО ВЕРТИКАЛИ
							if(i < 10){
								printf(" %d ", i);
							}else{
								printf("%d ", i);
							}
						}else{
							printf("[%c]", gameboard_mass[i][j]);// ВЫВОД САМОЙ ИГРОВОЙ ДОСКИ
						}
					}
				}
}