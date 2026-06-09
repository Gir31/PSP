#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());

    while (!pq.empty())
    {
        int first_scov = pq.top(); 
        if (first_scov >= K) break;
        pq.pop();
        int second_scov;
        if(!pq.empty())
        {
            second_scov = pq.top();
            pq.pop();
        }
        else
        {
            answer = -1;
            break;
        }

        int result_scov = first_scov + (second_scov * 2);

        pq.push(result_scov);
        answer++;
    }

    return answer;
}