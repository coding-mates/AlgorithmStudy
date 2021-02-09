#include <iostream>
using namespace std;

int mn = 0;
string s;

bool check(int idx) {
    for (int i = 0; idx + i < s.length() - i - 1; i++)
        if (s[idx + i] != s[s.length() - i - 1]) return false;
    return true;
}

int main() {
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (check(i)) {
            mn = s.length() + i;
            break;
        }
    }

    cout << mn << "\n";
    return 0;
}
