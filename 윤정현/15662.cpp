#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t, k;
    cin >> t;
    vector<string> gear(t + 1);
    for (int i = 1; i <= t; i++) cin >> gear[i];

    vector<int> rotate(t + 1, 0);
    int n, dir;
    cin >> k;
    while (k--) {
        cin >> n >> dir;

        fill(rotate.begin(), rotate.end(), 0);

        rotate[n] = dir;
        int prev = gear[n][6], p_dir = dir;
        for (int i = n - 1; i >= 1; i--) {
            if (gear[i][2] == prev) {
                break;
            } else {
                p_dir = (p_dir == -1) ? 1 : -1;
                rotate[i] = p_dir;
                prev = gear[i][6];
            }
        }

        prev = gear[n][2], p_dir = dir;
        for (int i = n + 1; i <= t; i++) {
            if (gear[i][6] == prev) {
                break;
            } else {
                p_dir = (p_dir == -1) ? 1 : -1;
                rotate[i] = p_dir;
                prev = gear[i][2];
            }
        }

        for (int i = 1; i <= t; i++) {
            if (rotate[i] == 1) {
                gear[i] = gear[i][7] + gear[i].substr(0, 7);
            } else if (rotate[i] == -1) {
                gear[i] = gear[i].substr(1) + gear[i][0];
            }
        }
    }

    int s = 0;
    for (int i = 1; i <= t; i++)
        if (gear[i][0] == '1') s++;

    cout << s << "\n";

    return 0;
}
