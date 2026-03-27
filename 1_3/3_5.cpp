#include<iostream>
#include<vector>
#include<string>

using namespace std;

int R, C;
vector<string> board;
bool visited[26];
pair<int, int> directions[4] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int maxDepth;

void DFS(pair<int, int> currLoc, int depth)
{
	if (maxDepth < depth) maxDepth = depth;

	for (int i = 0; i < 4; ++i)
	{
		int x = currLoc.first + directions[i].first;
		int y = currLoc.second + directions[i].second;

		if ((0 <= x && x < C) && (0 <= y && y < R))
		{
			if (!visited[board[y][x] - 'A'])
			{
				visited[board[y][x] - 'A'] = true;

				DFS({ x, y }, depth + 1);

				visited[board[y][x] - 'A'] = false;
			}
		}
	}
}

int main()
{
	cin >> R >> C;

	for (int i = 0; i < R; ++i)
	{
		string str;

		cin >> str;

		board.push_back(str);
	}

	visited[board[0][0] - 65] = true;

	DFS({ 0,0 }, 0);

	cout << maxDepth + 1;

	return 0;
}

//비트마스킹(Bitmasking) 활용
//알파벳은 26개이므로, 32비트 정수 하나(int)의 각 비트를 하나의 알파벳으로 매칭할 수 있습니다.
//
//방문 체크 : (visited & (1 << (board[ny][nx] - 'A')))
//
//방문 표시 : visited | (1 << (board[ny][nx] - 'A'))
//int bit = 1 << (board[nr][nc] - 'A');
// 비트 연산으로 방문 여부 확인
//if (!(visited & bit)) {
//	DFS(nr, nc, visited | bit, depth + 1);
//}