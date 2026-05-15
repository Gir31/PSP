#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
	long long N = 0;
	cin >> N;
	vector<int> request(N, 0);

	for (int i = 0; i < N; ++i)
		cin >> request[i];

	sort(request.begin(), request.end());

	int M = 0;
	cin >> M;

	int totalAmount = accumulate(request.begin(), request.end(), 0LL);
	if (totalAmount <= M)
	{
		cout << request.back();
	}
	else
	{
		int start = 0;
		int end = request.back();
		int answer = 0;

		while (start <= end)
		{
			int mid = (start + end) / 2;
			int sum = 0;
			bool flag = false;

			for (int i = 0; i < request.size(); ++i)
			{
				if (mid > request[i]) sum += request[i];
				else sum += mid;

				if (sum > M)
				{
					flag = true;
					break;
				}
			}

			if (flag) end = mid - 1;
			else
			{
				answer = mid;
				start = mid + 1;
			}
		}

		cout << answer;
	}

	return 0;
}