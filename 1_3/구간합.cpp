#include <iostream>
#include <vector>

using namespace std;

int find_progression(const int& n, const vector<int>& v, int left, int right)
{
	int res = 0;
	int sumValue = 0;

	vector<int> prefixSum(n + 1, 0);

	for (int i = 0; i < n; ++i)
	{
		sumValue += v[i];
		prefixSum[i + 1] = sumValue;
	}

	res = prefixSum[right] - prefixSum[left - 1];

	return res;
}

int main()
{
	cout << find_progression(5, { 10, 20, 30, 40, 50 }, 3, 4) << endl;

	return 0;
}