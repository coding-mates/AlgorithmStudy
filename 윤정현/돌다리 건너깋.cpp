#include <cstring>
#include <iostream>
using namespace std;

string magic;
string stone[2];

int d[2][101][21];

int dp(int c, int r, int idx) {
    if (idx == magic.length()) return 1;

    int &result = d[c][r][idx];
    if (result != -1) return result;

    result = 0;
    for (int i = r; i < stone[0].length(); i++) {
        if (stone[c][i] == magic[idx]) result += dp(1 - c, i + 1, idx + 1);
    }

    return result;
}

int main() {
    cin >> magic;
    for (int i = 0; i < 2; i++) cin >> stone[i];

    memset(d, -1, sizeof(d));

    int ans = 0;
    for (int i = 0; i < 2; i++) ans += dp(i, 0, 0);

    cout << ans << "\n";
    return 0;
}
