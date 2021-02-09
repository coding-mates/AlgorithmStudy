#include <iostream>
using namespace std;

int main() {
    int n;
    int d[31] = {0};
    d[0] = 1;
    d[2] = 3;

    cin >> n;

    for (int i = 4; i <= n; i++) {
        d[i] = d[i - 2] * 3;
        for (int j = 4; j <= i; j += 2) {
            d[i] += d[i - j] * 2;
        }
    }

    cout << d[n] << "\n";

    return 0;
}
