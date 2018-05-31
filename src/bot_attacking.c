#include "prototypes.h"

void move_bot_attacking(char tableGame[TABLE_Y][TABLE_Y], int botScore, int playerScore, int choice,  int *botScoreGorizont, int *botScoreVertikal, int *botScoreLeftDiagonal, int *botScoreRightDiagonal, int  *botScoreGorizontLeft, int *botScoreVertikalLeft, int *botScoreLeftDiagonalLeft, int *botScoreRightDiagonalLeft, int *hightAtakBot, int *weightAtakBot, int height, int widht, int *hodBot){
	if((((botScore == playerScore && (playerScore < 3 && choice == 0))) || (botScore == playerScore && choice == 0) || (botScore >= playerScore && (playerScore < 2 && choice == 0))) || (botScore > playerScore) || (playerScore < 2 && choice == 1)){//-----------УРОВЕНЬ БОТА - ИГРОК
		int addmission = 0;
		int exit, j;
		if(botScoreGorizont[8] >= botScoreVertikal[8] && botScoreGorizont[8] >= botScoreLeftDiagonal[8] && botScoreGorizont[8] >= botScoreRightDiagonal[8] && *hodBot != 1){
			if(((botScoreGorizont[8] - botScoreGorizontLeft[8]) <= botScoreGorizontLeft[8] || botScoreGorizont[8] == botScoreGorizontLeft[8]) && hightAtakBot[8] != 0 && weightAtakBot[8] != 0){
				height = hightAtakBot[8];
				widht = weightAtakBot[8];
				exit = widht - 4 - 1;
				addmission = 0;
				for(int i = widht - 1; i >= widht - 4; i--){
					if(i > 0 && i <= 15){// ДАННАЯ ПРОВЕРКА НУЖНА, ЧТОБЫ i НЕ ВЫШЛА ЗА МАССИВ
						if(addmission == 0){
							for(int j = 0; j < 4 - botScore; j++){
								if(choice == 1 && widht - j > 0){
									if(tableGame[height][widht - j] == 'X'){
										i = exit;
									}else if(tableGame[height][widht - j] == 'O' || tableGame[height][widht - j] == '_'){
										addmission++;
									}
								}else if(widht - j > 0){
									if(tableGame[height][widht - j] == 'O'){
										i = exit;
									}else if(tableGame[height][widht - j] == 'X' || tableGame[height][widht - j] == '_'){
										addmission++;
									}
								}else{
									j = 4 - botScore;
									i = exit;
								}
							}
						}
						if(i != exit && addmission == 4 - botScore){
							step_attack_bot_gorizont(choice, tableGame, &i, height, &*hodBot, exit, &widht);// САМ ПРОЦЕСС ХОДА БОТА
							if(*hodBot == 1){
								i = widht - 4 - 1;
								hightAtakBot[0] = height;
								weightAtakBot[0] = widht;
							}
						}else{
							addmission = 0;
						}
					}	
				}
			}
			if(*hodBot == 0 && hightAtakBot[1] != 0 && weightAtakBot[1] != 0){
				height = hightAtakBot[8];
				widht = weightAtakBot[8];
				exit = widht + 4 + 1;
				addmission = 0;
				for(int i = widht + 1; i <= widht + 4; i++){
					if(i > 0 && i <= 15){// ДАННАЯ ПРОВЕРКА НУЖНА, ЧТОБЫ i НЕ ВЫШЛА ЗА МАССИВ
						if(addmission == 0){
							for(int j = 0; j < 4 - botScore; j++){
								if(choice == 1 && widht + j <= 15){
									if(tableGame[height][widht + j] == 'X'){
										i = exit;
									}else if(tableGame[height][widht + j] == 'O' || tableGame[height][widht + j] == '_'){
										addmission++;
									}
								}else if(widht + j > 0){
									if(tableGame[height][widht + j] == 'O'){
										i = exit;
									}else if(tableGame[height][widht + j] == 'X' || tableGame[height][widht + j] == '_'){
										addmission++;
									}
								}else{
									j = 4 - botScore;
									i = exit;
								}
							}
						}
						if(i != exit && addmission == 4 - botScore){
							step_attack_bot_gorizont(choice, tableGame, &i, height, &*hodBot, exit, &widht);
							if(*hodBot == 1){
								i = widht + 4 + 1;
								hightAtakBot[1] = height;
								weightAtakBot[1] = widht;
							}
						}else{
							addmission = 0;
						}
					}	
				}
			}
		}
		if(botScoreVertikal[8] >= botScoreGorizont[8] && botScoreVertikal[8] >= botScoreLeftDiagonal[8] && botScoreVertikal[8] >= botScoreRightDiagonal[8] && *hodBot != 1){
			if(((botScoreVertikal[8] - botScoreVertikalLeft[8]) <= botScoreVertikalLeft[8] || botScoreVertikal[8] == botScoreVertikalLeft[8]) && hightAtakBot[2] != 0 && weightAtakBot[2] != 0){
				height = hightAtakBot[8];
				widht = weightAtakBot[8];
				exit = height - 4 - 1;
				addmission = 0;
				for(int i = height - 1; i >= height - 4; i--){
					if(i > 0 && i <= 15){
						if(addmission == 0){
							for(int j = 0; j < 4; j++){
								if(choice == 1 && height - j > 0){
									if(tableGame[height - j][widht] == 'X'){
										i = exit;
									}else if(tableGame[height - j][widht] == 'O' || tableGame[height - j][widht] == '_'){
										addmission++;
									}
								}else if(height - j > 0){
									if(tableGame[height - j][widht] == 'O'){
										i = exit;
									}else if(tableGame[height - j][widht] == 'X' || tableGame[height - j][widht] == '_'){
										addmission++;
									}
								}else{
									j = 4;
									i = exit;
								}
							}
						}
						if(i != exit && addmission == 4){
							step_attack_bot_vertical(choice, tableGame, &i, widht, &*hodBot, exit, &height);
							if(*hodBot == 1){
								i = height - 4 - 1;
								hightAtakBot[2] = height;
								weightAtakBot[2] = widht;
							}
						}else{
							addmission = 0;
						}
					}
				}
			}
			if(*hodBot == 0 && hightAtakBot[3] > 0 && weightAtakBot[3] > 0){
				height = hightAtakBot[8];
				widht = weightAtakBot[8];
				addmission = 0;
				exit = height + 4 + 1;
				for(int i = height + 1; i <= height + 4; i++){
					if(i > 0 && i <= 15){
						if(addmission == 0){
							for(int j = 0; j < 4; j++){
								if(choice == 1 && height + j <= 15){
									if(tableGame[height + j][widht] == 'X'){
										i = exit;
									}else if(tableGame[height + j][widht] == 'O' || tableGame[height + j][widht] == '_'){
										addmission++;
									}
								}else if(height + j > 0){
									if(tableGame[height + j][widht] == 'O'){
										i = exit;
									}else if(tableGame[height + j][widht] == 'X' || tableGame[height + j][widht] == '_'){
										addmission++;
									}
								}else{
									j = 4;
									i = exit;
								}
							}
						}
						if(i != exit && addmission == 4){
							step_attack_bot_vertical(choice, tableGame, &i, widht, &*hodBot, exit, &height);
							if(*hodBot == 1){
								i = height + 4 + 1;
								hightAtakBot[3] = height;
								weightAtakBot[3] = widht;
							}
						}else{
							addmission = 0;
						}
					}
				}
			}
		}
		/* ЛЕВАЯ ДИАГОНАЛЬ, ТО ЕСТЬ ТАКАЯ \ */
		if(botScoreLeftDiagonal[8] >= botScoreGorizont[8] && botScoreLeftDiagonal[8] >= botScoreVertikal[8] && botScoreLeftDiagonal[8] >= botScoreRightDiagonal[8] && *hodBot != 1){
			j = 0;
			widht = weightAtakBot[4];
			if((((botScoreLeftDiagonal[8] - botScoreLeftDiagonalLeft[8]) > botScoreLeftDiagonalLeft[8] || botScoreLeftDiagonal[8] == botScoreLeftDiagonalLeft[8]) && (widht - botScoreLeftDiagonal[8]) > 0) && hightAtakBot[4] != 0 && weightAtakBot[4] != 0){
				height = hightAtakBot[8];
				widht = weightAtakBot[8];
				exit = height - 4 - 1;
				addmission = 0;
				for(int i = height - 1; i >= height - 4; i--){//4 1
					if(i > 0 && i <= 15){
						j++;
						if(addmission == 0){
							for(int k = 0; k < 4; k++){
								if(choice == 1 && height - k > 0 && widht - k > 0){
									if(tableGame[height - k][widht - k] == 'X'){
										i = exit;
									}else if(tableGame[height - k][widht - k] == 'O' || tableGame[height - k][widht - k] == '_'){
										addmission++;
									}
								}else if(height - k > 0 && widht - k > 0){
									if(tableGame[height - k][widht - k] == 'O'){
										i = exit;
									}else if(tableGame[height - k][widht - k] == 'X' || tableGame[height - k][widht - k] == '_'){
										addmission++;
									}
								}else{
									k = 4;
									i = exit;
								}
							}
						}
						if(i != exit && addmission == 4){
							step_attack_bot_diagonal_minus(j, choice, tableGame, &i, &widht, &*hodBot, exit, &height);
							if(*hodBot == 1){
								i = height - 4 - 1;
								hightAtakBot[4] = height;
								weightAtakBot[4] = widht;
							}
						}else{
							addmission = 0;
						}
					}
				}
			}
			if(*hodBot == 0 && (height + botScoreLeftDiagonal[8] - botScoreLeftDiagonalLeft[8]) <= 15 && hightAtakBot[5] != 0 && weightAtakBot[5] != 0){
				height = hightAtakBot[8];
				widht = weightAtakBot[8];
				j = 0;
				addmission = 0;
				exit = height + 4 + 1;//11
				for(int i = height + 1; i <= height + 4; i++){// 7 do 10
					if(i > 0 && i <= 15){
						j++;
						if(addmission == 0){
							for(int k = 0; k < 4; k++){
								if(choice == 1 && height + k > 0 && widht + k > 0){//7 8
									if(tableGame[height + k][widht + k] == 'X'){
										i = exit;
									}else if(tableGame[height + k][widht + k] == 'O' || tableGame[height + k][widht + k] == '_'){
										addmission++;
									}
								}else if(height + k > 0 && widht + k > 0){// 
									if(tableGame[height + k][widht + k] == 'O'){
										i = exit;
									}else if(tableGame[height + k][widht + k] == 'X' || tableGame[height + k][widht + k] == '_'){
										addmission++;
									}
								}else{
									k = 4;
									i = exit;
								}
							}
						}
						if(i != exit && addmission == 4){
							step_attack_bot_diagonal_plus(j, choice, tableGame, &i, &widht, &*hodBot, exit, &height);
							if(*hodBot == 1){
								i = height + 4 + 1;
								hightAtakBot[5] = height;
								weightAtakBot[5] = widht;
							}
						}else{
							addmission = 0;
						}
					}
				}
			}
		}
		// ПРАВАЯ ДИАГОНАЛЬ, ТО ЕСТЬ ТАКАЯ / 
		if(botScoreRightDiagonal[8] >= botScoreGorizont[8] && botScoreRightDiagonal[8] >= botScoreVertikal[8] && botScoreRightDiagonal[8] >= botScoreLeftDiagonal[8] && *hodBot != 1){
			j = 0;
			widht = weightAtakBot[6];
			if((((botScoreRightDiagonal[8] - botScoreRightDiagonalLeft[8]) > botScoreRightDiagonalLeft[8]) && (widht + 1) != 11) && hightAtakBot[6] != 0 && weightAtakBot[6] != 0){
				height = hightAtakBot[8];
				widht = weightAtakBot[8];
				exit = height - 4 - 1;
				addmission = 0;
				for(int i = height; i >= height - 4; i--){
					if(i > 0 && i <= 15){
						if(addmission == 0){
							for(int k = 0; k < 4; k++){
								if(choice == 1 && height - k > 0 && widht - k > 0){
									if(tableGame[height - k][widht - k] == 'X'){
										i = exit;
									}else if(tableGame[height - k][widht - k] == 'O' || tableGame[height - k][widht - k] == '_'){
										addmission++;
									}
								}else if(height - k > 0 && widht - k > 0){
									if(tableGame[height - k][widht - k] == 'O'){
										i = exit;
									}else if(tableGame[height - k][widht - k] == 'X' || tableGame[height - k][widht - k] == '_'){
										addmission++;
									}
								}else{
									i = exit;
									k = 4;
								}
							}
						}
						if(i != exit && addmission == 4){
							step_attack_bot_diagonal_plus(j, choice, tableGame, &i, &widht, &*hodBot, exit, &height);
							if(*hodBot == 1){
								i = height - 4 - 1;
								hightAtakBot[6] = height;
								weightAtakBot[6] = widht;
							}
						}else{
							addmission = 0;
						}
						j++;
					}
				}
			}
			if(*hodBot == 0 && hightAtakBot[7] != 0 && weightAtakBot[7] != 0){
				height = hightAtakBot[8];
				widht = weightAtakBot[8];
				j = 0;
				exit = height + 4 + 1;
				addmission = 0;
				for(int i = height; i <= height + 4; i++){// 6 > 9
					if(i > 0 && i <= 15){
						if(addmission == 0){
							for(int k = 0; k < 4; k++){
								if(choice == 1 && height + k > 0 && widht + k > 0){
									if(tableGame[height + k][widht + k] == 'X'){
										i = exit;
									}else if(tableGame[height + k][widht + k] == 'O' || tableGame[height + k][widht + k] == '_'){
										addmission++;
									}
								}else if(height + k > 0 && widht + k > 0){
									if(tableGame[height + k][widht + k] == 'O'){
										i = exit;
									}else if(tableGame[height + k][widht + k] == 'X' || tableGame[height + k][widht + k] == '_'){
										addmission++;
									}
								}else{
									k = 4;
									i = exit;
								}
							}
						}
						if(i != exit && addmission == 4){
							step_attack_bot_diagonal_minus(j, choice, tableGame, &i, &widht, &*hodBot, exit, &height);
							if(*hodBot == 1){
								i = height + 4 + 1;
								hightAtakBot[7] = height;
								weightAtakBot[7] = widht;
							}
						}else{
							addmission = 0;
						}
						j++;
					}
				}
			}
		}
	}
}


char step_attack_bot_gorizont(int vibor, char tableGame[TABLE_Y][TABLE_Y], int *i, int hight, int *hodBot, int exit, int *weight)
{
	if(vibor == 1){
		if(tableGame[hight][*i] == '_'){// ЭТА КЛЕТКА ПРОВЕРЯЕТСЯ НА НАЛИЧИЕ Х (ПРОВЕРКА ИДЕТ НА ПОБЕДУ Х), ЕСЛИ ЕСТЬ, ТО СЧЕТЧИК УВЕЛИЧИВАЕТСЯ
			tableGame[hight][*i] = 'O';
			*weight = *i;// ТРЕБУЕТСЯ ДЛЯ ДАЛЬНЕЙШЕЙ ПРОВЕРКИ НА ПОБЕДУ БОТА
			*i = exit;// ТРЕБЙЕТСЯ ДЛЯ ДАЛЬНЕЙШЕЙ ПРОВЕРКИ БОТА НА ПОБЕДУ
			*hodBot = 1;// СЧЕТЧИК ОБОЗНАЧАЕТ, ЧТО БОТ СХОДИЛ И ПРАВО ХОДА ПЕРЕДАЕТСЯ ЧЕЛОВЕКУ
		}
	}else{// ЭТО В СЛУЧАЕ ТОГО, ЕСЛИ БОТ ИГРАЕТ ЗА КРЕСТИКИ
		if(tableGame[hight][*i] == '_'){// ЭТА КЛЕТКА ПРОВЕРЯЕТСЯ НА НАЛИЧИЕ Х (ПРОВЕРКА ИДЕТ НА ПОБЕДУ Х), ЕСЛИ ЕСТЬ, ТО СЧЕТЧИК УВЕЛИЧИВАЕТСЯ
			tableGame[hight][*i] = 'X';
			*weight = *i;
			*i = exit;
			*hodBot = 1;
		}
	}
	return 0;
}

char step_attack_bot_vertical(int vibor, char tableGame[TABLE_Y][TABLE_Y], int *i, int weight, int *hodBot, int exit, int *hight){
	if(vibor == 1){
		if(tableGame[*i][weight] == '_'){// ЭТА КЛЕТКА ПРОВЕРЯЕТСЯ НА НАЛИЧИЕ Х (ПРОВЕРКА ИДЕТ НА ПОБЕДУ Х), ЕСЛИ ЕСТЬ, ТО СЧЕТЧИК УВЕЛИЧИВАЕТСЯ
			tableGame[*i][weight] = 'O';
			*hight = *i;
			*i = exit;
			*hodBot = 1;
		}
	}else{
		if(tableGame[*i][weight] == '_'){// ЭТА КЛЕТКА ПРОВЕРЯЕТСЯ НА НАЛИЧИЕ Х (ПРОВЕРКА ИДЕТ НА ПОБЕДУ Х), ЕСЛИ ЕСТЬ, ТО СЧЕТЧИК УВЕЛИЧИВАЕТСЯ
			tableGame[*i][weight] = 'X';
			*hight = *i;
			*i = exit;	
			*hodBot = 1;
		}		
	}
	return 0;
}

char step_attack_bot_diagonal_plus(int j, int vibor, char tableGame[TABLE_Y][TABLE_Y], int *i, int *weight, int *hodBot, int exit, int *hight){
	if(vibor == 1){
		if(tableGame[*i][*weight + j] == '_' && *weight + j <= 15){// ЭТА КЛЕТКА ПРОВЕРЯЕТСЯ НА НАЛИЧИЕ Х (ПРОВЕРКА ИДЕТ НА ПОБЕДУ Х), ЕСЛИ ЕСТЬ, ТО СЧЕТЧИК УВЕЛИЧИВАЕТСЯ
			tableGame[*i][*weight + j] = 'O';
			*hight = *i;
			*weight = *weight + j;
			*i = exit;
			*hodBot = 1;
		}
	}else{
		if(tableGame[*i][*weight + j] == '_' && *weight + j <= 15){// ЭТА КЛЕТКА ПРОВЕРЯЕТСЯ НА НАЛИЧИЕ Х (ПРОВЕРКА ИДЕТ НА ПОБЕДУ Х), ЕСЛИ ЕСТЬ, ТО СЧЕТЧИК УВЕЛИЧИВАЕТСЯ
			tableGame[*i][*weight + j] = 'X';
			*hight = *i;
			*weight = *weight + j;
			*i = exit;	
			*hodBot = 1;
		}		
	}
	return 0;
}

char step_attack_bot_diagonal_minus(int j, int vibor, char tableGame[TABLE_Y][TABLE_Y], int *i, int *weight, int *hodBot, int exit, int *hight){
	if(vibor == 1){
		if(tableGame[*i][*weight - j] == '_' && *weight - j > 0){// ЭТА КЛЕТКА ПРОВЕРЯЕТСЯ НА НАЛИЧИЕ Х (ПРОВЕРКА ИДЕТ НА ПОБЕДУ Х), ЕСЛИ ЕСТЬ, ТО СЧЕТЧИК УВЕЛИЧИВАЕТСЯ
			tableGame[*i][*weight - j] = 'O';
			*hight = *i;
			*weight = *weight - j;
			*i = exit;
			*hodBot = 1;
		}
	}else{
		if(tableGame[*i][*weight - j] == '_' && *weight - j > 0){// ЭТА КЛЕТКА ПРОВЕРЯЕТСЯ НА НАЛИЧИЕ Х (ПРОВЕРКА ИДЕТ НА ПОБЕДУ Х), ЕСЛИ ЕСТЬ, ТО СЧЕТЧИК УВЕЛИЧИВАЕТСЯ
			tableGame[*i][*weight - j] = 'X';
			*hight = *i;
			*weight = *weight - j;
			*i = exit;	
			*hodBot = 1;
		}		
	}
	return 0;
}