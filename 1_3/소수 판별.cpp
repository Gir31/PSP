#include <iostream>

using namespace std;

// 소수 판별
bool isPirmeNumber(int x)
{
	for (int i = 2; i <= (int)sqrt(x); ++i)
	{
		if (x % i == 0)
			return false;
	}
	return true;
}

int main()
{
	cout << isPirmeNumber(4) << endl;
	cout << isPirmeNumber(7) << endl;

	return 0;
}