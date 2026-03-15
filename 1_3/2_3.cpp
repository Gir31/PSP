#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	size_t n = 0;
	int preSlope = 0;
	vector<int> heights;
	vector<int> slopes;

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		char chart;
		cin >> chart;

		switch (chart)
		{
		case '+':
			if (i != 0 && (preSlope == 1)) 
			{
				heights.push_back(heights[i - 1] + 1);
			}
			else if (i != 0 && (preSlope != 1))
			{
				heights.push_back(heights[i - 1]);
			}
			else
			{
				heights.push_back(0);
			}

			preSlope = 1;

			slopes.push_back(1);
			break;
		case '-':
			if (i != 0 && (preSlope != 1))
			{
				heights.push_back(heights[i - 1] - 1);
			}
			else if (i != 0 && (preSlope == 1))
			{
				heights.push_back(heights[i - 1]);
			}
			else
			{
				heights.push_back(0);
			}

			preSlope = -1;

			slopes.push_back(-1);
			break;
		case '=':
			if (i != 0 && (preSlope == 1))
			{
				heights.push_back(heights[i - 1] + 1);
			}
			else if (i != 0 && (preSlope != 1))
			{
				heights.push_back(heights[i - 1]);
			}
			else
			{
				heights.push_back(0);
			}

			preSlope = 0;

			slopes.push_back(0);
			break;
		}
	}

	int maxY = *max_element(heights.begin(), heights.end());
	int minY = *min_element(heights.begin(), heights.end());

	int graphY = maxY - minY;

	for (int i = 0; i < n; ++i)
		heights[i] -= minY;

	for (int y = graphY; y > -1; --y) {
		for (int x = 0; x < n; ++x)
		{
			if (heights[x] == y)
			{
				switch (slopes[x])
				{
				case 1:
					cout << '/';
					break;
				case -1:
					cout << '\\';
					break;
				case 0:
					cout << '_';
					break;
				}
			}
			else
				cout << '.';
		}
		cout << endl;
	}

	return 0;
}