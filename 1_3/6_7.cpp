#include <iostream>
#include <array>
#include <algorithm>

using namespace std;

int main()
{
	int N = 0;

	array<int, 3> lines{0, 0, 0};
	array<int, 3> line_max{ 0, 0, 0 };
	array<int, 3> line_min{ 0, 0, 0 };

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		cin >> lines[0] >> lines[1] >> lines[2];

		if (i) 
		{
			array<int, 3> max_num{ line_max[0], line_max[1], line_max[2] };
			array<int, 3> min_num{ line_min[0], line_min[1], line_min[2] };

			line_max[0] = max(max_num[0] + lines[0], max_num[1] + lines[0]);
			line_min[0] = min(min_num[0] + lines[0], min_num[1] + lines[0]);

			line_max[1] = max({ max_num[0] + lines[1], max_num[1] + lines[1], max_num[2] + lines[1] });
			line_min[1] = min({ min_num[0] + lines[1], min_num[1] + lines[1], min_num[2] + lines[1] });

			line_max[2] = max(max_num[1] + lines[2], max_num[2] + lines[2]);
			line_min[2] = min(min_num[1] + lines[2], min_num[2] + lines[2]);
		}
		else
		{
			line_max[0] = line_min[0] = lines[0];
			line_max[1] = line_min[1] = lines[1];
			line_max[2] = line_min[2] = lines[2];
		}
	}

	cout << max({ line_max[0], line_max[1] , line_max[2] }) << " " << min({ line_min[0], line_min[1], line_min[2] });

	return 0;
}