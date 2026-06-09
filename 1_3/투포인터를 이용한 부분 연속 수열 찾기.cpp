#include <iostream>
#include <vector>

using namespace std;

int find_progression(const int& n, const int& m, const vector<int>& v)
{
	int res = 0;
	int intervalSum = 0; int end = 0;

	for (int start = 0; start < n; ++start)
	{
		while (intervalSum < m && end < n)
		{
			intervalSum += v[end];
			end += 1;
		}
		if (intervalSum == m)
			res++;
		intervalSum -= v[start];
	}

	return res;
}

int main()
{
	cout << find_progression(5, 5, {1, 2, 3, 2, 5}) << endl;

	return 0;
}