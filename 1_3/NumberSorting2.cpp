#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	// 반드시 넣어주자
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	vector<int> A(N, 0);
	for (int i = 0; i < N; ++i)
		cin >> A[i];

	sort(A.begin(), A.end());

	for (int num : A)
		cout << num << '\n';

	return 0;
}