#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
	int N = 0, M = 0;

	map<int, vector<pair<int, int>>> routes;

	cin >> N >> M;

	vector<int> fodder(N, -1);
	fodder[0] = 0;

	for (int i = 0; i < M; ++i)
	{
		int A_i = 0, B_i = 0, C_i = 0;

		cin >> A_i >> B_i >> C_i;

		routes[A_i].push_back(make_pair(B_i, C_i));
		routes[B_i].push_back(make_pair(A_i, C_i));
	}

	for (int shed = 0; shed < N; ++shed)
	{
		for (pair<int, int> route : routes[shed + 1])
		{
			if (fodder[route.first - 1] == -1)
			{
				fodder[route.first - 1] = route.second + fodder[shed];
			}
			else
			{
				fodder[route.first - 1] = min(fodder[route.first - 1], fodder[shed] + route.second);
			}
		}
	}

	cout << fodder.back();


	return 0;
}