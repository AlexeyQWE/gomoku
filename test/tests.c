#include <ctest.h>
#include <stdio.h>
#include <prototypes.h>

CTEST(testing_suite, main_menu) 
{
	//WHEN
	const int result = main_menu();

	//THEN
	ASSERT_INTERVAL(0, 5, result);
}

CTEST(testing_suite, entering_coord) 
{
	//GIVEN
	char tableGame[16][16];
	int choice = 0, height = 0, widht = 0, winExit = 0;

	//WHEN
	entering_coord( choice,  winExit,  &height,  &widht, tableGame);

	//THEN
	ASSERT_INTERVAL(0, 1, choice);
	ASSERT_INTERVAL(0, 1, winExit);
	ASSERT_INTERVAL(1, 15, height);
	ASSERT_INTERVAL(1, 15, widht);
}

CTEST(testing_suite, game_settings) 
{
	//GIVEN
	int  level = 2, choice = 1, bot = 1, settings = 0, otladka = 1;

	//WHEN
	game_settings(2, &settings, &level, &choice, &bot, &otladka);

	//THEN
	const int expected = 5;
	ASSERT_EQUAL(expected, settings); //Проверка на то, что параметр settings, по завершению работы функции, будет равен 5
	ASSERT_INTERVAL(0, 2, level);   //Проверка на то, что параметр level, по завершению работы функциии, будет в диапозоне от 0 до 2
	ASSERT_INTERVAL(0, 1, choice);   //Проверка на то, что параметр choice, по завершению работы функциии, будет в диапозоне от 0 до 1
	ASSERT_INTERVAL(0, 1, bot);		//Проверка на то, что параметр bot, по завершению работы функциии, будет в диапозоне от 0 до 1
	ASSERT_INTERVAL(0, 1, otladka);  //Проверка на то, что параметр otladka, по завершению работы функциии, будет в диапозоне от 0 до 1

}

