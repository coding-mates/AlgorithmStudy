#include <iostream>
#define MAX 100000 + 1
using namespace std;

long long n;
long long road[MAX], price[MAX];

int main() {
    cin >> n;
    for (int i = 0; i < n - 1; i++) cin >> road[i];
    for (int i = 0; i < n; i++) cin >> price[i];

    long long sum = road[0] * price[0];
    long long mn_price = price[0];

    for (int i = 1; i < n - 1; i++) {
        if (mn_price > price[i]) mn_price = price[i];
        sum += mn_price * road[i];
    }

    cout << sum << "\n";
    return 0;
}
