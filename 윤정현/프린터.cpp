#include <queue>
#include <vector>
using namespace std;

int solution(vector<int> priorities, int location) {
    queue<pair<int, int>> q;
    priority_queue<int, vector<int>, less<int>> pq;
    for (int i = 0; i < priorities.size(); i++) {
        q.push({priorities[i], i});
        pq.push(priorities[i]);
    }

    int idx = 1;
    while (!pq.empty()) {
        if (q.front().first == pq.top()) {
            if (q.front().second == location) break;
            q.pop();
            pq.pop();
            idx++;
        } else {
            q.push(q.front());
            q.pop();
        }
    }

    return idx;
}