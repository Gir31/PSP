#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N = 0, K = 0;
	cin >> N >> K;

	vector<vector<int>> arr(K, vector<int>(N));
	for (int i = 0; i < K; ++i)
		for (int j = 0; j < N; ++j)
			cin >> arr[i][j];

	for (int i = 0; i < K; ++i)
	{
		next_permutation(arr[i].begin(), arr[i].end());

		for (int j = 0; j < N; ++j)
			cout << arr[i][j] << " ";
		cout << "\n";
	}

	return 0;
}