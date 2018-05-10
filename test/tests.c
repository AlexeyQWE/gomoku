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

