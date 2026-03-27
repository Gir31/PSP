#include <iostream>
#include <vector>

using namespace std;

void matrix_std(int A, int B)
{
	cout << "M" << endl;

	for (int row = 0; row < A; ++row)
	{
		for (int col = 0; col < B; ++col)
		{
			cout << ((row * B) + col) + 1;
			if (col != B - 1) cout << " ";
		}
		cout << endl;
	}
}

void matrix_right(int A, int B)
{
	cout << "R" << endl;

	for (int col = 0; col < B; ++col)
	{
		for (int row = A - 1; row > -1; --row)
		{
			cout << ((row * B) + col) + 1;
			if (row != 0) cout << " ";
		}
		cout << endl;
	}
}

void matrix_left(int A, int B)
{
	cout << "L" << endl;

	for (int col = B - 1; col > -1; --col)
	{
		for (int row = 0; row < A; ++row)
		{
			cout << ((row * B) + col) + 1;
			if (row != A - 1) cout << " ";
		}
		cout << endl;
	}
}

void matrix_transposition(int A, int B)
{
	cout << "T" << endl;

	for (int col = 0; col < B; ++col)
	{
		for (int row = 0; row < A; ++row)
		{
			cout << ((row * B) + col) + 1;
			if (row != A - 1) cout << " ";
		}
		cout << endl;
	}
}

void print_matrix(int A, int B)
{
	matrix_std(A, B);
	matrix_right(A, B);
	matrix_left(A, B);
	matrix_transposition(A, B);
}

int main()
{
	int A = 0, B = 0;
	cin >> A >> B;

	print_matrix(A, B);

	return 0;
}