#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N = 0, M = 0;
vector<int> trees;

int cutTree(int min, int max)
{
	long long meter = 0;
	int result = 0;

	while (min <= max) {
		int mid = (min + max) / 2;
		long long current_meter = 0;

		for (int tree : trees) {
			if (tree > mid) current_meter += (tree - mid);
		}

		if (current_meter >= M) {
			result = mid;   
			min = mid + 1;     
		}
		else {              
			max = mid - 1;       
		}
	}

	return result;
}

int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		int tree = 0;
		cin >> tree;
		trees.push_back(tree);
	}

	int height = *max_element(trees.begin(), trees.end());

	cout << cutTree(1, height);

	return 0;
}