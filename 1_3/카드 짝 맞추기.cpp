#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

const int INF = 987654321;

struct Point {
    int r, c, ctrl;
};

int dr[] = { -1, 1, 0, 0 };
int dc[] = { 0, 0, -1, 1 };

int get_shortest_path(const vector<vector<int>>& board, int start_r, int start_c, int end_r, int end_c) {
    vector<vector<int>> dist(4, vector<int>(4, INF));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;

    dist[start_r][start_c] = 0;
    pq.push({ 0, {start_r, start_c} });

    while (!pq.empty()) {
        int cost = pq.top().first;
        int r = pq.top().second.first;
        int c = pq.top().second.second;
        pq.pop();

        if (cost > dist[r][c]) continue;
        if (r == end_r && c == end_c) return cost;

        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < 4 && nc >= 0 && nc < 4) {
                if (cost + 1 < dist[nr][nc]) {
                    dist[nr][nc] = cost + 1;
                    pq.push({ cost + 1, {nr, nc} });
                }
            }

            nr = r;
            nc = c;
            while (true) {
                int nnr = nr + dr[i];
                int nnc = nc + dc[i];
                if (nnr < 0 || nnr >= 4 || nnc < 0 || nnc >= 4) break;
                nr = nnr;
                nc = nnc;
                if (board[nr][nc] != 0) break;
            }
            if (cost + 1 < dist[nr][nc]) {
                dist[nr][nc] = cost + 1;
                pq.push({ cost + 1, {nr, nc} });
            }
        }
    }
    return INF;
}

int match_cards(vector<vector<int>>& board, vector<pair<int, int>>& card_pos, const vector<int>& order, int idx, int r, int c) {
    if (idx == order.size()) return 0;

    int target_card = order[idx];
    vector<pair<int, int>> targets;
    for (int i = 1; i <= 6; ++i) {
        if (card_pos[i * 2 - 2].first != -1 && board[card_pos[i * 2 - 2].first][card_pos[i * 2 - 2].second] == target_card) {
            targets.push_back(card_pos[i * 2 - 2]);
            targets.push_back(card_pos[i * 2 - 1]);
            break;
        }
    }

    int p1_to_p2 = get_shortest_path(board, r, c, targets[0].first, targets[0].second)
        + get_shortest_path(board, targets[0].first, targets[0].second, targets[1].first, targets[1].second) + 2;

    int p2_to_p1 = get_shortest_path(board, r, c, targets[1].first, targets[1].second)
        + get_shortest_path(board, targets[1].first, targets[1].second, targets[0].first, targets[0].second) + 2;

    board[targets[0].first][targets[0].second] = 0;
    board[targets[1].first][targets[1].second] = 0;

    int res1 = p1_to_p2 + match_cards(board, card_pos, order, idx + 1, targets[1].first, targets[1].second);
    int res2 = p2_to_p1 + match_cards(board, card_pos, order, idx + 1, targets[0].first, targets[0].second);

    board[targets[0].first][targets[0].second] = target_card;
    board[targets[1].first][targets[1].second] = target_card;

    return min(res1, res2);
}

int solution(vector<vector<int>> board, int r, int c) {
    int answer = INF;
    vector<pair<int, int>> card_pos(12, { -1, -1 });
    vector<int> card_types;
    vector<bool> checked(7, false);

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            int num = board[i][j];
            if (num != 0) {
                if (!checked[num]) {
                    checked[num] = true;
                    card_types.push_back(num);
                    card_pos[num * 2 - 2] = { i, j };
                }
                else {
                    card_pos[num * 2 - 1] = { i, j };
                }
            }
        }
    }

    sort(card_types.begin(), card_types.end());

    do {
        answer = min(answer, match_cards(board, card_pos, card_types, 0, r, c));
    } while (next_permutation(card_types.begin(), card_types.end()));

    return answer;
}