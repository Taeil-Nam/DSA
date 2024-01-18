#include <iostream>

/*
Recursion structure

recursion(parameter)
{
	if (baseCondition)
	{
		~~~ // Ascending statement.
		recursion(...) // Recursion.
		~~~ // Descending statement.
	}
}
*/

void recursion(int number)
{
	if (number > 0)
	{
		std::cout << number << std::endl;	// Ascending statement. (재귀 함수 호출 시점에 실행됨)
		recursion(number - 1);
		std::cout << "recursion(" << number << ") finished." << std::endl;	// Descending statement. (재귀 함수 탈출 시점에 실행됨)
	}
}

int main()
{
	int number = 5;

	recursion(number);

	return 0;
}
