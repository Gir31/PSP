#include <iostream>
#include<vector>
using namespace std;

vector<vector<int>> Floyd_Warshall(int n, vector<vector<int>>& graph)
{
    vector<vector<int>> dist(n, vector<int>(n , 0));

    for (int i = 0; i < n; ++i)
        for (int next : graph[i])
            dist[i][next] = 1;

    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                if (dist[i][k] && dist[k][j])
                    dist[i][j] = 1;

    return dist;
}

vector<vector<int> > solution(int n, vector<vector<int>> signs)
{
    vector<vector<int>> answer;

    vector<vector<int>> graph(n);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (signs[i][j] == 1) graph[i].push_back(j);
        }
    }
    answer = Floyd_Warshall(n, graph);
    return answer;
}