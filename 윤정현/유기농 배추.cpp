#include <iostream>
#include <queue>
#define MAX 50 + 1
#define X first
#define Y second
using namespace std;

int t, m, n, k;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main(){
    cin >> t;
    while(t--){
        bool board[MAX][MAX] = {0};
        bool visited[MAX][MAX] = {0};

        cin >> m >> n >> k;
        int x, y;
        while(k--){
            cin >> x >> y;
            board[x][y] = 1;
        }

        int cnt = 0;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++){
                if(board[i][j] && !visited[i][j]){
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = 1;
                    cnt++;
                    while(!q.empty()){
                        auto cur = q.front();
                        q.pop();
                        for(int k=0; k<4; k++){
                            int nx = cur.X + dx[k];
                            int ny = cur.Y + dy[k];
                            if(nx < 0 || nx >= m || ny < 0 || ny >= n) continue;
                            if(visited[nx][ny] || !board[nx][ny]) continue;
                            visited[nx][ny] = 1;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        cout << cnt << "\n";
    }

    return 0;
}
