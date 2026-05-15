#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct RGB_COST
{
	int R_Cost;
	int G_Cost;
	int B_Cost;
};

int getMinCost(vector<RGB_COST>& colorCost)
{
	for (int i = 1; i < colorCost.size(); ++i)
	{
		colorCost[i].R_Cost += min(colorCost[i - 1].G_Cost, colorCost[i - 1].B_Cost);
		colorCost[i].G_Cost += min(colorCost[i - 1].R_Cost, colorCost[i - 1].B_Cost);
		colorCost[i].B_Cost += min(colorCost[i - 1].R_Cost, colorCost[i - 1].G_Cost);
	}

	return min({ colorCost.back().R_Cost, colorCost.back().G_Cost, colorCost.back().B_Cost });
}

int main()
{
	int N = 0;
	cin >> N;
	vector<RGB_COST> colorCost(N, RGB_COST{ 0, 0, 0 });

	for (int i = 0; i < N; ++i)
	{
		cin >> colorCost[i].R_Cost >> colorCost[i].G_Cost >> colorCost[i].B_Cost;
	}

	
	cout << getMinCost(colorCost);

	return 0;
}