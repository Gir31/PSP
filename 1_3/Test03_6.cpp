#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int R, C, Q;
	cin >> R >> C >> Q;
	vector<vector<int>> picture(R, vector<int>(C, 0));
	for (int i = 0; i < R; ++i)
	{
		for (int j = 0; j < C; ++j)
		{
			cin >> picture[i][j];
		}
	}



	vector<vector<int>> kv(Q, vector<int>(4,0));
	for (int i = 0; i < Q; ++i)
	{
		cin >> kv[i][0] >> kv[i][1] >> kv[i][2] >> kv[i][3];
	}

	vector<int> answer;

	for (int i = 0; i < Q; ++i)
	{
		int r1 = kv[i][0]; int c1 = kv[i][1];
		int r2 = kv[i][2]; int c2 = kv[i][3];

		int height = r2 - r1 + 1;
		int width = c2 - c1 + 1;
		int sum = 0;
		for (int y = r1 - 1; y < r2; y++)
		{
			for (int x = c1 - 1; x < c2; x++)
			{
				sum += picture[y][x];
			}
		}
		answer.push_back(sum / (width * height));
	}

	for (int i : answer)
	{
		cout << i << endl;
	}

	return 0;
}