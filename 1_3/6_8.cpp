#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N = 0;
	vector<int> A;
	vector<int> result;

	cin >> N;

	int num = 0;
	for (int i = 0; i < N; ++i)
	{
		cin >> num;
		A.push_back(num);
		result.push_back(num);
	}

	for (int i = 0; i < N; ++i)
	{
		vector<int> v;
		for(int j = i - 1; j > -1; --j)
		{
			if (A[i] > A[j])
			{
				v.push_back(A[i] + result[j]);
			}
		}
		if(!v.empty()) result[i] = *max_element(v.begin(), v.end());
	}

	cout << *max_element(result.begin(), result.end());
	
	return 0;
}