#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;

    vector<int> attempt(N + 1, 0);

    vector<pair<int, float>> failureRate;

    for (int stage : stages) attempt[stage - 1]++;

    float totalPlayer = stages.size();

    for (int stage = 0; stage < N; ++stage)
    {
        if (totalPlayer == 0)
        {
            failureRate.push_back({stage + 1, 0.f});
        }
        else
        {
            float rate = (float)attempt[stage] / totalPlayer;
            failureRate.push_back({ stage + 1, rate });

            totalPlayer -= attempt[stage];
        }

    }

    sort(failureRate.begin(), failureRate.end(), [](pair<int, float> left, pair<int, float> right)
        {
            if (left.second == right.second) return left.first < right.first;

            return left.second > right.second;
        });

    for (int stage = 0; stage < N; ++stage)
        answer.push_back(failureRate[stage].first);


    return answer;
}

int main()
{
    int N = 4;
    vector<int> stages = {4, 4, 4, 4, 4};

    vector<int> rate = solution(N, stages);

    for (int n : rate)
        cout << n << " ";

    return 0;
}