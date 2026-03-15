#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    
    vector<int> students;

    for (int i = 1; i <= n; ++i)
    {
        int cloth = 1;

        if (find(lost.begin(), lost.end(), i) != lost.end()) cloth--;
        if (find(reserve.begin(), reserve.end(), i) != reserve.end()) cloth++;

        students.push_back(cloth);
    }

    for (int i = 0; i < n; ++i)
    {
        if (students[i] == 0)
        {
            if (i != 0 && students[i - 1] == 2)
            {
                students[i - 1]--;
                students[i]++;
                answer++;
            }else if (i != n-1 && students[i + 1] == 2)
            {
                students[i + 1]--;
                students[i]++;
                answer++;
            }
        }
        else {
            answer++;
        }
    }


    return answer;
}
