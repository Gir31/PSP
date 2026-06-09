#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 소요시간 -> 요청시간 -> 작업 번호

struct Work
{
    int id;
    int call_time;
    int run_time;
};

bool compare(const Work& a, const Work& b)
{
    return a.call_time < b.call_time;
}

struct Compare_PQ
{
    bool operator()(const Work& a, const Work& b)
    {
        if (a.run_time != b.run_time) return a.run_time > b.run_time;
        if (a.call_time != b.call_time) return a.call_time > b.call_time;
        return a.id > b.id;
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;

    int job_size = jobs.size();
    vector<Work> works;
    for (int i = 0; i < job_size; ++i)
    {
        works.push_back({i, jobs[i][0], jobs[i][1]});
    }
    sort(works.begin(), works.end(), compare);

    int ms = 0;
    int idx = 0;

    vector<int> work_time(job_size, 0);
    priority_queue<Work, vector<Work>, Compare_PQ> pq;

    while (idx < job_size || !pq.empty())
    {
        while (idx < job_size)
        {
            if (works[idx].call_time <= ms)
            {
                pq.push(works[idx]);
                idx++;
            }
            else break;
        }

        if (!pq.empty())
        {
            Work curr_work = pq.top(); pq.pop();
            ms += curr_work.run_time;
            work_time[curr_work.id] = ms - curr_work.call_time;
        }
        else
            ms = works[idx].call_time;
    }

    for (int time : work_time)
    {
        answer += time;
    }
    answer /= job_size;

    return answer;
}