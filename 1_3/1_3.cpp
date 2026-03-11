#include <iostream>
#include <string>
void Othello(int T)
{
	int length;
	std::string initState;
	std::string goalState;

	for (int i = 0; i < T; ++i)
	{
		std::cin >> length;
		std::cin >> initState;
		std::cin >> goalState;

		int wtoB = 0, btoW = 0;

		for (int j = 0; j < length; ++j)
		{
			if (initState[j] != goalState[j])
			{
				if (initState[i] == 'W')
				{
					wtoB++;
				}
				else {
					btoW++;
				}
			}
		}

		if (wtoB >= btoW)
			std::cout << wtoB << std::endl;
		else
			std::cout << btoW << std::endl;
	}
}

int main()
{
	int T = 0;
	std::cin >> T ;

	Othello(T);

	return 0;
}