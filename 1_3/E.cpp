#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	int F = 0, S = 0, G = 0;

	int button[2];

	cin >> F >> S >> G >> button[0] >> button[1];

	button[1] *= -1;
	vector<bool> visited(F + 1, false);
	queue<pair<int, int>> q;
	q.push({ 0, S });
	visited[S] = true;

	int cnt = -1;

	while (!q.empty())
	{
		int depth = q.front().first;
		int curr_loc = q.front().second;

		if (curr_loc == G)
		{
			cnt = depth;
			break;
		}

		q.pop();

		for (int i = 0; i < 2; ++i)
		{
			if (0 < curr_loc + button[i] && curr_loc + button[i] <= F)
			{
				if (!visited[curr_loc + button[i]])
				{
					q.push({ depth + 1,curr_loc + button[i] });
					visited[curr_loc + button[i]] = true;
				}
			}
		}
	}

	if (cnt == -1)
		cout << "use the stairs";
	else
		cout << cnt;

	return 0;
}