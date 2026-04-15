#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0;
	cin >> N;
	vector<int> P(N, 0);
	for (int i = 0; i < N; ++i)
	{
		cin >> P[i];
	}

	sort(P.begin(), P.end());

	for (int i = 1; i < N; ++i)
	{
		P[i] += P[i - 1];
	}

	cout << accumulate(P.begin(), P.end(), 0);

	return 0;
}