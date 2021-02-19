#include <iostream>
#include <queue>
#define MAX 1000000 + 1
using namespace std;

int n;
int idx = 9;
long long num[MAX] = {0};
queue<long long> q;

void check() {
    while (idx <= n) {
        if (q.empty()) return;

        auto cur = q.front();
        q.pop();

        int last = cur % 10;
        for (int i = 0; i < last; i++) {
            q.push(cur * 10 + i);
            num[++idx] = cur * 10 + i;
        }
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= 9; i++) {
        q.push(i);
        num[i] = i;
    }
    check();

    (!num[n] && n) ? cout << "-1\n" : cout << num[n] << "\n";
    return 0;
}
