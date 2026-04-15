#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool rowCheck(vector<vector<int>>& sdoku)
{
	for (vector<int> sdokuCol : sdoku)
	{
		int check = 0;
		for (int num : sdokuCol)
		{
			if (num == 0) continue;
			if (check & (1 << num)) return true;
			check |= (1 << num);
		}
	}

	return false;
}

bool colCheck(vector<vector<int>>& sdoku)
{
	for (int col = 0; col < 9; ++col)
	{
		int check = 0;
		for (int row = 0; row < 9; ++row)
		{
			int num = sdoku[row][col];
			if (num == 0) continue;
			if (check & (1 << num)) return true;
			check |= (1 << num);
		}
	}

	return false;
}

bool boxCheck(vector<vector<int>>& sdoku)
{
	vector<int> box_masks(9, 0);

	for (int row = 0; row < 9; ++row)
	{
		for (int col = 0; col < 9; ++col)
		{
			int num = sdoku[row][col];
			if (num == 0) continue;

			int b_idx = (row / 3) * 3 + (col / 3);

			if (box_masks[b_idx] & (1 << num))
				return true; 

			box_masks[b_idx] |= (1 << num);
		}
	}
	return false;
}

int main()
{
	int n = 0;
	cin >> n;
	getchar();

	string line;

	for(int j = 0; j < n; ++j)
	{
		vector<vector<int>> sdoku;
		for (int i = 0; i < 13; ++i)
		{
			if (getline(cin, line))
			{
				vector<int> sdoku_line;
				for (char ch : line)
				{
					string numbers;
					if (isdigit(ch))
					{
						numbers += ch;
						int num = stoi(numbers);
						sdoku_line.push_back(num);
						numbers.clear();
					}
					else if (ch == '.')
					{
						sdoku_line.push_back(0);
					}
				}
				if (!sdoku_line.empty())
					sdoku.push_back(sdoku_line);
			}
		}

		if (rowCheck(sdoku))
		{
			cout << "N" << endl;
		}
		else if (colCheck(sdoku))
		{
			cout << "N" << endl;
		}
		else if (boxCheck(sdoku))
		{
			cout << "N" << endl;
		}
		else
		{
			cout << "Y" << endl;
		}
	}



	return 0;
}