#include <string>
#include <vector>
#include <set>
#include <map>

using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer;

    set<string> gemType(gems.begin(), gems.end());
    int totalType = gemType.size();
    map<string, int> m;

    int start = 0;
    int end = 0;
    int min_len = gems.size() + 1;

    while (true) {
        if (m.size() == totalType) {
            if (end - start < min_len) {
                min_len = end - start;
                answer = { start + 1, end }; 
            }

            m[gems[start]]--;
            if (m[gems[start]] == 0) {
                m.erase(gems[start]); 
            }
            start++;
        }
        else if (end == gems.size()) {
            break;
        }
        else {
            m[gems[end]]++;
            end++;
        }
    }
    return answer;
}