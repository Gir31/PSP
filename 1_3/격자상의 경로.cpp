#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

pair<int, int> getLoc(int M, int K)
{
	int x = K % M;
	int y = K / M;
	return {x, y};
}

int main()
{
	int N = 0, M = 0, K = 0; // N은 행, M은 열
	cin >> N >> M >> K;

	pair<int, int> goal1 = (K) ? getLoc(M, K - 1) : make_pair(0, 0);
	pair<int, int> goal2 = make_pair(M - goal1.first - 1, N - goal1.second - 1);

	size_t mapSize1 = (goal1.first + 1) * (goal1.second + 1);
	size_t mapSize2 = (goal2.first + 1) * (goal2.second + 1);

	vector<int> route1(mapSize1, 0); vector<int> route2(mapSize2, 0);
	route1[0] = (K) ? 1 : 0;
	route2[0] = 1;

	for (int i = 1; i < mapSize1; ++i)
	{
		int m = goal1.first + 1;
		pair<int, int> xy = getLoc(m ,i);
		int x = xy.first;
		int y = xy.second;

		if (x - 1 > -1)
		{
			route1[i] += route1[((y * m) + (x - 1))];
		}

		if (y - 1 > -1)
		{
			route1[i] += route1[((y - 1) * m + x)];
		}
	}

	for (int i = 1; i < mapSize2; ++i)
	{
		int m = goal2.first + 1;
		pair<int, int> xy = getLoc(m, i);
		int x = xy.first;
		int y = xy.second;

		if (x - 1 > -1)
		{
			route2[i] += route2[((y * m) + (x - 1))];
		}

		if (y - 1 > -1)
		{
			route2[i] += route2[((y - 1) * m + x)];
		}
	}

	int answer = (K) ? route1.back() * route2.back() : route2.back();

	cout << answer;

	return 0;
}