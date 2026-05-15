#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> money) {
    int answer = 0;

    vector<int> dpTable1(money.size() - 1, 0);
    vector<int> dpTable2(money.size(), 0);

    dpTable1[0] = money[0];
    dpTable1[1] = max(money[0], money[1]);

    for (int i = 2; i < money.size() - 1; ++i)
    {
        dpTable1[i] = max(money[i] + dpTable1[i - 2], dpTable1[i - 1]);
    }

    dpTable2[0] = 0;
    dpTable2[1] = money[1];

    for (int i = 2; i < money.size(); ++i)
    {
        dpTable2[i] = max(money[i] + dpTable2[i - 2], dpTable2[i - 1]);
    }

    answer = max(dpTable1.back(), dpTable2.back());

    return answer;
}