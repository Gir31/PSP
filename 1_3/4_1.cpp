#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> profits;
	int T = 0;

	cin >> T;

	for (int i = 0; i < T; ++i)
	{
		int N = 0;
		cin >> N;

		int maxProfit = 0;

		for (int j = 0; j < N; ++j)
		{
			int A = 0, B = 0, C = 0;
			cin >> A >> B >> C;

			int max = 0;

			if (max < A)  max = A;
			if (max < B)  max = B;
			if (max < C)  max = C;

			maxProfit += max;
		}

		profits.push_back(maxProfit);
	}

	for (int profit : profits)
		cout << profit << endl;

	return 0;
}