#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int N = 0;

	cin >> N;

	getchar();

	string line;
	int cupHolder = 0;

	if (getline(cin, line))
	{
		string sheet;
		for (char ch : line)
		{
			if (ch == 'L')
			{
				sheet += ch;
				if (sheet.length() == 2)
				{
					cupHolder++;
					sheet.clear();
				}
			}
			else if(ch == 'S')
			{
				cupHolder++;
			}
		}

		if (N != 0)
		{
			cupHolder += 1;
		}
	}

	int answer = min(cupHolder, N);

	cout << answer;

	return 0;
}