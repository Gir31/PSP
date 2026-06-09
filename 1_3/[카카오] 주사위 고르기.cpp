#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> comb(vector<int> lst, int n) {
    vector<vector<int>> ret;
    if (n > (int)lst.size()) return ret;
    if (n == 1) {
        for (int i : lst) ret.push_back({ i });
        return ret;
    }
    for (int i = 0; i <= (int)lst.size() - n; ++i) {
        vector<int> rest(lst.begin() + i + 1, lst.end());
        for (vector<int> temp : comb(rest, n - 1)) {
            vector<int> next_comb = { lst[i] };
            next_comb.insert(next_comb.end(), temp.begin(), temp.end());
            ret.push_back(next_comb);
        }
    }
    return ret;
}

void diceSum(const vector<vector<int>>& dice, int n,
    vector<int>& res, int cur, int sum) {
    if (cur == n) {
        res.push_back(sum);
        return;
    }
    for (int i = 0; i < 6; i++)
        diceSum(dice, n, res, cur + 1, sum + dice[cur][i]);
}

int find_rate(const vector<int>& A, const vector<int>& B) {
    int win = 0;
    for (int a : A)
        win += (int)(lower_bound(B.begin(), B.end(), a) - B.begin());
    return win;
}

vector<int> solution(vector<vector<int>> dice) {
    vector<int> answer;
    int dice_size = dice.size();

    vector<int> dice_id(dice_size);
    for (int i = 0; i < dice_size; ++i) dice_id[i] = i;

    vector<vector<int>> dice_combs = comb(dice_id, dice_size / 2);
    int high_win = -1;

    for (const vector<int>& dice_comb : dice_combs) {
        vector<vector<int>> A_dice, B_dice;
        int idx = 0;
        for (int i = 0; i < dice_size; ++i) {
            if (idx < (int)dice_comb.size() && i == dice_comb[idx]) {
                A_dice.push_back(dice[i]);
                idx++;
            }
            else {
                B_dice.push_back(dice[i]);
            }
        }

        vector<int> A_sum, B_sum;
        diceSum(A_dice, dice_size / 2, A_sum, 0, 0);
        diceSum(B_dice, dice_size / 2, B_sum, 0, 0);

        sort(B_sum.begin(), B_sum.end());
        int win = find_rate(A_sum, B_sum);

        if (win > high_win) {
            high_win = win;
            answer.clear();
            for (int id : dice_comb) answer.push_back(id + 1); // 1-indexed
        }
    }
    return answer;
}