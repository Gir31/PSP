#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;

    size_t mapSize = m * n;
    vector<int> route(mapSize, 0);
    vector<bool> Passable(mapSize, true);

    for (vector<int> puddle : puddles)
    {
        int loc = ((puddle[1] - 1) * m) + (puddle[0] - 1);
        Passable[loc] = false;
    }

    route[0] = 1;

    for (int i = 1; i < mapSize; ++i)
    {
        if (Passable[i])
        {
            int x = i % m; int y = i / m;

            if (x - 1 > -1)
            {
                route[i] += route[((y * m) + (x - 1))];
            }

            if (y - 1 > -1)
            {
                route[i] += route[((y - 1) * m + x)];
            }

            route[i] %= 1'000'000'007;
        }
    }

    answer = route.back();

    return answer;
}