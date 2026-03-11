#include<iostream>
#include<string>

int main()
{
	std::string str1;
	std::string str2;

	int locateA = 0, locateB = 0;
	bool flag = false;

	std::cin >> str1 >> str2;

	for (int i = 0; i < str1.length(); ++i)
	{
		for (int j = 0; j < str2.length(); ++j)
		{
			if (str1[i] == str2[j])
			{
				locateA = j;
				locateB = i;
				flag = true;
				break;
			}
		}

		if (flag) break;
	}

	for (int i = 0; i < str2.length(); ++i)
	{
		for (int j = 0; j < str1.length(); ++j)
		{
			if (i == locateA)
				std::cout << str1[j];
			else if (j == locateB)
				std::cout << str2[i];
			else
				std::cout << ".";
		}
		std::cout << std::endl;
	}

	return 0;
}