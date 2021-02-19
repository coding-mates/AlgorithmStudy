#include <iostream>
#include <vector>
using namespace std;

long long n, m;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    vector<long long> tree(n);

    long long mn = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        cin >> tree[i];
        mx = max(mx, tree[i]);
    }

    long long ans = 0;
    while (mn <= mx) {
        long long mid = (mn + mx) / 2;
        long long sum = 0;
        for (int i = 0; i < n; i++)
            if (mid < tree[i]) sum += tree[i] - mid;
        if (sum >= m) {
            if (ans < mid) ans = mid;
            mn = mid + 1;
        } else
            mx = mid - 1;
    }

    cout << ans << "\n";

    return 0;
}
