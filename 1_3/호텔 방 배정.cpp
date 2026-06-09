#include <vector>
#include <unordered_map>

using namespace std;

unordered_map<long long, long long> parent;

long long findParent(long long x) {
    if (parent.find(x) == parent.end()) {
        parent[x] = x + 1;
        return x;
    }
    return parent[x] = findParent(parent[x]);
}

vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> answer;

    for (long long num : room_number) {
        long long assigned_room = findParent(num);
        answer.push_back(assigned_room);
    }

    return answer;
}