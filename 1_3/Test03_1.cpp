#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct GAS_STATION
{
	int range;
	int gas;
};

bool compare(const GAS_STATION& a, const GAS_STATION& b)
{
	return a.range < b.range;
}

struct ComparePQ
{
	bool operator()(const GAS_STATION& a, const GAS_STATION& b) {
		if (a.gas != b.gas) {
			return a.range < b.range;
		}
		return a.gas < b.gas;
	}
};

int main()
{
	int N = 0;
	cin >> N;
	vector<GAS_STATION> gs;
	for (int i = 0; i < N; ++i)
	{
		int range = 0, gas = 0;
		cin >> range >> gas;
		gs.push_back({ range, gas });
	}
	sort(gs.begin(), gs.end(), compare);

	int destination = 0;
	int curr_gas = 0;
	cin >> destination >> curr_gas;

	priority_queue<GAS_STATION, vector<GAS_STATION>, ComparePQ> pq;
	pq.push({0, curr_gas});

	long long current_range = 0;
	int idx = 0;
	int total_gas_station = N;

	int answer = -1;
	while (idx < total_gas_station || !pq.empty())
	{
		if (pq.empty() && current_range < gs[idx].range) {
			answer = -1;
			break;
		}

		while (idx < total_gas_station && gs[idx].range <= current_range) {
			pq.push(gs[idx]);
			idx++;
		}

		if (!pq.empty()) {
			GAS_STATION active = pq.top();
			pq.pop();
			current_range += active.gas;
			answer++;
		}

		if (current_range >= destination) break;
	}

	cout << answer << endl;

	return 0;
}