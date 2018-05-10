#include <ctest.h>
#include <stdio.h>
#include <prototypes.h>

CTEST(testing_suite, correct_entering)
{
	//WHEN
	const int result = correct_entering(); 

	//THEN
	ASSERT_INTERVAL(0, 5, result); //Проверка на то, что из функции вернется число от 0 до 5
}

CTEST(testing_suite, fill_and_print_gameboard)
{
	//GIVEN
	char tableGame [16][16];

	//WHEN
	const int result1 = fill_gameboard(tableGame);
	const int result2 = print_gameboard(tableGame);

	//Проверка на то, что из функции вернется 0(в случае выхода за границы масиива вернется NULL и тест будет провален)

	//THEN
	const int expected1 = 0;
	ASSERT_EQUAL(expected1, result1);
	const int expected2 = 0;
	printf("\n");
	ASSERT_EQUAL(expected2, result2);
}
