#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(int N, int K)
{
	int sec = 0;

	int currLocation = 0;
	int currSec = 0;
	bool visited[100'001] = { 0 };

	queue<pair<int, int>> q;

	q.push({ N, 0 });


	while (!q.empty())
	{
		currLocation = q.front().first;
		currSec = q.front().second;

		if (visited[currLocation]) {
			q.pop();
			continue;
		}
		else {
			visited[currLocation] = true;
			q.pop();
		}

		if (currLocation == K) {
			sec = currSec;
			break;
		}

		int next[3] = { currLocation - 1, currLocation + 1, currLocation * 2 };

		for (int loc : next)
		{
			if (loc >= 0 && loc <= 100'001)
				q.push({ loc, currSec + 1 });
		}
	}

	cout << sec;
}

int main()
{
	int N = 0, K = 0;

	cin >> N >> K;

	BFS(N, K);

	return 0;
}