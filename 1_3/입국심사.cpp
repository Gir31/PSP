#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;

    long long start = 0;
    long long end = n;
    long long mid = 0;

    int examiner = times.size();

    sort(times.begin(), times.end());

    while (start <= end)
    {
        mid = (start + end) / 2;
        long long totalClient = mid * examiner;

        if (totalClient < n)
        {
            start = mid + 1;
        }
        else if(totalClient == n)
        {
            start = mid + 1;
            answer = max(((long long)times.back() * mid), answer);
        }
        else
        {
            end = mid - 1;
            answer = min(((long long)times.back() * mid), answer);
        }
    }

    return answer;
}

int main()
{
    int n = 10;
    vector<int> times = { 7, 100000 };
    long long answer = solution(n, times);

    cout << answer << endl;
    return 0;
}