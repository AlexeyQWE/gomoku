#include "prototypes.h"
#include <time.h>

void move_bot_easy(int level, char tableGame[TABLE_Y][TABLE_Y], int choice, int *hightAtakBot, int *weightAtakBot, int *hodBot, int *winX, int *winO, int height, int widht)
{
	int widhtBot[8] = {'\0'};
	int heightBot[8] = {'\0'};
	srand(time(NULL));
	int difference, i, randomStep, j = 0;
	while(j == 0){
		i = 0;
		difference = 0;
		do{// ЗДЕСЬ ПРОВЕРКА НА СВОБОДНОЕ МЕСТО ВОКРУГ ТЕХ КООРДИНАТ, КОТОРЫЕ ВВЕЛ ЧЕЛОВЕК, ЧТОБЫ ОПРЕДЕЛИТЬ КУДА МОЖНО СХОДИТЬ
			if(tableGame[height][widht + difference] == '_'  && widht + difference <= 15){// WEIGHT + RAZN - НУЖНО ДЛЯ ТОГО, ЧТОБЫ В ДАЛЬНЕЙШЕМ СЧЕТЧИК НЕ ВЫШЕЛ ЗА ПРЕДЕЛЫ МАССИВА
				widhtBot[i] = widht + difference;
				heightBot[i] = height;
				i++;
			}
			if(tableGame[height + difference][widht + difference] == '_'  && widht + difference <= 15 && height + difference <= 15){
				widhtBot[i] = widht + difference;
				heightBot[i] = height + difference;
				i++;
			}
			if(tableGame[height + difference][widht] == '_' && height + difference <= 15){
				widhtBot[i] = widht;
				heightBot[i] = height + difference;
				i++;
			}
			if(tableGame[height + difference][widht - difference] == '_' && widht - difference > 0 && height + difference <= 15){
				widhtBot[i] = widht - difference;
				heightBot[i] = height + difference;
				i++;
			}
			if(tableGame[height][widht - difference] == '_' && widht - difference > 0){
				widhtBot[i] = widht - difference;
				heightBot[i] = height;
				i++;
			}
			if(tableGame[height - difference][widht - difference] == '_' && widht - difference > 0 && height - difference > 0){
				widhtBot[i] = widht - difference;
				heightBot[i] = height - difference;
				i++;
			}
			if(tableGame[height - difference][widht] == '_' && height - difference > 0){
				widhtBot[i] = widht;
				heightBot[i] = height - difference;
				i++;						
			}
			if(tableGame[height - difference][widht + difference] == '_' && widht + difference <= 15 && height - difference > 0){
				widhtBot[i] = widht + difference;
				heightBot[i] = height - difference;
				i++;						
			}
			difference++;
		}while(i == 0);// ВЫХОД ИЗ ЦИКЛА, ЕСЛИ УСЛОВИЯ БУДУТ ВЫПОЛНЯТЬСЯ, ТО RAZN УВЕЛИЧИВЕТСЯ ДО ТЕХ ПОР ПОКА УСЛОВИЕ НЕ ВЫПОЛНИТСЯ,
		// ЧТОБ ВЫЙТИ ИЗ ЦИКЛА
		if(i > 0){
			randomStep = rand()%i; // СЧЕТЧИК i НУЖЕН БЫЛ ДЛЯ ТОГО ЧТОБЫ ВЫБРАТЬ РАНДОМНУЮ ПУСТУЮ ЯЧЕЙКУ ВОКРУГ КООРДИНАТ ВВЕДЕНЫХ ПОЛЬЩОВАТЕЛЕМ
			if(choice == 0){// ЗДЕСЬ ИИ СМОТРИТ ЗА КОГО ОН ИГРАЕТ, ЕСЛИ VIBOR = 0, ТО ЗНАЧИТ ИИ ИГРАЕТ ЗА КРЕСТИКИ И НАОБОРОТ
				tableGame[heightBot[randomStep]][widhtBot[randomStep]] = 'X';
				*hodBot = 1;
			}else{
				tableGame[heightBot[randomStep]][widhtBot[randomStep]] = 'O';
				*hodBot = 1;
			}
			if(*hodBot == 1){
				hightAtakBot[8] = height;
				weightAtakBot[8] = widht;
				if(level == 1){
					hightAtakBot[0] = height;
					weightAtakBot[0] = widht;
				}
			}
		}
		if(difference >= 8 && i == 0){// ЭТО ПРОВЕРКА НА ТО ЕСТЬ ЛИ ХОДЫ ДЛЯ ИИ, ЕСЛИ НЕТ, ТО ИИ ПРОИГРЫВАЕТ
			if(choice == 1){
				*winX = 1;
			}else{
				*winO = 1;
			}
		}else{
			j = 1;// ЭТО НУЖНО ДЛЯ ВЫХОДЫ ИЗ ЦИКЛА, ЕСЛИ НЕ ПОНЯТНО, ГЛЯНЬТЕ ВХОД В ЭТОТ ЦИКЛ, ГДЕ ПРОИСХОДИЛ ВЕСЬ ЭТОТ АД /как же я ошибался, этот Леха не видел сложного бота
		}
	}
}