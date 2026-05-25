#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N = 0, K = 0;
	cin >> N >> K;

	vector<vector<int>> arr(K, vector<int>(N));
	for(int i = 0; i < K; ++i)
		for (int j = 0; j < N; ++j)
			cin >> arr[i][j];

	return 0;
}