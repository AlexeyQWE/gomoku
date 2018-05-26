#include "prototypes.h"

void move_bot_defender(char tableGame[TABLE_Y][TABLE_Y], int *playerScoreGorizont, int *playerScoreVertikal, int *playerScoreLeftDiagonal, int *playerScoreRightDiagonal, int  *playerScoreGorizontLeft, int *playerScoreVertikalLeft, int *playerScoreLeftDiagonalLeft, int *playerScoreRightDiagonalLeft, int *hodBot, int choice, int height, int widht, int *hightAtakBot, int *weightAtakBot){
	int exit;
	int j;
	int left, right, down, up;
	int rak;
	printf("сюда заходь 524");
				scanf("%d", &rak);
	// ПРОВЕРКА СЧЕТЧИКОВ, КОТОРЫЕ СЧИТАЛИСЬ ПРИ ПРОВЕРКЕ ХОДА ИГРОКА, ТО ЕСТЬ, ЕСЛИ ГДЕ-ТО СЧЕТЧИК БОЛЬШЕ, ТО ЗНАЧИТ БОТ БУДЕТ ХОДИТЬ ИМЕННО В ТОЙ ПЛОСКОСТИ
	// НАПРИМЕР gorizontScore = 5  А ОСТАЛЬНЫЕ РАВНЫ ПО 1 (СЧЕТЧИКИ), ЗНАЧИТ ОН ПОЙДЕТ ИМЕННО ПО ПЛОСКОСТИ ГОРИЗОНТАЛИ (ВПРАВО ИЛИ ВЛЕВО БУДЕТ РЕШАТЬСЯ ДАЛЬШЕ)
	if(playerScoreGorizont[8] >= playerScoreVertikal[8] && playerScoreGorizont[8] >= playerScoreLeftDiagonal[8] && playerScoreGorizont[8] >= playerScoreRightDiagonal[8] && *hodBot != 1){
		printf("сюда заходь 529");
				scanf("%d", &rak);
		left = widht - 4;
		exit = left - 1;// СЧЕТЧИК ДЛЯ ВЫХОДА И ПОСЛЕДУЮЩЕГО ЦИКЛА for
		if((playerScoreGorizont[8] - playerScoreGorizontLeft[8]) <= playerScoreGorizontLeft[8] || playerScoreGorizont[8] == playerScoreGorizontLeft[8] || playerScoreGorizont[8] == 3 || playerScoreGorizont[8] == 2){
			for(int i = widht - 1; i >= left; i--){
				if(i > 0 && i <= 15){// ДАННАЯ ПРОВЕРКА НУЖНА, ЧТОБЫ i НЕ ВЫШЛА ЗА МАССИВ
					move_bot_gotizont(choice, tableGame, &i, height, &*hodBot, exit, &widht);// САМ ПРОЦЕСС ХОДА БОТА
					if(*hodBot == 1){
						hightAtakBot[0] = height;
						weightAtakBot[0] = widht;
					}
				}	
			}
		}

		if(*hodBot == 0){
			printf("сюда заходь 546");
				scanf("%d", &rak);
			right = widht + 4; 
			exit = right + 1;
			for(int i = widht + 1; i <= right; i++){
				if(i > 0 && i <= 15){// ДАННАЯ ПРОВЕРКА НУЖНА, ЧТОБЫ i НЕ ВЫШЛА ЗА МАССИВ
					move_bot_gotizont(choice, tableGame, &i, height, &*hodBot, exit, &widht);
					if(*hodBot == 1){
						hightAtakBot[1] = height;
						weightAtakBot[1] = widht;
					}
				}	
			}
		}
	}
	if(playerScoreVertikal[8] >= playerScoreGorizont[8] && playerScoreVertikal[8] >= playerScoreLeftDiagonal[8] && playerScoreVertikal[8] >= playerScoreRightDiagonal[8] && *hodBot != 1){
		up = height - 4;
		exit = up - 1;
		printf("сюда заходь 565");
				scanf("%d", &rak);
		if((playerScoreVertikal[8] - playerScoreVertikalLeft[8]) <= playerScoreVertikalLeft[8] || playerScoreVertikal[8] == playerScoreVertikalLeft[8]){
			for(int i = height - 1; i >= up; i--){
				if(i > 0 && i <= 15){
					move_bot_vertical(choice, tableGame, &i, widht, &*hodBot, exit, &height);
					if(*hodBot == 1){
						hightAtakBot[2] = height;
						weightAtakBot[2] = widht;
					}
				}
			}
		}
		if(*hodBot == 0){
			printf("сюда заходь 579");
				scanf("%d", &rak);
			down = height + 4;
			exit = down + 1;
			for(int i = height + 1; i <= down; i++){
				if(i > 0 && i <= 15){
					move_bot_vertical(choice, tableGame, &i, widht, &*hodBot, exit, &height);
					if(*hodBot == 1){
						hightAtakBot[3] = height;
						weightAtakBot[3] = widht;
					}
				}
			}
		}
	}
	/* ЛЕВАЯ ДИАГОНАЛЬ, ТО ЕСТЬ ТАКАЯ \ */
	if(playerScoreLeftDiagonal[8] >= playerScoreGorizont[8] && playerScoreLeftDiagonal[8] >= playerScoreVertikal[8] && playerScoreLeftDiagonal[8] >= playerScoreRightDiagonal[8] && *hodBot != 1){
		up = height - 4;
		down = height + 4;
		exit = up - 1;
		j = 0;
		printf("сюда заходь 599");
				scanf("%d", &rak);
		// leftDiagonalSchet - leftDiagonalSchetLeft --- ЭТО СЧЕТЧИК КАК БЫ ВЕРХНЕЙ ПОЛОВИНЫ ЛЕВОЙ ДИАГОНАЛИ, leftDiagonalSchetLeft ---- ЭТО СЧЕТЧИК НИЖНЕЙ ЛЕВОЙ ДИАГОНАЛИ
		if(((playerScoreLeftDiagonal[8] - playerScoreLeftDiagonalLeft[8]) > playerScoreLeftDiagonalLeft[8] || playerScoreLeftDiagonal[8] == playerScoreLeftDiagonalLeft[8]) && (widht - playerScoreLeftDiagonal[8]) > 0) {
			for(int i = height - 1; i >= up; i--){//4 1
				if(i > 0 && i <= 15){
					++j;
					move_bot_diagonal_minus(j, choice, tableGame, &i, &widht, &*hodBot, exit, &height);
					if(*hodBot == 1){
						hightAtakBot[4] = height;
						weightAtakBot[4] = widht;
					}
				}
			}
		}
		if(*hodBot == 0 && (height + playerScoreLeftDiagonal[8] - playerScoreLeftDiagonalLeft[8]) <= 15){
			printf("сюда заходь 615");
				scanf("%d", &rak);
			exit = down + 1;
			j = 0;
			for(int i = height + 1; i <= down; i++){
				if(i > 0 && i <= 15){
					++j;
					move_bot_diagonal_plus(j, choice, tableGame, &i, &widht, &*hodBot, exit, &height);
					if(*hodBot == 1){
						hightAtakBot[5] = height;
						weightAtakBot[5] = widht;
					}
				}
			}
		}
	}
	// ПРАВАЯ ДИАГОНАЛЬ, ТО ЕСТЬ ТАКАЯ / 
	if(playerScoreRightDiagonal[8] >= playerScoreGorizont[8] && playerScoreRightDiagonal[8] >= playerScoreVertikal[8] && playerScoreRightDiagonal[8] >= playerScoreLeftDiagonal[8] && *hodBot != 1){ 
		up = height - 4;
		down = height + 4;
		exit = up - 1;
		j = 0;
		printf("сюда заходь 637");
				scanf("%d", &rak);
		// rightDiagonalSchet - rightDiagonalSchetLeft --- ЭТО СЧЕТЧИК КАК БЫ НИЖНЕЙ ПОЛОВИНЫ ПРАВОЙ ДИАГОНАЛИ, rightDiagonalSchetLeft ---- ЭТО СЧЕТЧИК ВЕРХНЕЙ ПРАВОЙ ДИАГОНАЛИ
		if(((playerScoreRightDiagonal[8] - playerScoreRightDiagonalLeft[8]) > playerScoreRightDiagonalLeft[8] || playerScoreRightDiagonal[8] == playerScoreRightDiagonal[8]) && (widht + 1) != 16){
			for(int i = height - 1; i >= up; i--){
				if(i > 0 && i <= 15){
					++j;
					move_bot_diagonal_plus(j, choice, tableGame, &i, &widht, &*hodBot, exit, &height);
					if(*hodBot == 1){
						hightAtakBot[6] = height;
						weightAtakBot[6] = widht;
					}
				}
			}
		}
		if(*hodBot == 0){
			printf("сюда заходь 653");
				scanf("%d", &rak);
			exit = down + 1;
			j = 0;
			for(int i = height + 1; i <= down; i++){// 6 > 9
				if(i > 0 && i <= 15){
					++j;
					move_bot_diagonal_minus(j, choice, tableGame, &i, &widht, &*hodBot, exit, &height);
					if(*hodBot == 1){
						hightAtakBot[7] = height;
						weightAtakBot[7] = widht;
					}
				}
			}
		}
	}
}

char move_bot_gotizont(int choice, char tableGame[TABLE_Y][TABLE_Y], int *i, int height, int *hodBot, int exit, int *widht){
	if(choice == 1){
		if(tableGame[height][*i] == 'O'){// ЕСЛИ В ХОДЕ ЦИКЛА-ПРОВЕРКИ ВСТРЕЧАЕТСЯ СОЮЗНЫЙ ЗНАК (ТО ЕСТЬ ТОТ, ЗА КОТОРЫЙ ИГРАЕТ БОТ), ТО ВЫБОР ХОДА СБРАСЫВАЕТСЯ И ВЫХОДИТ ИЗ ЦИКЛА, ПЕРЕКЛЮЧАЯСЬ НА СЛЕД ЦИКЛ-ВЫБОР ДЛЯ СВОЕГО ХОДА
			*i = exit;
		}else if(tableGame[height][*i] == '_' && tableGame[height][*i] != 'O'){// ЭТА КЛЕТКА ПРОВЕРЯЕТСЯ НА НАЛИЧИЕ Х (ПРОВЕРКА ИДЕТ НА ПОБЕДУ Х), ЕСЛИ ЕСТЬ, ТО СЧЕТЧИК УВЕЛИЧИВАЕТСЯ
			tableGame[height][*i] = 'O';
			*widht = *i;// ТРЕБУЕТСЯ ДЛЯ ДАЛЬНЕЙШЕЙ ПРОВЕРКИ НА ПОБЕДУ БОТА
			*i = exit;// ТРЕБЙЕТСЯ ДЛЯ ДАЛЬНЕЙШЕЙ ПРОВЕРКИ БОТА НА ПОБЕДУ
			*hodBot = 1;// СЧЕТЧИК ОБОЗНАЧАЕТ, ЧТО БОТ СХОДИЛ И ПРАВО ХОДА ПЕРЕДАЕТСЯ ЧЕЛОВЕКУ
		}
	}else{// ЭТО В СЛУЧАЕ ТОГО, ЕСЛИ БОТ ИГРАЕТ ЗА КРЕСТИКИ
		if(tableGame[height][*i] == 'X'){
			*i = exit;
		}else if(tableGame[height][*i] == '_' && tableGame[height][*i] != 'X'){// ЭТА КЛЕТКА ПРОВЕРЯЕТСЯ НА НАЛИЧИЕ Х (ПРОВЕРКА ИДЕТ НА ПОБЕДУ Х), ЕСЛИ ЕСТЬ, ТО СЧЕТЧИК УВЕЛИЧИВАЕТСЯ
			tableGame[height][*i] = 'X';
			*widht = *i;
			*i = exit;
			*hodBot = 1;
		}
	}
	return 0;
}

char move_bot_vertical(int choice, char tableGame[TABLE_Y][TABLE_Y], int *i, int widht, int *hodBot, int exit, int *height){
	if(choice == 1){
		if(tableGame[*i][widht] == 'O'){
			*i = exit;
		}else if(tableGame[*i][widht] == '_' && tableGame[*i][widht] != 'O'){// ЭТА КЛЕТКА ПРОВЕРЯЕТСЯ НА НАЛИЧИЕ Х (ПРОВЕРКА ИДЕТ НА ПОБЕДУ Х), ЕСЛИ ЕСТЬ, ТО СЧЕТЧИК УВЕЛИЧИВАЕТСЯ
			tableGame[*i][widht] = 'O';
			*height = *i;
			*i = exit;
			*hodBot = 1;
		}else{
			*hodBot = 0;
		}
	}else{
		if(tableGame[*i][widht] == 'X'){
			*i = exit;
		}else if(tableGame[*i][widht] == '_' && tableGame[*i][widht] != 'X'){// ЭТА КЛЕТКА ПРОВЕРЯЕТСЯ НА НАЛИЧИЕ Х (ПРОВЕРКА ИДЕТ НА ПОБЕДУ Х), ЕСЛИ ЕСТЬ, ТО СЧЕТЧИК УВЕЛИЧИВАЕТСЯ
			tableGame[*i][widht] = 'X';
			*height = *i;
			*i = exit;	
			*hodBot = 1;
		}		
	}
	return 0;
}

char move_bot_diagonal_minus(int j, int choice, char tableGame[TABLE_Y][TABLE_Y], int *i, int *widht, int *hodBot, int exit, int *height){
	if(choice == 1){
		if(tableGame[*i][*widht - j] == 'O'){
			*i = exit;
		}else if(tableGame[*i][*widht - j] == '_' && tableGame[*i][*widht - j] != 'O' && *widht - j > 0){// ЭТА КЛЕТКА ПРОВЕРЯЕТСЯ НА НАЛИЧИЕ Х (ПРОВЕРКА ИДЕТ НА ПОБЕДУ Х), ЕСЛИ ЕСТЬ, ТО СЧЕТЧИК УВЕЛИЧИВАЕТСЯ
			tableGame[*i][*widht - j] = 'O';
			*height = *i;
			*widht = *widht - j;
			*i = exit;
			*hodBot = 1;
		}else{
			*hodBot = 0;
		}
	}else{
		if(tableGame[*i][*widht - j] == 'X'){
			*i = exit;
		}else if(tableGame[*i][*widht - j] == '_' && tableGame[*i][*widht - j] != 'X' && *widht - j > 0){// ЭТА КЛЕТКА ПРОВЕРЯЕТСЯ НА НАЛИЧИЕ Х (ПРОВЕРКА ИДЕТ НА ПОБЕДУ Х), ЕСЛИ ЕСТЬ, ТО СЧЕТЧИК УВЕЛИЧИВАЕТСЯ
			tableGame[*i][*widht - j] = 'X';
			*height = *i;
			*widht = *widht - j;
			*i = exit;	
			*hodBot = 1;
		}else{
			*hodBot = 0;
		}		
	}
	return 0;
}

char move_bot_diagonal_plus(int j, int choice, char tableGame[TABLE_Y][TABLE_Y], int *i, int *widht, int *hodBot, int exit, int *height){
	if(choice == 1){
		if(tableGame[*i][*widht + j] == 'O'){
			*i = exit;
		}else if(tableGame[*i][*widht + j] == '_' && tableGame[*i][*widht + j] != 'O' && *widht + j <= 10){// ЭТА КЛЕТКА ПРОВЕРЯЕТСЯ НА НАЛИЧИЕ Х (ПРОВЕРКА ИДЕТ НА ПОБЕДУ Х), ЕСЛИ ЕСТЬ, ТО СЧЕТЧИК УВЕЛИЧИВАЕТСЯ
			tableGame[*i][*widht + j] = 'O';
			*height = *i;
			*widht = *widht + j;
			*i = exit;
			*hodBot = 1;
		}else{
			*hodBot = 0;
		}
	}else{
		if(tableGame[*i][*widht + j] == 'X'){
			*i = exit;
		}else if(tableGame[*i][*widht + j] == '_' && tableGame[*i][*widht + j] != 'X' && *widht + j <= 10){// ЭТА КЛЕТКА ПРОВЕРЯЕТСЯ НА НАЛИЧИЕ Х (ПРОВЕРКА ИДЕТ НА ПОБЕДУ Х), ЕСЛИ ЕСТЬ, ТО СЧЕТЧИК УВЕЛИЧИВАЕТСЯ
			tableGame[*i][*widht + j] = 'X';
			*height = *i;
			*widht = *widht + j;
			*i = exit;	
			*hodBot = 1;
		}else{
			*hodBot = 0;
		}		
	}
	return 0;
}