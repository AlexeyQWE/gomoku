#include <ctest.h>
#include <stdio.h>
#include <prototypes.h>

#define TABLE_Y 16

CTEST(testing_suite, main_menu) 
{
	//WHEN
	const int result = main_menu();

	//THEN
	ASSERT_INTERVAL(0, 5, result);
}

CTEST(testing_suite, correct_entering) 
{
	//GIVEN
	int menu = 1, settings = 0;

	//WHEN
	const int result = correct_entering(menu, settings);

	//THEN 
	ASSERT_INTERVAL(0, 15, result);
}

CTEST(testing_suite, fill_gameboard) 
{
	//GIVEN
	char tableGame[TABLE_Y][TABLE_Y];
	int limitMovesX = 50, limitMovesO = 50;

	//WHEN
	fill_gameboard(tableGame);
	print_gameboard(tableGame, limitMovesX, limitMovesO);

	//THEN
	const char expected = '_';
	for(int i = 0; i < TABLE_Y; i++) {
		for(int j = 0; j < TABLE_Y; j++) {
			ASSERT_EQUAL(expected, tableGame[i][j]);
		}
	}
}

CTEST(testing_suite, entering_coord) 
{
	//GIVEN
	char tableGame[TABLE_Y][TABLE_Y];
	int choice = 0, height = 0, widht = 0, winExit = 0;

	//WHEN
	entering_coord( choice,  winExit,  &height,  &widht, tableGame);

	//THEN
	ASSERT_INTERVAL(0, 1, choice);
	ASSERT_INTERVAL(0, 1, winExit);
	ASSERT_INTERVAL(1, 15, height);
	ASSERT_INTERVAL(1, 15, widht);
}

CTEST(testing_suite, prioritization) 
{
	//GIVEN
	int level = 2, playerScore = 0, dopusk = 0, outPutReplics = 0;
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
	prioritization(level, playerScoreGorizont, playerScoreVertikal, playerScoreLeftDiagonal, playerScoreRightDiagonal, playerScoreGorizontLeft, 
		playerScoreVertikalLeft, playerScoreLeftDiagonalLeft, playerScoreRightDiagonalLeft, &playerScore, hightStepPlayer, weightStepPlayer, dopusk, 
		&outPutReplics);

	//THEN
	const int expected1 = 2;
	const int expected2 = 0;
	ASSERT_EQUAL(expected1, level);
	ASSERT_EQUAL(expected2, dopusk);
	ASSERT_INTERVAL(0, 10, playerScore);
	ASSERT_INTERVAL(0, 10, outPutReplics);
}

CTEST(testing_suite, control) 
{
	//GIVEN
	char tableGame[16][16];

	for(int i = 0; i < TABLE_Y; i++){
		for(int j = 0; j < TABLE_Y; j++){
			tableGame[i][j] = '_';
		}
	}
	tableGame[6][6] = 'X';

	int exit = 0, widht = 6, i = widht - 1, choice = 0, score = 0, height = 6, spaceFinder = 0, zamok = 0, check = 0;

	//WHEN
	control(exit, i, choice, tableGame, height, &score, &spaceFinder, height, height, i - 1, i + 1, &check, i, &zamok);

	//THEN
	const int expended1 = 0;
	const int expended2 = 6;
	const int expended3 = 5;
	ASSERT_EQUAL(expended1, exit);
	ASSERT_EQUAL(expended2, widht);
	ASSERT_EQUAL(expended2, height);
	ASSERT_EQUAL(expended3, i);
	ASSERT_EQUAL(expended1, choice);
	ASSERT_INTERVAL(0, 5, score);
	ASSERT_INTERVAL(0, 1, spaceFinder);
	ASSERT_INTERVAL(0, 1, zamok);
	ASSERT_INTERVAL(0, 1, check);

}

CTEST(testing_suite, check_to_win) 
{
	//GIVEN
	char tableGame[TABLE_Y][TABLE_Y];
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

CTEST(testing_suite, check_to_win_bot) 
{
	//GIVEN
	char tableGame[TABLE_Y][TABLE_Y];
	int choice = 0, widht = 1, height = 1, winExit = 0, winX = 0, winO = 0;
	int botScoreGorizont[9] = {'\0'};
	int botScoreVertikal[9] = {'\0'};
	int botScoreLeftDiagonal[9] = {'\0'};
	int botScoreRightDiagonal[9] = {'\0'};
	int botScoreGorizontLeft[9] = {'\0'};
	int botScoreVertikalLeft[9] = {'\0'};
	int botScoreLeftDiagonalLeft[9] = {'\0'};
	int botScoreRightDiagonalLeft[9] = {'\0'};
	int hightAtakBot[9] = {'\0'};
	int weightAtakBot[9] = {'\0'};

	//WHEN
	check_to_win_bot(tableGame, choice, widht, height, winExit, &winX, &winO, botScoreGorizont, botScoreVertikal, botScoreLeftDiagonal, botScoreRightDiagonal, 
					botScoreGorizontLeft, botScoreVertikalLeft, botScoreLeftDiagonalLeft, botScoreRightDiagonalLeft, hightAtakBot, weightAtakBot);

	//THEN
	const int expected = 0;
	ASSERT_INTERVAL(0, 1, choice);
	ASSERT_INTERVAL(1, 15, widht);
	ASSERT_INTERVAL(1, 15, height);
	ASSERT_EQUAL(expected, winExit);
	ASSERT_EQUAL(expected, winX);
	ASSERT_EQUAL(expected, winO);
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

CTEST(testing_suite, rules) 
{
	//GIVEN
	int menu = 3, settings = 0;

	//WHEN
	rules(menu, settings);

	//THEN 
	const int expended = 3;
	ASSERT_EQUAL(expended, menu);
}

CTEST(testing_suite, table_name) 
{
	//GIVEN
	struct winner tablname[15];
	int menu = 4, settings = 0;

	//WHEN
	table_name(menu, settings, tablname);

	//THEN 
	const int expended = 4;
	ASSERT_EQUAL(expended, menu);
}

CTEST(testing_suite, move_bot_easy) 
{
	//GIVEN
	char tableGame[16][16];

	for(int i = 0; i < TABLE_Y; i++){
		for(int j = 0; j < TABLE_Y; j++){
			tableGame[i][j] = '_';
		}
	}
	tableGame[6][6] = 'X';

	int level = 2, choice = 1, hodBot = 0, height = 6, widht = 6, winX = 0, winO = 0;
	int hightAtakBot[9] = {'\0'};
	int weightAtakBot[9] = {'\0'};

	//WNEN
	move_bot_easy(level, tableGame, choice, hightAtakBot, weightAtakBot, &hodBot, &winX, &winO, height, widht);

	//THEN

	const int expended1 = 2;
	const int expended2 = 1;
	const int expended3 = 6;
	ASSERT_EQUAL(expended1, level);
	ASSERT_EQUAL(expended2, choice);
	ASSERT_EQUAL(expended3, height);
	ASSERT_EQUAL(expended3, widht);
	ASSERT_EQUAL(expended2, hodBot);
	ASSERT_INTERVAL(0, 1, hodBot);
	ASSERT_INTERVAL(0, 1, winX);
	ASSERT_INTERVAL(0, 1, winO);

}

CTEST(testing_suite, move_bot_defender) 
{
	//GIVEN
	int choice = 1, hodBot = 0, height = 6, widht = 6;
	char tableGame[16][16];
	for(int i = 0; i < TABLE_Y; i++){
		for(int j = 0; j < TABLE_Y; j++){
			tableGame[i][j] = '_';
		}
	}
	tableGame[6][6] = 'X';
	int playerScoreGorizont[9] = {'\0'};
	int playerScoreVertikal[9] = {'\0'};
	int playerScoreLeftDiagonal[9] = {'\0'};
	int playerScoreRightDiagonal[9] = {'\0'};
	int playerScoreGorizontLeft[9] = {'\0'};
	int playerScoreVertikalLeft[9] = {'\0'};
	int playerScoreLeftDiagonalLeft[9] = {'\0'};
	int playerScoreRightDiagonalLeft[9] = {'\0'};
	int hightAtakBot[9] = {0,0,0,0,0,0,0,0,6};
	int weightAtakBot[9] = {0,0,0,0,0,0,0,0,6};

	//WHEN
	move_bot_defender(tableGame, playerScoreGorizont, playerScoreVertikal, playerScoreLeftDiagonal, playerScoreRightDiagonal, playerScoreGorizontLeft, 
		playerScoreVertikalLeft, playerScoreLeftDiagonalLeft, playerScoreRightDiagonalLeft, &hodBot, choice, height, widht, hightAtakBot, weightAtakBot);

	//THEN

	const int expended1 = 1;
	const int expended2 = 6;
	ASSERT_EQUAL(expended1, choice);
	ASSERT_EQUAL(expended2, height);
	ASSERT_EQUAL(expended2, widht);
	ASSERT_EQUAL(expended1, hodBot);
	ASSERT_INTERVAL(0, 1, hodBot);
}

CTEST(testing_suite,move_bot_gotizont) 
{
	//GIVEN
	char tableGame[16][16];
	for(int i = 0; i < TABLE_Y; i++){
		for(int j = 0; j < TABLE_Y; j++){
			tableGame[i][j] = '_';
		}
	}
	tableGame[6][6] = 'X';
	int choice = 1, hodBot = 0, height = 6, widht = 6, exit = 1, i = 5;

	//WHEN
	move_bot_gotizont(choice, tableGame, &i, height, &hodBot, exit, &widht);

	//THEN
	const int expected = 1;
	ASSERT_EQUAL(expected, hodBot);
	ASSERT_EQUAL(5, widht);
	ASSERT_EQUAL(exit, i);
}