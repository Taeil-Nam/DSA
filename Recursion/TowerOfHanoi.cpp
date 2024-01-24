#include <iostream>

// Hanoi(size, from, wait, to)
void Hanoi(int topSize, int a, int b, int c)
{
	if (topSize > 0)
	{
		Hanoi(topSize - 1, a, c, b); // c를 사용해서 a에 1개만 남기고 b로 보냄.
		std::cout << "move from " << a << " to " << c << std::endl; // a에 남아있는 1개를 c로 보냄.
		Hanoi(topSize - 1, b, a, c); // a를 사용해서 b에 남아있던 것들을 c로 보냄.
	}
}

int main()
{
	int topSize = 4;

	Hanoi(topSize, 1, 2, 3);

	return 0;
}
