#include <deque>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> board(n, vector<int>(n, 0));
    int x, y;
    while (k--) {
        cin >> x >> y;
        board[x - 1][y - 1] = 1;
    }

    int l, time;
    char r;
    cin >> l;
    queue<pair<int, char>> rotate;
    while (l--) {
        cin >> time >> r;
        rotate.push({time, r});
    }

    int dir = 0;
    x = 0;
    y = 0;
    time = 0;
    deque<pair<int, int>> dq;
    board[0][0] = 2;
    dq.push_back({0, 0});
    while (1) {
        time++;
        x = x + dx[dir];
        y = y + dy[dir];

        if (x < 0 || x >= n || y < 0 || y >= n || board[x][y] == 2) {
            cout << time << "\n";
            return 0;
        }
        dq.push_front({x, y});
        if (board[x][y] == 0) {
            auto back = dq.back();
            dq.pop_back();
            board[back.first][back.second] = 0;
        }
        board[x][y] = 2;

        if (rotate.front().first == time) {
            if (rotate.front().second == 'L') {
                dir = dir == 0 ? 3 : dir - 1;
            } else {
                dir = dir == 3 ? 0 : dir + 1;
            }
            rotate.pop();
        }
    }

    return 0;
}
