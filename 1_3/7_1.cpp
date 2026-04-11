#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void find_route(vector<vector<pair<int, int>>>& routes, vector<int>& fodder, priority_queue<pair<int, int>>& q, int curr_shed)
{
	for (pair<int, int> route : routes[curr_shed])
	{
		if (fodder[route.first] > fodder[curr_shed] + route.second)
		{
			fodder[route.first] = fodder[curr_shed] + route.second;
			
			q.push(route);
		}
	}


}

int main()
{
	int N = 0, M = 0;

	cin >> N >> M;

	vector<vector<pair<int, int>>> routes(N + 1);
	vector<int> fodder(N + 1, INFINITY);
	fodder[1] = 0;

	for (int i = 0; i < M; ++i)
	{
		int A_i = 0, B_i = 0, C_i = 0;

		cin >> A_i >> B_i >> C_i;

		routes[A_i].push_back(make_pair(B_i, C_i));
		routes[B_i].push_back(make_pair(A_i, C_i));
	}


	return 0;
}