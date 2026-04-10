#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N = 0;

	cin >> N;

	vector<int> sugar(5001, 0);

	for (int i = 3; i <= N; ++i)
	{
		if (i % 3 == 0) sugar[i] = i / 3;
		if (i % 5 == 0) sugar[i] = i / 5;
		if (i - 3 > 0 && sugar[i - 3]) {
			if(sugar[i]) sugar[i] = min(sugar[i], sugar[i - 3] + 1);
			else sugar[i] = sugar[i - 3] + 1;
		}
		if (i - 5 > 0 && sugar[i - 5]) {
			if (sugar[i]) sugar[i] = min(sugar[i], sugar[i - 5] + 1);
			else sugar[i] = sugar[i - 5] + 1;
		}
	}

	cout << (sugar[N] ? sugar[N] : -1) << endl;

	return 0;
}