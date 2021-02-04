#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, k;
int main() {
    cin >> n >> k;
    vector<int> child(n);
    for (int i = 0; i < n; i++) cin >> child[i];

    sort(child.begin(), child.end());

    if (k == 1) {
        cout << child[n - 1] - child[0] << "\n";
        return 0;
    }

    vector<pair<int, int>> diff;
    for (int i = 1; i < n; i++) diff.push_back({child[i] - child[i - 1], i});

    sort(diff.begin(), diff.end(), greater<pair<int, int>>());

    vector<int> idx;
    for (int i = 0; i < k - 1; i++) idx.push_back(diff[i].second);

    sort(idx.begin(), idx.end());

    int ans = 0;
    for (int i = 0; i < k - 1; i++) {
        ans += (i == 0) ? child[idx[i] - 1] - child[0]
                        : child[idx[i] - 1] - child[idx[i - 1]];
    }
    ans += child[n - 1] - child[idx[k - 2]];

    cout << ans << "\n";

    return 0;
}
