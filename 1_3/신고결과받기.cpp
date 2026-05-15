#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;

    map<string, set<string>> report_list;

    for (string r : report)
    {
        stringstream str(r);
        string reporter;
        string reported_user;

        str >> reporter >> reported_user;

        report_list[reporter].insert(reported_user);
    }

    map<string, int> reported_cnt;

    for (string id : id_list)
        reported_cnt[id] = 0;

    for (auto it = report_list.begin(); it != report_list.end(); ++it)
    {
        for (string reported_user : it->second)
        {
            reported_cnt[reported_user]++;
        }
    }

    for (string id : id_list)
    {
        int ban_user = 0;
        for (string reported_user : report_list[id])
        {
            if (reported_cnt[reported_user] >= k) ban_user++;
        }
        answer.push_back(ban_user);
    }

    return answer;
}

int main()
{
    vector<string> id_list = { "con", "ryan" };
    vector<string> report = { "ryan con", "ryan con", "ryan con", "ryan con" };

    vector<int> results = solution(id_list, report, 2);

    for (int result : results)
        cout << result;

    return 0;
}