#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	vector<pair<int, int>> score1;
	vector<pair<int, int>> score2;

	for (int i = 0; i < n; ++i)
	{
		int score = 0;
		cin >> score;

		score--;

		score1.push_back({score, n - i});
	}
	sort(score1.begin(), score1.end(), [](pair<int, int> left, pair<int, int> right)
		{
			return left.first < right.first;
		});

	for (int i = 0; i < n; ++i)
	{
		int score = 0;
		cin >> score;

		score2.push_back({ i + 1, score });
	}
	sort(score2.begin(), score2.end(), [](pair<int, int> left, pair<int, int> right)
		{
			return left.second > right.second;
		});
	for (int i = 0; i < n; ++i)
	{
		score2[i].second = n - i;
	}
	
	for (int i = 0; i < n; ++i)
	{
		score2[i].second += score1[score2[i].first - 1].second;
	}

	sort(score2.begin(), score2.end(), [](pair<int, int> left, pair<int, int> right)
		{
			return left.second > right.second;
		});

	for (int i = 0; i < n; ++i)
	{
		if (score2[i].first < 10)
		{
			cout << i + 1 << ". Kod0" << score2[i].first << " (" << score2[i].second << ")" << endl;
		}
		else
		{
			cout << i + 1 << ". Kod" << score2[i].first << " (" << score2[i].second << ")" << endl;
		}
	}
	return 0;
}