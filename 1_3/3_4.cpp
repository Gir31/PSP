#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool DFS(int cnt, string currCity, vector<bool>& visited, vector<string>& path, const vector<vector<string>>& tickets)
{
    if (cnt == tickets.size()) return true;

    for (int i = 0; i < tickets.size(); ++i)
    {
        if (!visited[i] && tickets[i][0] == currCity)
        {
            visited[i] = true;
            path.push_back(tickets[i][1]);

            if (DFS(cnt + 1, tickets[i][1], visited, path, tickets)) return true;

            visited[i] = false;
            path.pop_back();
        }
    }

    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    size_t ticketSize = tickets.size();

    sort(tickets.begin(), tickets.end());

    vector<bool> visited;

    for (int i = 0; i < ticketSize; ++i) visited.push_back(false);

    answer.push_back("ICN");

    DFS(0, "ICN", visited, answer, tickets);


    return answer;
}