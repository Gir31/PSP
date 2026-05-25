#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_VALUE 1e9

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = MAX_VALUE;

    long long start = 0;
    long long end = n;
    long long mid = 0;

    sort(times.begin(), times.end());

    while (start <= end)
    {
        mid = (start + end) / 2;
        long long current_client = n;
        long long sum = 0;

        for (int examiner : times) {
            if (current_client > 0) 
            {
                if(current_client - mid >= 0)
                {
                    sum = max(sum, examiner * mid);
                    current_client -= mid;
                }
                else
                {
                    sum = max(sum, examiner * current_client);
                    current_client -= mid;
                }
            }
            else
            {
                break;
            }
        }

        if (current_client > 0)
        {
            start = mid + 1;
        }
        else
        {
            if (sum < answer)
            {
                answer = sum;
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
    }

    return answer;
}

int main()
{
    int n = 0, m = 0;
    cin >> n >> m;

    vector<int> times(n , 0);

    for (int i = 0; i < n; ++i)
    {
        cin >> times[i];
    }

    long long answer = solution(m, times);

    cout << answer << endl;
    return 0;
}