#include <iostream>
#include <queue>
#define MAX 100 + 1
#define X first
#define Y second
using namespace std;

int n, m;
bool board[MAX][MAX];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool bfs() {
    int visited[MAX][MAX];
    for (int i = 0; i < n; i++) fill(visited[i], visited[i] + m, -1);

    queue<pair<int, int>> q;
    visited[0][0] = 0;
    q.push({0, 0});

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int nx = cur.X + dx[k];
            int ny = cur.Y + dy[k];

            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if (board[nx][ny])
                visited[nx][ny]++;
            else {
                if (visited[nx][ny] == -1) {
                    visited[nx][ny] = 0;
                    q.push({nx, ny});
                }
            }
        }
    }

    bool flag = false;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (visited[i][j] >= 1) {
                board[i][j] = 0;
                flag = true;
            }

    return flag;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> board[i][j];

    int time = 0;
    while (bfs()) {
        time++;
    }

    cout << time << "\n";
    return 0;
}
