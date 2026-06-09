#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isPrime(long long num) {
    if (num < 2) return false;
    for (long long i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int solution(int n, int k) {
    int answer = 0;
    string converted = "";

    while (n > 0) {
        converted += to_string(n % k);
        n /= k;
    }
    reverse(converted.begin(), converted.end());

    string current = "";
    for (char c : converted) {
        if (c == '0') {
            if (!current.empty()) {
                if (isPrime(stoll(current))) {
                    answer++;
                }
                current = "";
            }
        }
        else {
            current += c;
        }
    }

    if (!current.empty()) {
        if (isPrime(stoll(current))) {
            answer++;
        }
    }

    return answer;
}