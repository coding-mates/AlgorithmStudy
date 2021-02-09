#include <algorithm>
#include <iostream>
using namespace std;

int t, k;
pair<int, int> board[101];
int d[101][10001];

int main() {
    cin >> t >> k;
    int a, b;
    for (int i = 1; i <= k; i++) {
        cin >> a >> b;
        board[i] = {a, b};
    }
    sort(board, board + k);
    d[0][0] = 1;
    for (int i = 1; i <= k; i++)
        for (int j = 0; j <= board[i].second; j++)
            for (int x = 0; x <= t; x++) {
                if (board[i].first * j + x > t) break;
                d[i][x + board[i].first * j] += d[i - 1][x];
            }

    cout << d[k][t] << "\n";
    return 0;
}
