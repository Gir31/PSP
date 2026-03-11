#include<iostream>
#include<vector>

using namespace std;

int main()
{
	size_t n = 0;
	vector<char> charts;

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		char graph;
		cin >> graph;

		switch (graph)
		{
		case '+':
			graph = '/';
			break;
		case '-':
			graph = '\\';
			break;
		case '=':
			graph = '_';
			break;
		}

		charts.push_back(graph);
	}
	            
	for (char chart : charts)
		cout << chart << endl;
	


	return 0;
}