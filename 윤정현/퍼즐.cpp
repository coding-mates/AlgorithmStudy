#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#define N 123456789
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {
    int n = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            int k;
            cin >> k;

            if (k == 0) k = 9;
            n = n * 10 + k;
        }
    }

    queue<int> q;
    map<int, int> visited;
    q.push(n);
    visited[n] = 0;

    while (!q.empty()) {
        int cur = q.front();
        string s = to_string(cur);
        q.pop();

        if (cur == N) break;

        int idx = s.find('9');

        int x = idx / 3;
        int y = idx % 3;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (0 <= nx && nx < 3 && 0 <= ny && ny < 3) {
                string temp = s;
                swap(temp[x * 3 + y], temp[nx * 3 + ny]);

                int nxt = stoi(temp);
                if (!visited.count(nxt)) {
                    visited[nxt] = visited[cur] + 1;
                    q.push(nxt);
                }
            }
        }
    }

    (!visited.count(N)) ? cout << -1 << "\n" : cout << visited[N] << "\n";

    return 0;
}
