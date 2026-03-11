#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N = 0;
	int goalValue = 0;
	vector<int> coins;

	cin >> N >> goalValue;

	for (int i = 0; i < N; ++i)
	{
		int coin;
		cin >> coin;

		coins.push_back(coin);
	}

	int cnt = 0;

	while (goalValue > 0)
	{
		for (auto coin = coins.rbegin(); coin != coins.rend(); ++coin)
		{
			if (goalValue >= *coin)
			{
				cnt = cnt + (goalValue / *coin);
				goalValue %= *coin;
			}
		}
	}

	cout << cnt << endl;

	return 0;
}