#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	long long T = 0;
	vector<bool> answer;

	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		long long ia = 0, ib = 0, ic = 0;
		char ca = '\0', cb = '\0';

		cin >> ia >> ca >> ib >> cb >> ic;

		switch (ca)
		{
		case '+':
			answer.push_back(ic == ia + ib);
			break;
		case '-':
			answer.push_back(ic == ia - ib);
			break;
		case '/':
			answer.push_back(ic == ia / ib);
			break;
		case '*':
			answer.push_back(ic == ia * ib);
			break;
		}
	}

	for (bool a : answer)
		cout << (a ? "correct" : "wrong answer") << endl;

	return 0;
}