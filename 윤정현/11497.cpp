#include <algorithm>
#include <iostream>
#define MAX 10000 + 1
using namespace std;

int t, n;
int board[MAX];

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> board[i];
        sort(board, board + n);

        int mx = 0;
        for (int i = 2; i < n; i++) {
            mx = max(mx, board[i] - board[i - 2]);
        }

        cout << mx << "\n";
    }

    return 0;
}
