#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

int getTime(string time)
{
    stringstream ss(time);
    char sign;
    int HH, MM, SS;
    ss >> HH >> sign >> MM >> sign >> SS;

    return SS + (MM * 60) + (HH * 60 * 60);
}

string makeTimeString(int total_second) {
    int h = total_second / 3600;
    int m = (total_second % 3600) / 60;
    int s = total_second % 60;

    string res = "";
    if (h < 10) res += "0"; res += to_string(h) + ":";
    if (m < 10) res += "0"; res += to_string(m) + ":";
    if (s < 10) res += "0"; res += to_string(s);
    return res;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    int iplay_time = getTime(play_time);
    int iadv_time = getTime(adv_time);

    vector<long long> time(iplay_time + 5, 0);

    for (string log : logs)
    {
        stringstream ss(log);
        int H1, M1, S1, H2, M2, S2;
        char sign;
        ss >> H1 >> sign >> M1 >> sign >> S1 >> sign
            >> H2 >> sign >> M2 >> sign >> S2;

        int start_time = S1 + (M1 * 60) + (H1 * 60 * 60);
        int end_time = S2 + (M2 * 60) + (H2 * 60 * 60);

        time[start_time]++;
        time[end_time]--;
    }

    for (int i = 1; i <= iplay_time; ++i) {
        time[i] += time[i - 1];
    }

    for (int i = 1; i <= iplay_time; ++i) {
        time[i] += time[i - 1];
    }

    long long max_view_time = time[iadv_time - 1];
    int best_start_sec = 0;

    for (int i = 1; i <= iplay_time - iadv_time; ++i) {

        long long current_view_time = time[i + iadv_time - 1] - time[i - 1];

        if (current_view_time > max_view_time) {
            max_view_time = current_view_time;
            best_start_sec = i; 
        }
    }

    return makeTimeString(best_start_sec);
}