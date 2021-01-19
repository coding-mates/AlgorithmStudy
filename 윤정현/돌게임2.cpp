#include <iostream>
#define MAX 1000 + 1
using namespace std;

bool d[MAX];

int main() {
    int n;
    cin >> n;

    d[1] = 0;
    d[2] = 1;
    d[3] = 0;
    for (int i = 4; i <= n; i++) {
        if (!d[i - 1] | !d[i - 3])
            d[i] = 1;
        else
            d[i] = 0;
    }

    (d[n]) ? cout << "SK\n" : cout << "CY\n";

    return 0;
}
