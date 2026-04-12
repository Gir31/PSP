#include <iostream>
#include <string>
#include <vector>

using namespace std;

int sum_vec(vector<int> numbers)
{
    int sum = 0;

    for (int num : numbers)
        sum += num;

    return sum;
}

int DFS(vector<int> numbers, int target, int depth, int curr_sum)
{
    int cnt = 0;
    if (depth == numbers.size())
    {
        return (curr_sum == target) ? 1 : 0;
    }

    int plus = DFS(numbers, target, depth + 1, curr_sum + numbers[depth]);
    int minus = DFS(numbers, target, depth + 1, curr_sum - numbers[depth]);

    return plus + minus;
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    answer = DFS(numbers, target, 0, 0);

    return answer;
}

int main()
{
    int cnt = solution({ 1, 1, 1, 1 ,1 }, 3);

    cout << cnt;

    return 0;
}