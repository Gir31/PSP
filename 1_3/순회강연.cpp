#include <iostream>
#include <map>
#include <queue>

#define MAXINT 1e9

using namespace std;

int main()
{
	int n = 0;
	cin >> n;

	map<int, priority_queue<int>> m;
	
	for (int i = 0; i < n; ++i)
	{
		int p = 0, d = 0;
		cin >> p >> d;
		m[d].push(p);
	}

	int sum = 0;
	for (auto it = m.rbegin(); it != m.rend(); ++it)
	{
		int max_p = it->second.top();

		sum += max_p;
	}

	cout << sum << endl;

	return 0;
}