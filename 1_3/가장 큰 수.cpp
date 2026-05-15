#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";

    sort(numbers.begin(), numbers.end(), [](int a, int b) {
        string sa = to_string(a);
        string sb = to_string(b);
        return sa + sb > sb + sa;
		});

    if(numbers[0] == 0) {
        return "0";
	}
    
    for (int num : numbers) {
        answer += to_string(num);
    }

    return answer;
}

int main()
{
    vector<int> numbers = {6, 10, 2};
    string answer = solution(numbers);

    cout << answer << endl;

    return 0;
}