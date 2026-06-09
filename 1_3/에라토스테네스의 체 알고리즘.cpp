#include <iostream>
#include <vector>

using namespace std;

vector<bool> Sieve_of_Eratosthenes(const int n)
{
	vector<bool> arr(n + 1, true);

	for (int i = 2; i <= (int)sqrt(n); ++i)
	{
		if (arr[i] == true)
		{
			int j = 2;
			while (i * j <= n)
			{
				arr[i * j] = false;
				j += 1;
			}
		}
	}

	return arr;
}

int main()
{
	vector<bool> arr = Sieve_of_Eratosthenes(1000);

	for (int i = 2; i < arr.size(); ++i)
	{
		if (arr[i]) cout << i << ' ';
	}

	return 0;
}