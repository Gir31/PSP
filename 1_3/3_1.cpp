#include <iostream>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>


using namespace std;

vector<set<int>> edges;

vector<int> visitedDFS;

void DFS(int V)
{
	int currNode = V;

	if (find(visitedDFS.begin(), visitedDFS.end(), currNode) == visitedDFS.end())
	{
		visitedDFS.push_back(currNode);
	}
	else return;

	for (int node : edges[currNode - 1])
	{
		DFS(node);
	}

}

vector<int> visitedBFS;
queue<int> searchQueue;

void BFS(int V)
{
	visitedBFS.push_back(V);
	searchQueue.push(V);

	while (!searchQueue.empty())
	{
		int currNode = searchQueue.front();
		searchQueue.pop();

		for (int node : edges[currNode - 1])
		{
			if (find(visitedBFS.begin(), visitedBFS.end(), node) == visitedBFS.end())
			{
				visitedBFS.push_back(node);
				searchQueue.push(node);
			}
		}
	}
}

int main()
{
	int N = 0, M = 0, V = 0;

	cin >> N >> M >> V;

	edges.resize(N);

	for (int i = 0; i < M; ++i)
	{
		int a = 0, b = 0;
		cin >> a >> b;

		edges[a - 1].insert(b);
		edges[b - 1].insert(a);
	}

	DFS(V);
	for (int node : visitedDFS)
		cout << node << " ";

	cout << endl;

	BFS(V);
	for (int node : visitedBFS)
		cout << node << " ";

	return 0;
}