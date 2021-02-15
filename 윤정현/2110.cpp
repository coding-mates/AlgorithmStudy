#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, c, x;
int ans = 0;
vector<int> v;
int main() {
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());

    int left = 0, right = v[n - 1] - v[0];
    while (left <= right) {
        int mid = (left + right) / 2;
        int prev = 0, cnt = 1;

        for (int idx = 1; idx < n; idx++) {
            if (v[idx] - v[prev] >= mid) {
                prev = idx;
                cnt++;
            }
        }

        if (cnt >= c)
            left = mid + 1;
        else
            right = mid - 1;

        if (ans < mid && cnt >= c) ans = mid;
    }

    cout << ans << "\n";

    return 0;
}
