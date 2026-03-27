#include <iostream>
#include <vector>
#include <string>

using namespace std;

void preOrder(char currNode, const vector<vector<char>> tree)
{
	if (currNode == '.') return;
	cout << currNode;
	preOrder(tree[currNode - 'A'][0], tree);
	preOrder(tree[currNode - 'A'][1], tree);
}

void inOrder(char currNode, const vector<vector<char>> tree)
{
	if (currNode == '.') return;
	inOrder(tree[currNode - 'A'][0], tree);
	cout << currNode;
	inOrder(tree[currNode - 'A'][1], tree);
}

void postOrder(char currNode, const vector<vector<char>> tree)
{
	if (currNode == '.') return;
	postOrder(tree[currNode - 'A'][0], tree);
	postOrder(tree[currNode - 'A'][1], tree);
	cout << currNode;
}

void treePrint(const vector<vector<char>> tree)
{
	preOrder('A', tree);
	cout << endl;
	inOrder('A', tree);
	cout << endl;
	postOrder('A', tree);
}

int main()
{
	int N = 0;

	cin >> N;

	vector<vector<char>> tree;

	for (int i = 0; i < N; ++i)
	{
		vector<char> child;
		tree.push_back(child);
	}

	for (int i = 0; i < N; ++i)
	{
		char root, left, right;

		cin >> root >> left >> right;

		tree[root - 'A'].push_back(left);
		tree[root - 'A'].push_back(right);
	}

	treePrint(tree);
	

	return 0;
}