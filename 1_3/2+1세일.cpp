#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N = 0;
	cin >> N;
	vector<int> Ci(N, 0);

	for (int i = 0; i < N; ++i)
	{
		cin >> Ci[i];
	}

	sort(Ci.begin(), Ci.end(), greater<int>());

	int sum = 0;
	for (int i = 0; i < N; ++i)
	{
		if (i % 3 != 2) sum += Ci[i];
	}

	cout << sum;

	return 0;
}