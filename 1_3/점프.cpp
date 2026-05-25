#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int N = 0;
	cin >> N;

	vector<vector<int>> board(N, vector<int>(N, 0));
	for (int y = 0; y < N; ++y)
	{
		for (int x = 0; x < N; ++x)
		{
			cin >> board[y][x];
		}
	}

	size_t mapSize = N * N;
	vector<vector<int>> route(N, vector<int>(N, 0));


	return 0;
}