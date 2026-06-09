#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    set<int> unique_primes;

    sort(numbers.begin(), numbers.end());

    do {
        for (int i = 1; i <= numbers.size(); i++) {
            int num = stoi(numbers.substr(0, i));
            if (isPrime(num)) {
                unique_primes.insert(num);
            }
        }
    } while (next_permutation(numbers.begin(), numbers.end()));

    return unique_primes.size();
}