#include <stdio.h>
#include <stdlib.h> 
#include "prototypes.h"

void input_nubmers_test(int *numbers)// ПРОВЕРКА НА ВВОДИМЫЕ ЦИФРЫ 
{
	for(int i = 0; i < 1; i++){
		scanf("%d", numbers);
		if((*numbers < 0) || (*numbers > 1)){
			printf("Эй, не шали, такого варианта нет!\n");
			--i;
		}
	}
}

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

void fill_gameboard(char gameboard_mass[TABLE_Y][TABLE_Y])
{
	system("clear");// ОЧИЩАЕМ ОБЛАСТЬ ВЫШЕ, В ДАЛЬНЕЙШЕМ, БУДЕТ ВЫГЯДИТЬ ТАК, ЧТО ДОСКА СТАТИЧНА
	for(int i = 0; i < TABLE_Y; i++){// ЗАПОЛНЯЕМ МАССИВ (ИГРОВУЮ ДОСКУ), ТО ЕСТЬ ПРИВОДИМ К СМОТРИБЕЛЬНОМУ ВИДУ
		for(int j = 0; j < TABLE_Y; j++){
			gameboard_mass[i][j] = '_';
		}
	}
}

void print_gameboard(char gameboard_mass[TABLE_Y][TABLE_Y])
{
	system("clear"); 
	printf("\n\t\t   ____   __      _    _      __    _   __ __   __\n");
	printf("\t\t  (  __) /  \\    / \\  / \\    /  \\  ( )_/ / \\ \\_/ /\n");
	printf("\t\t  ) (   ( () )  / /\\\\//\\ \\  ( () ) )  _ |   \\_  /\n");
	printf("\t\t  (_)    \\__/  (_)  --  (_)  \\__/  (_) \\_\\   /_/\n");
	for(int i = 0; i < TABLE_Y; i++){// ЗДЕСЬ ВЫВОДИТСЯ САМА ДОСКА
		printf("\n\t\t");
		for(int j = 0; j < TABLE_Y; j++){
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

void entering_coord(int vibor, int winExit, int *height, int *widht, char tableGame[TABLE_Y][TABLE_Y])
{
	if((vibor == 1 || vibor == 0) && winExit != 1){
		if(vibor == 1){
			printf("\nХод делает X [Высота] [Ширина]\n");
		}else{
			printf("\nХод делает O [Высота] [Ширина]\n");
		}
		for(int i = 0; i < 1; i++){// ПРОВЕРКА НА ВВОДИМЫЕ СИМВОЛЫ
			scanf("%d %d", &*height, &*widht);
			if(((*height <= 0) || (*height > 15)) || ((*widht <= 0) || (*widht > 15))){
				printf("Наверно руки дрожат? Попробуй еще раз\n");
				--i;
			}
			if(tableGame[*height][*widht] == 'X' || tableGame[*height][*widht] == 'O'){// ПРОВЕРКА НА ЗАНЯТОСТЬ КЛЕТКИ
				printf("Эта клетка уже занята\n");
				--i;
			}
		}
	}
}

void game_settings(int *menu, int *settings, int *level, int *vibor, int *bot)
{
	int i = 0;

	while(*menu == 2){
		system("clear");
		printf("\t\t\t\t      _____   _\n");
		printf("\t\t\t\t     /   //  /\\\\\n");
		printf("\t\t\t\t    /   //  /  \\\\\n");				
		printf("\t\t\t\t    \\   \\\\_/   ||\n");
		printf("\t\t\t\t     \\        //\n");
		printf("\t\t\t\t      |    __//\n");
		printf("\t\t\t\t      /   //\n");
		printf("\t\t\t\t     /   //\n");
		printf("\t\t\t\t    /   //\n");
		printf("\n\n\t\t\t\t   НАСТРОЙКИ");
		printf("\n\n\t\t\t\t   1.Бот - ");

		if(*bot == 1){
			printf("включён");
		}else{
			printf("выключен");
		}
		if(*settings == 1){
			printf("\n\t\t\t\t\t|-------- 1.Включить\n\t\t\t\t\t|-------- 0.Выключить");
		}
		printf("\n\t\t\t\t   2.Уровень бота - ");
		if(*level == 1){
			printf("новичок");
		}else if(*level == 0){
			printf("защитник");
		}
		if(*settings == 2){
			printf("\n\t\t\t\t\t|-------- 1.Новичок\n\t\t\t\t\t|-------- 0.Защитник");
		}
		printf("\n\t\t\t\t   3.Автоматически Вы играете за - ");
		if(*vibor == 1){
			printf("X");
		}else{
			printf("O");
		}
		if(*settings == 3){
			printf("\n\t\t\t\t\t|-------- 1.Играть первым за Х\n\t\t\t\t\t|-------- 0.Играть первым за О");
		}
		printf("\n\t\t\t\t   4.Выход в меню\n\t\t\t\t   ");
		if(*settings == 0){	
			for(int i = 0; i < 1; i++){
				scanf("%d", settings);
				if((*settings < 1) || (*settings > 4)){
					printf("Эй, не шали, такого варианта нет!\n");
					--i;
				}
			}
			i = 0;
		}
		if(*settings == 1 && i == 1){
			input_nubmers_test(bot);
			i = 0;
			*settings = 0;
		}else if(*settings == 2 && i == 1){
			input_nubmers_test(level);
			i = 0;
			*settings = 0;
		}else if(*settings == 3 && i == 1){
			input_nubmers_test(vibor);
			i = 0;
			*settings = 0;
		}else if(*settings == 4){
			*menu = *settings;
		}
		i = 1;
	}
	i = 0;
}