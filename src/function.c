#include "prototypes.h"

static int LEN = 3, GLEN = 4;

int correct_entering(int menu, int settings)
{
	int c, error = 0;
	char *ptr;
	if(menu == 0){
		char strChoose[LEN];
		do{
			if(error == 1){
				printf("\t\t\t\t   [Ошибка!]\n\t\t\t\t   ");
				error = 0;
			}
			for(ptr = strChoose; ptr - strChoose < LEN - 1 && (c = getchar()) != EOF && c != '\n'; ++ptr)
				*ptr = c;

			if(c == '\n')
				*ptr = '\0';

			while(c != '\n'){
				c = getchar();
				continue;
			}
			error++;
		}while((strChoose[0] != '1' && strChoose[0] != '2' && strChoose[0] != '3' && strChoose[0] != '4' && strChoose[0] != '5') || strChoose[1] != '\0');
		if(strChoose[0] == '1')
			return 1;
		else if(strChoose[0] == '2')
			return 2;
		else if(strChoose[0] == '3')
			return 3;
		else if(strChoose[0] == '4')
			return 4;
		else if(strChoose[0] == '5')
			return 5;
		else
			return 0;
	}else if(menu == 1){
		char strChoose[GLEN];
		do{
			if(error == 1){
				printf("[Ошибка! Попробуйте снова]-----> ");
				error = 0;
			}
			for(ptr = strChoose; ptr - strChoose < GLEN - 1 && (c = getchar()) != EOF && c != '\n'; ++ptr)
				*ptr = c;

			if(c == '\n')
				*ptr = '\0';

			while(c != '\n'){
				c = getchar();
				continue;
			}
			error++;
		}while((((strChoose[0] != '1' || strChoose[1] != '0') && (strChoose[0] != '1' || strChoose[1] != '1') && (strChoose[0] != '1' || strChoose[1] != '2') && (strChoose[0] != '1' || strChoose[1] != '3') && (strChoose[0] != '1' || strChoose[1] != '4') && (strChoose[0] != '1' || strChoose[1] != '5')) || strChoose[2] != '\0') && (strChoose[0] != '1' || strChoose[1] != '\0') && (strChoose[0] != '2' || strChoose[1] != '\0') && (strChoose[0] != '3' || strChoose[1] != '\0') && strChoose[0] != '4' && (strChoose[0] != '5' || strChoose[1] != '\0') && (strChoose[0] != '6' || strChoose[1] != '\0') && (strChoose[0] != '7' || strChoose[1] != '\0') && (strChoose[0] != '8' || strChoose[1] != '\0') && (strChoose[0] != '9' || strChoose[1] != '\0'));
		switch(strChoose[0]){
			case '1':
				if(strChoose[1] == '\0'){
					return 1;
				}
				switch(strChoose[1]){
					case '0':
						return 10;
					case '1':
						return 11;
					case '2':
						return 12;
					case '3':
						return 13;
					case '4':
						return 14;
					case '5':
						return 15;
				}
			case '2':
				return 2;
			case '3':
				return 3;
			case '4':
				return 4;
			case '5':
				return 5;
			case '6':
				return 6;
			case '7':
				return 7;
			case '8':
				return 8;
			case '9':
				return 9;
		}
	}else if(menu == 2){
		char strChoose[LEN];
		do{
			if(error == 1){
				printf("\t\t\t\t   [Ошибка!]\n\t\t\t\t   ");
				error = 0;
			}
			for(ptr = strChoose; ptr - strChoose < LEN - 1 && (c = getchar()) != EOF && c != '\n'; ++ptr)
				*ptr = c;

			if(c == '\n')
				*ptr = '\0';

			while(c != '\n'){
				c = getchar();
				continue;
			}
			error++;
		}while((strChoose[0] != '1' && strChoose[0] != '2' && (strChoose[0] != '3' || settings != 0) && (strChoose[0] != '4' || settings != 0)) || strChoose[1] != '\0');
		if(strChoose[0] == '1')
			return 1;
		else if(strChoose[0] == '2' && settings == 0)
			return 2;
		else if(strChoose[0] == '2' && settings != 0)
			return 0;
		else if(strChoose[0] == '3')
			return 3;
		else if(strChoose[0] == '4')
			return 4;
		else
			return 0;	
	}else if(menu == 10){
		char strChoose[LEN];
		do{
			if(error == 1){
				printf("\t\t\t\t   [Ошибка!]\n\t\t\t\t   ");
				error = 0;
			}
			for(ptr = strChoose; ptr - strChoose < LEN - 1 && (c = getchar()) != EOF && c != '\n'; ++ptr)
				*ptr = c;

			if(c == '\n')
				*ptr = '\0';

			while(c != '\n'){
				c = getchar();
				continue;
			}
			error++;
		}while((strChoose[0] != '1' && strChoose[0] != '2') || strChoose[1] != '\0');
		if(strChoose[0] == '1')
			return 1;
		else if(strChoose[0] == '2')
			return 0;	
	}
	return 0;
}

int main_menu()
{
	int menu = 0, settings = 0;

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
	menu = correct_entering(menu, settings);

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
				if(gameboard_mass[i][j] == 'X'){
					printf("[%c]", gameboard_mass[i][j]);// ВЫВОД САМОЙ ИГРОВОЙ ДОСКИ
				}else if(gameboard_mass[i][j] == 'X'){
					printf("[%c]", gameboard_mass[i][j]);// ВЫВОД САМОЙ ИГРОВОЙ ДОСКИ
				}else{
					printf("[%c]", gameboard_mass[i][j]);// ВЫВОД САМОЙ ИГРОВОЙ ДОСКИ
				}
			}
		}
	}
}

void entering_coord(int choice, int winExit, int *height, int *widht, char tableGame[TABLE_Y][TABLE_Y])
{
	int menu = 1, settings = 0;
	if((choice == 1 || choice == 0) && winExit != 1){
		if(choice == 1){
			printf("\nХод делает X");
		}else{
			printf("\nХод делает O");
		}
		for(int i = 0; i < 1; i++){// ПРОВЕРКА НА ВВОДИМЫЕ СИМВОЛЫ
			if(choice == 1){
				printf("\n[Высота] - ");
			}else{
				printf("\n[Высота] - ");
			}
			*height = correct_entering(menu, settings);
			printf("[Ширина] - ");
			*widht = correct_entering(menu, settings);
			if(tableGame[*height][*widht] == 'X' || tableGame[*height][*widht] == 'O'){// ПРОВЕРКА НА ЗАНЯТОСТЬ КЛЕТКИ
				printf("---!!!Эта клетка уже занята!!!---");
				--i;
			}
		}
	}

	if(choice == 1){
		tableGame[*height][*widht] = 'X';
	}else{
		tableGame[*height][*widht] = 'O';
	}
}

void check_to_win(char tableGame[TABLE_Y][TABLE_Y], int choice, int widht, int height, int winExit, int *winX, int *winO, int *gorizontScore, int *vertikalScore, int *leftDiagonalScore, int *rightDiagonalScore, int *gorizontScoreLeft, int *vertikalScoreLeft, int *leftDiagonalScoreLeft, int *rightDiagonalScoreLeft, int *left, int *right, int *up, int *down)
{
		int score = 0, j = 0;
		*left = widht - 4;
		*right = widht + 4; 
		*up = height - 4;
		*down = height + 4;
		// ГОРИЗОНТАЛЬНАЯ ПРОВЕРКА, СОСТОИТ В ТОМ
		// ЧТО ПРОВЕРКА ПРОВОДИТСЯ ОТНОСИТЕЛЬНО КООРДИНАТ ВВЕДЕННЫХ ИГРОКОМ
		// В ЛЕВО НА 4 КЛЕТКИ И В ПРАВО НА 4 КЛЕТКИ
		// СРАВНИВАЯ СОДЕРЖИМОЕ МАССИВА
		// ПОШАГОВО ОПИШУ НА СЛЕДУЩЕЙ ПРОВЕРКЕ ПО ГОРИЗОНТАЛИ
		int exit = *left - 1;
		int check = 0;
		int spaceFinder = 0;
		for(int i = widht - 1; i >= *left; i--){// НАЧИНАЕТСЯ ОТСЧЕТ С ЛЕВОЙ КЛЕТКИ, КОТОРАЯ НАХОДИТСЯ РАДОМ С ТОЙ КЛЕКТОЙ, КОТОРУЮ УКАЗАЛ ЮЗЕР
			control(exit, i, choice, tableGame, height, &score, &spaceFinder, height, height, widht - 1, widht + 1, &check, i);
			if(check != 0)
				i = check;
		}
		*gorizontScoreLeft = score;
		check = 0;
		exit = *right + 1;
		for(int i = widht + 1; i <= *right; i++){
			control(exit, i, choice, tableGame, height, &score, &spaceFinder, height, height, widht - 1, widht + 1, &check, i);
			if(check != 0)
				i = check;
		}
		*gorizontScore = score;
		check = 0;
		checkWin(score, choice, &*winX, &*winO);
		score = 0;
		spaceFinder = 0;
		// ВЕРТИКАЛЬНАЯ ПРОВЕРКА, СОСТОИТ В ТОМ
		// ЧТО ПРОВЕРКА ПРОВОДИТСЯ ОТНОСИТЕЛЬНО КООРДИНАТ ВВЕДЕННЫХ ИГРОКОМ
		// В ВЕРХ НА 4 КЛЕТКИ И ВНИЗ НА 4 КЛЕТКИ
		// СРАВНИВАЯ СОДЕРЖИМОЕ МАССИВА
		exit = *up - 1;
		for(int i = height - 1; i >= *up; i--){
			control(exit, widht, choice, tableGame, i, &score, &spaceFinder, height - 1, height + 1, widht, widht, &check, i);
			if(check != 0)
				i = check;
		}
		*vertikalScoreLeft = score;
		check = 0;
		exit = *down + 1;
		for(int i = height + 1; i <= *down; i++){
			control(exit, widht, choice, tableGame, i, &score, &spaceFinder, height - 1, height + 1, widht, widht, &check, i);
			if(check != 0)
				i = check;
		}
		*vertikalScore = score;
		check = 0;
		checkWin(score, choice, &*winX, &*winO);
		score = 0;
		spaceFinder = 0;
		// ЛЕВАЯ ДИАГОНАЛЬНАЯ ПРОВЕРКА (ТО ЕСТЬ ТАКАЯ \ ), СОСТОИТ В ТОМ
		// ЧТО ПРОВЕРКА ПРОВОДИТСЯ ОТНОСИТЕЛЬНО КООРДИНАТ ВВЕДЕННЫХ ИГРОКОМ
		// В ВЕРХ И ВЛЕВО НА 4 КЛЕТКИ И ВНИЗ ВПРАВО НА 4 КЛЕТКИ
		// СРАВНИВАЯ СОДЕРЖИМОЕ МАССИВА
		exit = *up - 1;
		j = 0;
		for(int i = height - 1; i >= *up; i--){//4 1
			++j;
			control(exit, widht - j, choice, tableGame, i, &score, &spaceFinder, height - 1, height + 1, widht - j - 1, widht - j + 1, &check, i);
			if(check != 0)
				i = check;
		}
		*leftDiagonalScoreLeft = score;
		check = 0;
		exit = *down + 1;
		j = 0;
		for(int i = height + 1; i <= *down; i++){
			++j;
			control(exit, widht + j, choice, tableGame, i, &score, &spaceFinder, height - 1, height + 1, widht + j - 1, widht + j + 1, &check, i);
			if(check != 0)
				i = check;
		}
		*leftDiagonalScore = score;
		check = 0;
		checkWin(score, choice, &*winX, &*winO);
		score = 0;
		spaceFinder = 0;
		// ПРАВАЯ ДИАГОНАЛЬНАЯ ПРОВЕРКА (ТО ЕСТЬ ТАКАЯ / ), СОСТОИТ В ТОМ
		// ЧТО ПРОВЕРКА ПРОВОДИТСЯ ОТНОСИТЕЛЬНО КООРДИНАТ ВВЕДЕННЫХ ИГРОКОМ
		// В ВЕРХ И !!!ВПРАВО!!! НА 4 КЛЕТКИ И ВНИЗ !!!ВЛЕВО!!! НА 4 КЛЕТКИ
		// СРАВНИВАЯ СОДЕРЖИМОЕ МАССИВА
		exit = *up - 1;
		j = 0;
		for(int i = height - 1; i >= *up; i--){
			++j;
			control(exit, widht + j, choice, tableGame, i, &score, &spaceFinder, height - 1, height + 1, widht + j - 1, widht + j + 1, &check, i);
			if(check != 0)
				i = check;
		}
		*rightDiagonalScoreLeft = score;
		check = 0;
		exit = *down + 1;
		j = 0;
		for(int i = height + 1; i <= *down; i++){// 6 > 9
			++j;
			if(check != 0)
				i = check;
		}
		*rightDiagonalScore = score;
		check = 0;
		checkWin(score, choice, &*winX, &*winO);
		score = 0;
		j = 0;
		spaceFinder = 0;
}

int checkWin(int score, int choice, int *winX, int *winO)// ПРОВЕРКА НА ПОБЕДУ
{
	if(score == 4){
		if(choice == 1){// ЕСЛИ СЧЕТЧИК БУДЕТ РАВЕН 4, ТО ИГРОК ПОБЕДИЛ
			*winX = 1;
		}else{
			*winO = 1;
		}
	}else if(score > 4){
		if(choice == 1){
			*winO = 1;
		}else{
			*winX = 1;
		}
	}
	return 0;
}

void control(int exit, int i, int choice, char tableGame[TABLE_Y][TABLE_Y], int coord, int *score, int *spaceFinder, int hightCoordLeft, int hightCoordRight, int weightCoordLeft, int weightCoordRight, int *check, int checkTwo)
{
	if(i > 0 && checkTwo <= 15){// ДАННАЯ ПРОВЕРКА НУЖНА, ЧТОБЫ i НЕ ВЫШЛА ЗА МАССИВ
		if(choice == 1){
			if(tableGame[coord][i] == 'X'){// ЭТА КЛЕТКА ПРОВЕРЯЕТСЯ НА НАЛИЧИЕ Х (ПРОВЕРКА ИДЕТ НА ПОБЕДУ Х), ЕСЛИ ЕСТЬ, ТО СЧЕТЧИК УВЕЛИЧИВАЕТСЯ
				++*score;
			}else if(tableGame[coord][i] == '_'){
				if(tableGame[hightCoordLeft][weightCoordLeft] == 'X' && tableGame[hightCoordRight][weightCoordRight] == 'X'){
					++*spaceFinder;
					*check = exit;
				}
			}else{// ЕСЛИ В КАКОЙ-ТО ОБЛАСТИ ИЗ 4 КЛЕТОК ЕСТЬ БРЕШЬ, ТО ПРОВЕРКА СБРАСЫВАЕТСЯ
				*check = exit;
			}
		}else{
			if(tableGame[coord][i] == 'O'){// ЭТА КЛЕТКА ПРОВЕРЯЕТСЯ НА НАЛИЧИЕ Х (ПРОВЕРКА ИДЕТ НА ПОБЕДУ Х), ЕСЛИ ЕСТЬ, ТО СЧЕТЧИК УВЕЛИЧИВАЕТСЯ
				++*score;
			}else if(tableGame[coord][i] == '_'){
				if(tableGame[hightCoordLeft][weightCoordLeft] == 'O' && tableGame[hightCoordRight][weightCoordRight] == 'O'){
					++*spaceFinder;
					*check = exit;
				}
			}else{// ЕСЛИ В КАКОЙ-ТО ОБЛАСТИ ИЗ 4 КЛЕТОК ЕСТЬ БРЕШЬ, ТО ПРОВЕРКА СБРАСЫВАЕТСЯ
				*check = exit;
			}
		}
	}
}

void game_settings(int menu, int *settings, int *level, int *choice, int *bot)
{
	int i = 0;

	while(menu == 2){
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
			printf("\n\t\t\t\t\t|-------- 1.Включить\n\t\t\t\t\t|-------- 2.Выключить");
		}
		printf("\n\t\t\t\t   2.Уровень бота - ");
		if(*level == 1){
			printf("новичок");
		}else if(*level == 0){
			printf("защитник");
		}
		if(*settings == 2){
			printf("\n\t\t\t\t\t|-------- 1.Новичок\n\t\t\t\t\t|-------- 2.Защитник");
		}
		printf("\n\t\t\t\t   3.Автоматически Вы играете за - ");
		if(*choice == 1){
			printf("X");
		}else{
			printf("O");
		}
		if(*settings == 3){
			printf("\n\t\t\t\t\t|-------- 1.Играть первым за Х\n\t\t\t\t\t|-------- 2.Играть первым за О");
		}
		printf("\n\t\t\t\t   4.Выход в меню\n\t\t\t\t   ");
		if(*settings == 0){	
			*settings = correct_entering(menu, *settings);
			i = 0;
		}
		if(*settings == 1 && i == 1){
			*bot = correct_entering(menu, *settings);
			i = 0;
			*settings = 0;
		}else if(*settings == 2 && i == 1){
			*level = correct_entering(menu, *settings);
			i = 0;
			*settings = 0;
		}else if(*settings == 3 && i == 1){
			*choice = correct_entering(menu, *settings);
			i = 0;
			*settings = 0;
		}else if(*settings == 4){
			menu = *settings;
		}
		i = 1;
	}
	i = 0;
}