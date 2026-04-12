#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int, int>> directions = {{0, 1}, { 0, -1 }, { -1, 0 }, { 1, 0 }};

pair<int, int> calPosition(pair<int, int> loc)
{ 
    return make_pair(loc.first + 1, loc.second + 1);
}
bool isTargetPosition(pair<int, int> currLoc, pair<int, int> target) 
{ 
    pair<int, int>  loc = calPosition(currLoc);
    return ((loc.first == target.first) && (loc.second == target.second));
}
bool isValidPosition(int height, int width, pair<int, int> loc) 
{ 
    return (((0 <= loc.first) && (loc.first < width)) && ((0 <= loc.second) && (loc.second < height))); 
}

int BFS(vector<vector<int>>& maps)
{
    queue<pair<int, int>> q;
    q.push(make_pair(0, 0));

    maps[0][0] = 0;

    int height = maps.size();
    int width = maps.front().size();

    while (!q.empty())
    {
        pair<int, int> curr_loc = q.front();
        int depth = curr_loc.first;
        int x = curr_loc.second % width; int y = curr_loc.second / width;
        q.pop();

        if (maps[y][x])
        {
            if (isTargetPosition({x, y}, {width, height}))
            {
                return depth + 1;
            }
            for (pair<int, int> direction : directions)
            {
                int new_x = x + direction.first;
                int new_y = y + direction.second;

                if (isValidPosition(height, width, { new_x, new_y }))
                {
                    maps[new_y][new_x] = 0;
                    q.push({depth + 1, (new_y * width) + new_x});
                }
            }
        }
    }

    return -1;
}

int solution(vector<vector<int>> maps)
{
    int answer = 0;

    answer = BFS(maps);

    return answer;
}

int main()
{
    vector<vector<int>> maps =
    {
        {1, 0, 1, 1, 1},
        {1, 0, 1, 0, 1},
        {1, 0, 1, 1, 1},
        {1, 1, 1, 0, 1},
        {0, 0, 0, 0, 1}
    };

    solution(maps);
    return 0;
}