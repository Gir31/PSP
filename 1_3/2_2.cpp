#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N = 0, M = 0;
	vector<int> cards;

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		int card = 0;
		cin >> card;

		cards.push_back(card);
	}

	int max = 0;
	size_t cardSize = cards.size();

	for (int i = 0; i < cardSize - 2; i++)
	{
		for (int j = i + 1; j < cardSize - 1; j++)
		{
			for (int k = j + 1; k < cardSize; k++)
			{
				int sum = cards[i] + cards[j] + cards[k];
				if (sum <= M && sum > max) max = sum;
			}
		}
	}

	cout << max << endl;

	return 0;
}