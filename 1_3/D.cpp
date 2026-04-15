#include <iostream>
#include <vector>
#include <string>

using namespace std;

pair<int, int> direction[4]{ {-1, 0}, { 0, -1 }, { 1, 0 }, { 0, 1 }};

void DFS(pair<int, int> loc, int w, int h, vector<vector<bool>>& visited, const vector<vector<bool>>& seaMap)
{
	visited[loc.second][loc.first] = true;

	for (int dir = 0; dir < 4; ++dir)
	{
		int nextX = loc.first + direction[dir].first;
		int nextY = loc.second + direction[dir].second;

		if ((0 <= nextX && nextX < w) && (0 <= nextY && nextY < h))
		{
			if (seaMap[nextY][nextX] && !visited[nextY][nextX])
				DFS({ nextX, nextY }, w, h, visited, seaMap);
		}
	}
}

int main()
{
	int N = 0;
	cin >> N;

	vector<vector<char>> map1;
	vector<vector<char>> map2;

	for (int y = 0; y < N; ++y)
	{
		vector<char> line1;
		vector<char> line2;
		for (int x = 0; x < N; ++x)
		{
			char ch;

			cin >> ch;

			line1.push_back(ch);
			if (ch == 'R' || ch == 'G')
			{
				line2.push_back('R');
			}
			else
			{
				line2.push_back('B');
			}
		}

		map1.push_back(line1);
		map2.push_back(line2);
	}

	return 0;
}