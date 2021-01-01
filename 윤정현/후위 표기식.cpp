#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<char> sign;
    string s;

    cin >> s;
    for (char c : s) {
        if (c == '*' || c == '/') {
            if (!sign.empty() && (sign.top() == '*' || sign.top() == '/')) {
                cout << sign.top();
                sign.pop();
            }
            sign.push(c);
        } else if (c == '+' || c == '-') {
            if (!sign.empty()) {
                while (!sign.empty()) {
                    if (sign.top() == '(') break;
                    cout << sign.top();
                    sign.pop();
                }
            }
            sign.push(c);
        } else if (c == '(') {
            sign.push(c);
        } else if (c == ')') {
            while (sign.top() != '(') {
                cout << sign.top();
                sign.pop();
            }
            sign.pop();
        } else {
            cout << c;
        }
    }

    while (!sign.empty()) {
        cout << sign.top();
        sign.pop();
    }

    return 0;
}
