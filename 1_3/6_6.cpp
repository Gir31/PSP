#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int X = 0;

	cin >> X;

	vector<int> num(1'000'001, 1'000'000);
	num[1] = 0;

	for (int i = 1; i <= X; ++i)
	{
		if (i % 3 == 0) num[i] = min(num[i], num[i / 3] + 1);
		if (i % 2 == 0) num[i] = min(num[i], num[i / 2] + 1);
		num[i] = min(num[i], num[i - 1] + 1);
	}

	cout << num[X];

	return 0;
}