#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N = 0, M = 0;
	vector<vector<int>> m;

	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		vector<int> good;
		for (int j = 0; j < 4; ++j)
		{
			int num = 0;
			cin >> num;
			good.push_back(num);
		}
		m.push_back(good);
	}

	return 0;
}