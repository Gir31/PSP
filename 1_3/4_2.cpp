#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int solution(vector<pair<int, int>> meetingTimes)
{
	if (meetingTimes.empty()) return 0;

	sort(meetingTimes.begin(), meetingTimes.end(), [](const pair<int, int> left, const pair<int, int> right)
		{
			if (left.second == right.second) return left.first < right.first;
			return left.second < right.second;
		});

	int cnt = 1;
	int finishTime = meetingTimes[0].second;

	for (int i = 1; i < meetingTimes.size(); ++i)
	{
		if (meetingTimes[i].first >= finishTime) {
			finishTime = meetingTimes[i].second;
			++cnt;
		}
	}

	return cnt;
}

int main()
{
	int N = 0;
	vector<pair<int, int>> meetingTimes;

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		int startTime = 0, finishTime = 0;

		cin >> startTime >> finishTime;

		meetingTimes.push_back({ startTime, finishTime });
	}

	cout << solution(meetingTimes);

	return 0;
}