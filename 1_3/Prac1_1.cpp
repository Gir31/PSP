#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

int getScoreGap(vector<int>& info1, vector<int> info2)
{
    int info1_score = 0, info2_score = 0;

    for (int i = 0; i < 11; ++i)
    {
        if (info1[i] >= info2[i]) info1_score += (10 - i);
        else if (info1[i] < info2[i]) info2_score += (10 - i);
    }

    return (info2_score - info1_score);
}
// info1 = apeach, info2 = ryan
vector<int> DFS(int arrow_cnt, int score, vector<int> info1, vector<int> info2)
{
    if (!arrow_cnt)
    {
        if (getScoreGap(info1, info2) > 0) return info2;
        else return { -1 };
    }

    int target_cnt[3] = {info1[10 - score] + 1, info1[10 - score], 0};
    for (int i = 0; i < 3; ++i)
    {
        info2[10 - score] = target_cnt[i];
        DFS(arrow_cnt - target_cnt[i], score + 1, info1, info2);
    }

}

vector<int> solution(int n, vector<int> info) {
    vector<int> answer;

    cout << "[ ";
    for (int i = 0; i < info.size(); ++i)
    {
        cout << info[i] << " ";
    }
    cout << "]" << endl;

    return answer;
}

int main()
{
    solution(5, { 2,1,1,1,0,0,0,0,0,0,0 });

    return 0;
}