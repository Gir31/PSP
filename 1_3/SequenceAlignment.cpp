#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N;
	cin >> N;

	vector<pair<int, int>> A(N, { 0, 0 });
	vector<int> P(N, 0);

	for (int i = 0; i < N; ++i)
	{
		cin >> A[i].first;
		A[i].second = i;
	}
		
	sort(A.begin(), A.end(), [](pair<int, int>left, pair<int, int> right)
		{
			if (left.first == right.first) return left.second < right.second;
			return left.first < right.first;
		});

	for (int i = 0; i < N; ++i)
	{
		P[A[i].second] = i;
	}


	for (int num : P)
		cout << num << " ";
	

	return 0;
}

