#include <iostream>
#include <vector>
#include <string>

using namespace std;

pair<int, int> direction[8]{ {-1, 0}, {-1, -1}, { 0, -1 }, {1, -1}, { 1, 0 }, {1, 1}, { 0, 1 }, {-1, 1} };

void DFS(pair<int, int> loc, int w, int h, vector<vector<bool>>& visited, const vector<vector<bool>>& seaMap)
{
	visited[loc.second][loc.first] = true;

	for (int dir = 0; dir < 8; ++dir)
	{
		int nextX = loc.first + direction[dir].first;
		int nextY = loc.second + direction[dir].second;

		if ((0 <= nextX && nextX < w) && (0 <= nextY && nextY < h))
		{
			if (seaMap[nextY][nextX] && !visited[nextY][nextX])
				DFS({nextX, nextY}, w, h, visited, seaMap);
		}
	}
}

int searchLand(int w, int h, const vector<vector<bool>>& seaMap)
{
	int landCnt = 0;

	vector<vector<bool>> visited(h, vector<bool>(w, false));

	for (int row = 0; row < h; ++row)
	{
		for (int col = 0; col < w; ++col)
		{
			if (seaMap[row][col] && !visited[row][col])
			{
				++landCnt;

				DFS({ col, row }, w, h, visited, seaMap);
			}

			visited[row][col] = true;
		}
	}

	return landCnt;
}

int main()
{
	int w = 0, h = 0;
	vector<int> landCnt;

	while (true)
	{
		cin >> w >> h;

		if (w == 0 && h == 0) break;

		vector<vector<bool>> seaMap;
		
		for (int row = 0; row < h; ++row)
		{
			vector<bool> v;
			for (int col = 0; col < w; ++col)
			{
				bool n = false;
				cin >> n;

				v.push_back(n);
			}
			seaMap.push_back(v);
		}

		landCnt.push_back(searchLand(w, h, seaMap));
	}

	for (int cnt : landCnt)
		cout << cnt << endl;

	return 0;
}