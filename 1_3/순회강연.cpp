#include <iostream>
#include <queue>
#include <numeric>

#define MAXINT 1e9

using namespace std;

struct Compare
{
	bool operator()(const pair<int, int>& a, const pair<int, int>& b)
	{
		return a.first < b.first;
	}
};

int main()
{
	int n = 0;
	cin >> n;

	vector<int> day(10001, 0);

	priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
	
	for (int i = 0; i < n; ++i)
	{
		int p = 0, d = 0;
		cin >> p >> d;
		pq.push({p, d});
	}

	while (!pq.empty())
	{
		auto top = pq.top();
		pq.pop();

		for (int i = top.second; i >= 1; --i)
		{
			if (day[i] == 0)
			{
				day[i] = top.first;
				break;
			}
		}
	}

	int sum = accumulate(day.begin(), day.end(), 0);

	cout << sum << endl;

	return 0;
}