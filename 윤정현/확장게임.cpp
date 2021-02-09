#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#define P_MAX 10
#define MAX 1000 + 1
using namespace std;

int n, m, p;
queue<tuple<int, int, int>> q[P_MAX];
int move_cnt[P_MAX];
char board[MAX][MAX];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

int main(){
    cin >> n >> m >> p;
    for(int i=1; i<=p; i++) cin >> move_cnt[i];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            cin >> board[i][j];
            if(board[i][j] >= '1' && board[i][j] <= '9')
                q[board[i][j] - '0'].push({i, j, move_cnt[board[i][j]-'0']});
        }

    int x, y, cnt;
    while(1){            
        bool flag = false;
        for(int i=1; i<=p; i++){
            queue<tuple<int, int, int>> tmp = q[i];
            while(!tmp.empty()){
                tie(x, y, cnt) = tmp.front();
                tmp.pop();
                if(cnt == move_cnt[i]) q[i].pop();

                for(int k=0; k<4; k++){
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    int nCnt = cnt;
                    if(nCnt == 0) break;
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] != '.') continue;
                    board[nx][ny] = i + '0';
                    q[i].push({nx, ny, move_cnt[i]});
                    tmp.push({nx, ny, nCnt - 1});
                    flag = true;
                }
            }
        }
        if(!flag) break;
    }

    int answer[P_MAX] = {0};
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            if(board[i][j] >= '1' && board[i][j] <= '9') answer[board[i][j] - '0']++;

    for(int i=1; i<=p; i++) cout << answer[i] << ' ';
    return 0;
}
