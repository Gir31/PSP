#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main()
{
	int N = 0;

	cin >> N;

	vector<int> sugar(5001, 5001);

	for (int i = 3; i <= N; ++i)
	{
		if (i % 3 == 0) sugar[i] = i / 3;
		if (i % 5 == 0) sugar[i] = i / 5;
		if (i - 3 > 0) {
			sugar[i] = min(sugar[i], sugar[i - 3] + 1);
		}
		if (i - 5 > 0) {
			sugar[i] = min(sugar[i], sugar[i - 5] + 1);
		}
	}

	cout << (sugar[N] != 5001 ? sugar[N] : -1) << endl;

	return 0;
}

// c++에서 자주 사용하는 최댓값 초기화 방법
// vector<int> a(5000, numeric_limits<int>::max());