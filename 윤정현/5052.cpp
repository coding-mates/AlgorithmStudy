#include <algorithm>
#include <iostream>
#define MAX 10000 + 1
using namespace std;

int t, n;
string phone[MAX];

int main() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> phone[i];
        sort(phone, phone + n);

        bool flag = true;
        for (int i = 0; i < n - 1; i++) {
            string tmp = phone[i + 1].substr(0, phone[i].length());
            if (phone[i] == tmp) {
                flag = false;
                break;
            }
        }
        (flag) ? cout << "YES\n" : cout << "NO\n";
    }
    return 0;
}
