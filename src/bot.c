#include <stdio.h>
#include <stdlib.h> 
#include "prototypes.h"

void move_bot(char tableGame[TABLE_Y][TABLE_Y], int level, int gorizontScore, int vertikalScore, int leftDiagonalScore, int rightDiagonalScore, int gorizontScoreLeft, int vertikalScoreLeft, int leftDiagonalScoreLeft, int rightDiagonalScoreLeft, int hodBot, int left, int right, int down, int up, int choice, int *height, int *widht){
	int exit;
	if(level == 2){
		level = 1;// ЗДЕСБ БУДЕТ СЛОЖНЫЙ БОТ (ТИПА *СЛОЖНЫЙ*)
	}
	if(level == 1){
		// ПРОВЕРКА СЧЕТЧИКОВ, КОТОРЫЕ СЧИТАЛИСЬ ПРИ ПРОВЕРКЕ ХОДА ИГРОКА, ТО ЕСТЬ, ЕСЛИ ГДЕ-ТО СЧЕТЧИК БОЛЬШЕ, ТО ЗНАЧИТ БОТ БУДЕТ ХОДИТЬ ИМЕННО В ТОЙ ПЛОСКОСТИ
		// НАПРИМЕР gorizontScore = 5  А ОСТАЛЬНЫЕ РАВНЫ ПО 1 (СЧЕТЧИКИ), ЗНАЧИТ ОН ПОЙДЕТ ИМЕННО ПО ПЛОСКОСТИ ГОРИЗОНТАЛИ (ВПРАВО ИЛИ ВЛЕВО БУДЕТ РЕШАТЬСЯ ДАЛЬШЕ)
		if(gorizontScore >= vertikalScore && gorizontScore >= leftDiagonalScore && gorizontScore >= rightDiagonalScore){
			exit = left - 1;// СЧЕТЧИК ДЛЯ ВЫХОДА И ПОСЛЕДУЮЩЕГО ЦИКЛА for
				if((gorizontScore - gorizontScoreLeft) <= gorizontScoreLeft || gorizontScore == gorizontScoreLeft){
					for(int i = *widht - 1; i >= left; i--){
						if(i > 0 && i <= 15){// ДАННАЯ ПРОВЕРКА НУЖНА, ЧТОБЫ i НЕ ВЫШЛА ЗА МАССИВ
							move_bot_gotizont(choice, tableGame, &i, *height, &hodBot, exit, &*widht);// САМ ПРОЦЕСС ХОДА БОТА
						}	
					}
				}
				if(hodBot == 0){
					exit = right + 1;
					for(int i = *widht + 1; i <= right; i++){
						if(i > 0 && i <= 15){// ДАННАЯ ПРОВЕРКА НУЖНА, ЧТОБЫ i НЕ ВЫШЛА ЗА МАССИВ
							move_bot_gotizont(choice, tableGame, &i, *height, &hodBot, exit, &*widht);
						}	
					}
				}
		}
		if(vertikalScore >= gorizontScore && vertikalScore >= leftDiagonalScore && vertikalScore >= rightDiagonalScore && hodBot != 1){
			exit = up - 1;
			if((vertikalScore - vertikalScoreLeft) <= vertikalScoreLeft || vertikalScore == vertikalScoreLeft){
				for(int i = *height - 1; i >= up; i--){
					if(i > 0 && i <= 15){
						move_bot_vertical(choice, tableGame, &i, *widht, &hodBot, exit, &*height);
					}
				}
			}
			if(hodBot == 0){
				exit = down + 1;
				for(int i = *height + 1; i <= down; i++){
					if(i > 0 && i <= 15){
						move_bot_vertical(choice, tableGame, &i, *widht, &hodBot, exit, &*height);
					}
				}
			}
		}
		/* ЛЕВАЯ ДИАГОНАЛЬ, ТО ЕСТЬ ТАКАЯ \ */
		if(leftDiagonalScore >= gorizontScore && leftDiagonalScore >= vertikalScore && leftDiagonalScore >= rightDiagonalScore && hodBot != 1){
			exit = up - 1;
			int j = 0;
			// leftDiagonalScore - leftDiagonalScoreLeft --- ЭТО СЧЕТЧИК КАК БЫ ВЕРХНЕЙ ПОЛОВИНЫ ЛЕВОЙ ДИАГОНАЛИ, leftDiagonalScoreLeft ---- ЭТО СЧЕТЧИК НИЖНЕЙ ЛЕВОЙ ДИАГОНАЛИ
			if(((leftDiagonalScore - leftDiagonalScoreLeft) > leftDiagonalScoreLeft || leftDiagonalScore == leftDiagonalScoreLeft) && (*widht - leftDiagonalScore) > 0) {
				for(int i = *height - 1; i >= up; i--){//4 1
					if(i > 0 && i <= 15){
						++j;
						move_bot_diagonal_minus(j, choice, tableGame, &i, &*widht, &hodBot, exit, &*height);
					}
				}
			}
			if(hodBot == 0 && (*height + leftDiagonalScore - leftDiagonalScoreLeft) <= 15){
				exit = down + 1;
				int j = 0;
				for(int i = *height + 1; i <= down; i++){
					if(i > 0 && i <= 15){
						++j;
						move_bot_diagonal_plus(j, choice, tableGame, &i, &*widht, &hodBot, exit, &*height);
					}
				}
			}
		}
		// ПРАВАЯ ДИАГОНАЛЬ, ТО ЕСТЬ ТАКАЯ / 
		if(rightDiagonalScore >= gorizontScore && rightDiagonalScore >= vertikalScore && rightDiagonalScore >= leftDiagonalScore && hodBot != 1){
			exit = up - 1;
			int j = 0;
			// rightDiagonalScore - rightDiagonalScoreLeft --- ЭТО СЧЕТЧИК КАК БЫ НИЖНЕЙ ПОЛОВИНЫ ПРАВОЙ ДИАГОНАЛИ, rightDiagonalScoreLeft ---- ЭТО СЧЕТЧИК ВЕРХНЕЙ ПРАВОЙ ДИАГОНАЛИ
			if(((rightDiagonalScore - rightDiagonalScoreLeft) > rightDiagonalScoreLeft || rightDiagonalScore == rightDiagonalScoreLeft) && (*widht + 1) != 11){
				for(int i = *height - 1; i >= up; i--){
					if(i > 0 && i <= 15){
						++j;
						move_bot_diagonal_plus(j, choice, tableGame, &i, &*widht, &hodBot, exit, &*height);
					}
				}
			}
			if(hodBot == 0){
				exit = down + 1;
				j = 0;
				for(int i = *height + 1; i <= down; i++){// 6 > 9
					if(i > 0 && i <= 15){
						++j;
						move_bot_diagonal_minus(j, choice, tableGame, &i, &*widht, &hodBot, exit, &*height);
					}
				}
			}
		}
	}
	if(level == 0 || hodBot == 0){// ЕСЛИ БОТ НЕ СДЕЛАЛ ХОД, ТО ОН ПЕРЕХОДИТ К ЛЕГКОМУ БОТУ
		level = 1;
		/* задача Алексея Карасева */
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