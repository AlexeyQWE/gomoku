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

CTEST(testing_suite, game_settings) 
{
	//GIVEN
	int  level = 2, choice = 1, bot = 1, settings = 0, otladka = 1;

	//WHEN
	game_settings(2, &settings, &level, &choice, &bot, &otladka);

	//THEN
	const int expected = 5;
	ASSERT_EQUAL(expected, settings); //Проверка на то, что параметр settings, по завершению работы функции, будет равен 5
	ASSERT_INTERVAL(0, 3, level);   //Проверка на то, что параметр level, по завершению работы функциии, будет в диапозоне от 0 до 3
	ASSERT_INTERVAL(0, 1, choice);   //Проверка на то, что параметр choice, по завершению работы функциии, будет в диапозоне от 0 до 1
	ASSERT_INTERVAL(0, 1, bot);		//Проверка на то, что параметр bot, по завершению работы функциии, будет в диапозоне от 0 до 1
	ASSERT_INTERVAL(0, 1, otladka);  //Проверка на то, что параметр otladka, по завершению работы функциии, будет в диапозоне от 0 до 1

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

CTEST(testing_suite, check_to_win) 
{
	//GIVEN
	char tableGame[16][16];
	int choice = 0, widht = 1, height = 1, winExit = 0, winX = 0, winO = 0;
	int playerScoreGorizont[9] = {'\0'};
	int playerScoreVertikal[9] = {'\0'};
	int playerScoreLeftDiagonal[9] = {'\0'};
	int playerScoreRightDiagonal[9] = {'\0'};
	int playerScoreGorizontLeft[9] = {'\0'};
	int playerScoreVertikalLeft[9] = {'\0'};
	int playerScoreLeftDiagonalLeft[9] = {'\0'};
	int playerScoreRightDiagonalLeft[9] = {'\0'};
	int hightStepPlayer[9] = {'\0'};
	int weightStepPlayer[9] = {'\0'};
			
	//WHEN
	check_to_win(tableGame, choice, widht, height, winExit, &winX, &winO, playerScoreGorizont, playerScoreVertikal, 
		playerScoreLeftDiagonal, playerScoreRightDiagonal, 
		playerScoreGorizontLeft, playerScoreVertikalLeft, 
		playerScoreLeftDiagonalLeft, playerScoreRightDiagonalLeft, hightStepPlayer, weightStepPlayer);

	//THEN
	const int expected = 0;
	/*int EplayerScoreGorizont[9] = {'\0'};
	int EplayerScoreVertikal[9] = {'\0'};
	int EplayerScoreLeftDiagonal[9] = {'\0'};
	int EplayerScoreRightDiagonal[9] = {'\0'};
	int EplayerScoreGorizontLeft[9] = {'\0'};
	int EplayerScoreVertikalLeft[9] = {'\0'};
	int EplayerScoreLeftDiagonalLeft[9] = {'\0'};
	int EplayerScoreRightDiagonalLeft[9] = {'\0'};
	int EhightStepPlayer[9] = {'\0'};
	int EweightStepPlayer[9] = {'\0'};*/

	ASSERT_INTERVAL(0, 1, choice);
	ASSERT_INTERVAL(1, 15, widht);
	ASSERT_INTERVAL(1, 15, height);
	ASSERT_EQUAL(expected, winExit);
	ASSERT_EQUAL(expected, winX);
	ASSERT_EQUAL(expected, winO);
	/*ASSERT_DATA(EplayerScoreGorizont, 9, playerScoreGorizont, 9);
	ASSERT_DATA(EplayerScoreVertikal, 9, playerScoreVertikal, 9);
	ASSERT_DATA(EplayerScoreLeftDiagonal, 9, playerScoreLeftDiagonal, 9);
	ASSERT_DATA(EplayerScoreRightDiagonal, 9, playerScoreRightDiagonal, 9);
	ASSERT_DATA(EplayerScoreGorizontLeft, 9, playerScoreGorizontLeft, 9);
	ASSERT_DATA(EplayerScoreVertikalLeft, 9, playerScoreVertikalLeft, 9);
	ASSERT_DATA(EplayerScoreLeftDiagonalLeft, 9, EplayerScoreLeftDiagonalLeft, 9);
	ASSERT_DATA(EplayerScoreRightDiagonalLeft, 9, playerScoreRightDiagonalLeft, 9);
	ASSERT_DATA(EhightStepPlayer, 9, hightStepPlayer, 9);
	ASSERT_DATA(EweightStepPlayer, 9,weightStepPlayer, 9);*/
}

CTEST(testing_suite, checkWwin) 
{
	//GIVEN
	int choice = 0, score = 2, winX = 0, winO = 0;

	//WHEN
	const int result = checkWin(score, choice, &winX, &winO);

	//THEN
	const int expected = 0;
	ASSERT_EQUAL(expected, result);
	ASSERT_INTERVAL(0, 1, choice);
	ASSERT_INTERVAL(0, 1, winX);
	ASSERT_INTERVAL(0, 1, winO);
	ASSERT_INTERVAL(0, 5, score);
}
