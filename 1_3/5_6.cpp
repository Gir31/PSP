#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N = 0, C = 0;

	cin >> N >> C;
	vector<int> xi(N, 0);

	for (int i = 0; i < N; ++i)
		cin >> xi[i];

	sort(xi.begin(), xi.end());

	int start = 1;
	int end = xi.back() - xi.front();
	int answer = 0;

	while (start <= end)
	{
		int mid = (start + end) / 2;
		int curr = xi.front();
		int use = 1;

		for (int i = 1; i < N; ++i)
		{
			if (xi[i] >= curr + mid)
			{
				curr = xi[i];
				use++;
			}
		}

		if (use >= C) 
		{
			answer = mid;
			start = mid + 1;
		}
		else if (use < C)
		{
			end = mid - 1;
		}
	}

	cout << answer;

	return 0;
}