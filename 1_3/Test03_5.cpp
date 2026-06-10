#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;

int main()
{
	int N = 0, K = 0;
	cin >> N >> K;

	vector<int> a;
	for (int i = 0; i < N; ++i)
	{
		int num = 0;
		cin >> num;
		a.push_back(num);
	}

	set<int> intType(a.begin(), a.end());
	int totalInt=intType.size();
	map<int, int> m;


	int start = 0;
	int end = 0;
	int len = 0;
    vector<int> answer;
    while (true) {
        if (m.size() == totalInt) {
            len = end - start;

            m[a[start]]--;
            if (m[a[start]] == 0) {
                m.erase(a[start]);
            }


            start++;
        }
        else if (end == a.size()) {
            break;
        }
        else {
            m[a[end]]++;
            end++;
        }
    }

    cout << answer[1] - answer[0];

	return 0;
}