#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;

vector<int> solution(vector<string> operations) {
    priority_queue<int> max_pq;                           
    priority_queue<int, vector<int>, greater<int>> min_pq; 
    map<int, int> cnt;                                     

    for (string operation : operations) {
        char cmd = operation[0];
        int num = stoi(operation.substr(2));

        switch (cmd) {
        case 'I':
            max_pq.push(num);
            min_pq.push(num);
            cnt[num]++;
            break;

        case 'D':
            if (num == 1) {
                while (!max_pq.empty() && cnt[max_pq.top()] == 0)
                    max_pq.pop();
                if (!max_pq.empty()) {
                    cnt[max_pq.top()]--;
                    max_pq.pop();
                }
            }
            else {
                while (!min_pq.empty() && cnt[min_pq.top()] == 0)
                    min_pq.pop();
                if (!min_pq.empty()) {
                    cnt[min_pq.top()]--;
                    min_pq.pop();
                }
            }
            break;
        }
    }

    while (!max_pq.empty() && cnt[max_pq.top()] == 0) max_pq.pop();
    while (!min_pq.empty() && cnt[min_pq.top()] == 0) min_pq.pop();

    if (max_pq.empty() || min_pq.empty()) return { 0, 0 };

    return { max_pq.top(), min_pq.top() };
}