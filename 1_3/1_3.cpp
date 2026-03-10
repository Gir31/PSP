#include <iostream>
#include <vector>
#include <string>

bool changeLocate(char* piece1, char* piece2)
{
	if (*piece1 == *piece2) return false;

	char tmp = *piece1;
	*piece1 = *piece2;
	*piece2 = tmp;

	return true;
}

void changeColor(char* piece)
{
	if (*piece == 'W')
		*piece = 'B';
	else
		*piece = 'W';
}

void Othello(int T)
{
	int length;
	std::string initState;
	std::string goalState;

	for (int i = 0; i < T; ++i)
	{
		int minCnt = 0;

		std::cin >> length;
		std::cin >> initState;
		std::cin >> goalState;

		for (int j = 0; j < length; ++j)
		{
			if (initState[j] != goalState[j])
			{
				bool flag = true;
				for (int k = j+1; k < length; ++k)
				{
					if (initState[k] != goalState[k])
						if (changeLocate(&initState[j], &initState[k])) {
							flag = false;

							minCnt++;
							break;
						}
				}

				if (flag) {
					changeColor(&initState[j]);
					minCnt++;
				}
			}
		}
		std::cout << minCnt << std::endl;
	}
}

int main()
{
	int T = 0;
	std::cin >> T ;

	Othello(T);

	return 0;
}