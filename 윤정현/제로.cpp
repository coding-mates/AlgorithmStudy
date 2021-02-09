#include <iostream>
#include <stack>
using namespace std;

int main() {
    int k;
    cin >> k;

    int sum = 0, n;
    stack<int> s;
    while (k--) {
        cin >> n;
        if (n) {
            s.push(n);
            sum += n;
        } else {
            sum -= s.top();
            s.pop();
        }
    }

    cout << sum << "\n";
    return 0;
}
