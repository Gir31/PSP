#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Program_Data
{
    int score;
    int call_time;
    int run_time;
};

bool compareOrigin(const Program_Data& a, const Program_Data& b) {
    return a.call_time < b.call_time;
}

struct comparePQ {
    bool operator()(const Program_Data& a, const Program_Data& b) {
        if (a.score != b.score) {
            return a.score > b.score;
        }
        return a.call_time > b.call_time;
    }
};

vector<long long> solution(vector<vector<int>> program) {
    vector<long long> answer(11, 0);
    vector<Program_Data> pd;

    for (const auto& data : program) {
        pd.push_back({ data[0], data[1], data[2] });
    }

    sort(pd.begin(), pd.end(), compareOrigin);

    priority_queue<Program_Data, vector<Program_Data>, comparePQ> pq;

    long long current_time = 0;
    int idx = 0;           
    int total_programs = pd.size();

    while (idx < total_programs || !pq.empty()) {
        if (pq.empty() && current_time < pd[idx].call_time) {
            current_time = pd[idx].call_time;
        }

        while (idx < total_programs && pd[idx].call_time <= current_time) {
            pq.push(pd[idx]);
            idx++;
        }
        if (!pq.empty()) {
            Program_Data active = pq.top();
            pq.pop();

            long long wait_time = current_time - active.call_time;
            answer[active.score] += wait_time; 
            current_time += active.run_time;
            answer[0] = current_time;
        }
    }

    return answer;
}