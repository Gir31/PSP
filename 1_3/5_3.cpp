#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

int main()
{
	string line;
	stack<string> arith;

	if (getline(cin, line))
	{
		for (char ch : line)
		{
			if (ch == '+' || ch == '-')
			{
				string str1 = arith.top();
				arith.pop();
				string str2 = arith.top();
				arith.pop();

				string result;
				result = "(" + str2 + ch + str1 + ")";

				arith.push(result);
			}
			else
			{
				arith.push(string(1, ch));
			}
		}
	}

	cout << arith.top();

	return 0;
}