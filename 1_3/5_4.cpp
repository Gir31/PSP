#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;

    for (int i = 0; i < n; ++i)
    {
        int result = arr1[i] | arr2[i];
        string str;
        for (int j = 0; j < n; ++j)
        {
            str += (result%2 ? '#' : ' ');
            result /= 2;
        }

        reverse(str.begin(), str.end());

        answer.push_back(str);
    }

    return answer;
}

int main()
{
    vector<string> maps;

    maps = solution(6, { 46, 33, 33, 22, 31, 50 }, { 27, 56, 19, 14, 14, 10 });

    for (string str : maps)
        cout << str << endl;

    return 0;
}