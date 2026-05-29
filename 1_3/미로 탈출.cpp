#include <string>
#include <vector>

using namespace std;

int solution(int n, int start, int end, vector<vector<int>> roads, vector<int> traps) {
    int answer = 0;

	vector<vector<pair<int, int>>> graph(n + 1);

    for (vector<int> road : roads)
    {
		graph[road[0]].push_back({ road[1], road[2] });
    }

    return answer;
}