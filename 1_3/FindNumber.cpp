#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N = 0;
	cin >> N;
	vector<int> numbers(N, 0);

	for (int i = 0; i < N; ++i)
		cin >> numbers[i];

	return 0;
}