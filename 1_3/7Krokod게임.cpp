#include <iostream>
#include <vector>
#include <string>

using namespace std;

int getKrokodScore(int d, int k, int o, int r)
{
	int score = 0;
	int flag = d * k * o * r;

	while (flag > 0)
	{
		d -= 1; k -= 2; o -= 2; r -= 1;
		flag = d * k * o * r;
		if (d >= 0 && k >= 0 && o >= 0 && r >= 0) score += 7;
	}


	return score;
}

int getCardScore(int card)
{
	return card * card;
}

int getTotalScore(int d, int k, int o, int r)
{
	return getCardScore(d) + getCardScore(k) + getCardScore(o) +
		getCardScore(r) + getKrokodScore(d, k, o, r);
}


int main()
{
	int n = 0, m = 0;
	cin >> n >> m;

	int d = 0, k = 0, o = 0, r = 0;

	for (int i = 0; i < n; ++i)
	{
		char ch;
		cin >> ch;

		switch (ch)
		{
		case 'd':
			d++;
			break;
		case 'k':
			k++;
			break;
		case 'o':
			o++;
			break;
		case 'r':
			r++;
			break;
		}
	}

	int max_score = getTotalScore(d, k, o, r);;
	for (int i = 0; i < m; ++i)
	{
		int dn = d, kn = k, on = o, rn = r;
		int curr_score = 0;

		curr_score = getTotalScore(dn + 1, kn, on, rn);

		if (max_score < curr_score)
		{
			d += 1;


			max_score = curr_score;
		}

		curr_score = getTotalScore(dn, kn + 1, on, rn);

		if (max_score < curr_score)
		{
			d -= 1;
			k += 1;
			max_score = curr_score;
		}

		curr_score = getTotalScore(dn, kn, on + 1, rn);

		if (max_score < curr_score)
		{
			k -= 1;
			o += 1;
			max_score = curr_score;
		}

		curr_score = getTotalScore(dn, kn, on, rn + 1);

		if (max_score < curr_score)
		{
			o -= 1;
			r += 1;
			max_score = curr_score;
		}
	}
	
	cout << max_score;

	return 0;
}

//krokod