#include <algorithm>
#include <iostream>
#include <vector>

int n, k;

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    vector<int> v(n);

    for (int i = 0; i < n; i++) cin >> v[i];

    if (n <= k) {
        cout << "0\n";
        return 0;
    }

    sort(v.begin(), v.end());

    vector<int> board(n - 1);
    for (int i = 0; i < n - 1; i++) board[i] = v[i + 1] - v[i];

    sort(board.begin(), board.end());

    int sum = 0;
    for (int i = 0; i < n - k; i++) sum += board[i];

    cout << sum << "\n";

    return 0;
}
