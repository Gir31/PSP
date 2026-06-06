#include <string>
#include <vector>
#include <map>
using namespace std;

#define MONTH 12
#define DAY 28

long long GetDate(int y, int m, int d)
{
    return (long long)(y * MONTH * DAY) + ((m - 1) * DAY) + d;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;

    int y, m, d;
    sscanf(today.c_str(), "%d.%d.%d", &y, &m, &d);
    long long iToday = GetDate(y, m, d);

    map<char, int> mTerms;
    for (string term : terms)
    {
        char variety;
        int duration;
        sscanf(term.c_str(), "%c %d", &variety, &duration);
        mTerms[variety] = duration * DAY;
    }

    int idx = 1;
    for (string privacy : privacies)
    {
        char variety;
        sscanf(privacy.c_str(), "%d.%d.%d %c", &y, &m, &d, &variety);
        long long deadLine = GetDate(y, m, d) + mTerms[variety] - 1;
        if (deadLine < iToday)
            answer.push_back(idx);
        idx++;
    }

    return answer;
}

/////////////////////////////////////////////////////////////////////////////////////////
// 流立 颇教窍绰 版快
//
//#include <sstream>
//
//long long GetDate(int y, int m, int d)
//{
//    return (long long)(y * MONTH * DAY) + ((m - 1) * DAY) + d;
//}
//
//vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
//    vector<int> answer;
//
//    int y, m, d;
//    char dot;
//    stringstream ss(today);
//    ss >> y >> dot >> m >> dot >> d;
//    long long iToday = GetDate(y, m, d);
//
//    map<char, int> mTerms;
//    for (string term : terms)
//    {
//        char variety;
//        int duration;
//        stringstream ss(term);
//        ss >> variety >> duration;
//        mTerms[variety] = duration * DAY;
//    }
//
//    int idx = 1;
//    for (string privacy : privacies)
//    {
//        char variety;
//        stringstream ss(privacy);
//        ss >> y >> dot >> m >> dot >> d >> variety;
//        long long deadLine = GetDate(y, m, d) + mTerms[variety] - 1;
//        if (deadLine < iToday)
//            answer.push_back(idx);
//        idx++;
//    }
//
//    return answer;
//}