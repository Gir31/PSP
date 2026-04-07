#include <iostream>
#include <vector>
#include <string>

using namespace std;

pair<int, int> getLight(int x, int height)
{
	return {x - height, x + height};
}

int getMinHeight(int N, vector<int> x)
{
	int start = 0;
	int end = N;

	int minHeight = N;

	bool flag = false;

	while (start <= end)
	{
		int mid = (start + end) / 2;

		int dark = 0;

		for (int loc : x)
		{
			pair<int, int> light = getLight(loc, mid);

			if (dark >= light.first)
			{
				dark = light.second;
			}
			else
			{
				flag = true;
				break;
			}

			if (dark >= N) break;
		}

		if (dark < N) flag = true;

		if (flag)
		{
			start = mid + 1;
			flag = false;
		}
		else
		{
			if (minHeight > mid) minHeight = mid;
			end = mid - 1;
		}
	}

	return minHeight;
}

int main()
{
	int N = 0, M = 0;
	vector<int> x;

	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		int loc = 0;
		cin >> loc;
		x.push_back(loc);
	}

	cout << getMinHeight(N, x) << endl;

	return 0;
}