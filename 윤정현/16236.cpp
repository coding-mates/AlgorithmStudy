#include <cstring>
#include <iostream>
#include <queue>
#define MAX 20 + 1
#define INF 400 + 1
#define X first
#define Y second
using namespace std;

int n;
int board[MAX][MAX], dist[MAX][MAX];

pair<int, int> shark;
int shark_size = 2;

int mn_dist = INF;
int fish_cnt = 0;
pair<int, int> nxt_shark;

int time = 0;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void reset() {
    mn_dist = INF;
    nxt_shark = {MAX, MAX};
    memset(dist, -1, sizeof(dist));
}

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    dist[x][y] = 0;

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];

            if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if (dist[nx][ny] != -1 || board[nx][ny] > shark_size) continue;

            dist[nx][ny] = dist[cur.X][cur.Y] + 1;
            if (board[nx][ny] && board[nx][ny] < shark_size) {
                if (mn_dist > dist[nx][ny]) {
                    mn_dist = dist[nx][ny];
                    nxt_shark = {nx, ny};
                } else if (mn_dist == dist[nx][ny]) {
                    if (nx < nxt_shark.X ||
                        (nx == nxt_shark.X && ny < nxt_shark.Y))
                        nxt_shark = {nx, ny};
                }
            }
            q.push({nx, ny});
        }
    }
}
int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 9) {
                shark = {i, j};
                board[i][j] = 0;
            }
        }

    while (1) {
        reset();
        bfs(shark.X, shark.Y);
        if (mn_dist == INF) break;

        fish_cnt++;
        if (fish_cnt == shark_size) {
            shark_size++;
            fish_cnt = 0;
        }

        time += dist[nxt_shark.X][nxt_shark.Y];
        board[nxt_shark.X][nxt_shark.Y] = 0;

        shark = nxt_shark;
    }

    cout << time << "\n";

    return 0;
}
