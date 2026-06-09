#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct CMD
{
    char cmd_type;
    int move;
};

int pre_idx[1000005];
int nxt_idx[1000005];

string solution(int n, int k, vector<string> cmd) {
    string answer = "";

    for (int i = 0; i < n; ++i) {
        pre_idx[i] = i - 1;
        nxt_idx[i] = i + 1;
    }
    nxt_idx[n - 1] = -1;

    vector<bool> Table(n, true);
    stack<int> delete_data;
    int curr_select = k;

    for (const string& data : cmd)
    {
        char type = data[0];

        switch (type)
        {
        case 'U':
        {
            int move = stoi(data.substr(2));
            while (move--) {
                curr_select = pre_idx[curr_select];
            }
            break;
        }
        case 'D':
        {
            int move = stoi(data.substr(2));
            while (move--) {
                curr_select = nxt_idx[curr_select];
            }
            break;
        }
        case 'C':
        {
            Table[curr_select] = false;
            delete_data.push(curr_select);

            int prev = pre_idx[curr_select];
            int next = nxt_idx[curr_select];

            if (prev != -1) nxt_idx[prev] = next;
            if (next != -1) pre_idx[next] = prev;

            if (next == -1)
                curr_select = prev;
            else
                curr_select = next;
            break;
        }
        case 'Z':
        {
            if (!delete_data.empty())
            {
                int data_idx = delete_data.top();
                delete_data.pop();
                Table[data_idx] = true;

                int prev = pre_idx[data_idx];
                int next = nxt_idx[data_idx];

                if (prev != -1) nxt_idx[prev] = data_idx;
                if (next != -1) pre_idx[next] = data_idx;
            }
            break;
        }
        default:
            break;
        }
    }

    for (bool data : Table)
    {
        answer += data ? 'O' : 'X';
    }

    return answer;
}