#include <vector>
#include <numeric>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;

    long long sum1 = 0;
    long long sum2 = 0;

    vector<int> combined;
    for (int num : queue1) { sum1 += num; combined.push_back(num); }
    for (int num : queue2) { sum2 += num; combined.push_back(num); }

    if ((sum1 + sum2) % 2 != 0) return -1;

    int p1 = 0;
    int p2 = queue1.size();

    int max_operations = queue1.size() * 4;

    while (sum1 != sum2) {
        if (answer > max_operations) return -1;

        if (sum1 > sum2) {
            sum1 -= combined[p1];
            sum2 += combined[p1];
            p1 = (p1 + 1) % combined.size(); 
        }
        else {
            sum1 += combined[p2];
            sum2 -= combined[p2];
            p2 = (p2 + 1) % combined.size();
        }
        answer++;
    }

    return answer;
}