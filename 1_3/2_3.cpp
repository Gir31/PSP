#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main()
{
	size_t n = 0;
	int maxY = 0, centerY = 0, pos = 0, neg = 0;

	vector<int> flues;

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		char chart;
		int flue = 0;
		cin >> chart;

		switch (chart)
		{
		case '+':
			pos++;
			flue = 1;
			break;
		case '-':
			neg++;
			flue = -1;
			break;
		case '=':
			flue = 0;
			break;
		}

		flues.push_back(flue);
	}

	maxY = max(pos, neg) - 1;

	vector<int> heights;
	int height = 0;
	for (int i = 0; i < n; ++i)
	{
		if (i != 0 && flues[i] == flues[i - 1])
		{
			height += flues[i];
		}
		
		heights.push_back(height);
	}

	int minY = *(min_element(heights.begin(), heights.end()));

	for (int i = 0; i < n; ++i)
	{
		heights[i] -= minY;

		cout << heights[i] << endl;
	}

	for (int y = maxY; y != -1; --y)
	{
		for(int x = 0; x < n; ++x)
		{
			if (heights[x] == y) {
				switch (flues[x])
				{
				case 1:
					cout << '/';
					break;
				case 0:
					cout << '_';
					break;
				case -1:
					cout << '\\';
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