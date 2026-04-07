#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minTime(vector<pair<int, int>> cows)
{
	int min = 0;

	for (pair<int, int> cow : cows)
	{
		if (min < cow.first) min = cow.first;

		min += cow.second;
	}

	return min;
}

int main()
{
	int N = 0;
	vector<pair<int, int>> cows;

	cin >> N;

	for (int order = 0; order < N; ++order)
	{
		int arrT = 0, reT = 0;

		cin >> arrT >> reT;

		cows.push_back({ arrT, reT });
	}

	sort(cows.begin(), cows.end());

	cout << minTime(cows) << endl;

	return 0;
}