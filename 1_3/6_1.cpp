#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    vector<vector<int>> results;

    for (int i = 0; i < triangle.size(); ++i)
    {
        if (i != 0)
        {
            vector<int> result;
            size_t triangleSize = triangle[i].size();

            result.push_back(triangle[i][0] + results[i - 1][0]);
            for (int j = 1; j < triangleSize - 1; ++j)
            {
                result.push_back(triangle[i][j] + max(results[i - 1][j - 1], results[i - 1][j]));
            }
            result.push_back(triangle[i][triangleSize - 1] + results[i - 1][triangleSize - 2]);

            answer = *max_element(result.begin(), result.end());

            results.push_back(result);
        }
        else
        {
            results.push_back(triangle[i]);
        }
    }
    return answer;
}