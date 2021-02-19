#include <iostream>
#include <vector>
using namespace std;

string s;
int main() {
    getline(cin, s);
    vector<string> v;

    string tmp = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') {
            v.push_back(tmp);
            tmp = "";
        } else
            tmp += s[i];
    }
    v.push_back(tmp);

    for (int i = 1; i < v.size(); i++) {
        cout << v[0];
        int idx = 0;
        for (int j = v[i].length() - 2; j >= 0; j--) {
            if (('a' <= v[i][j] && v[i][j] <= 'z') ||
                ('A' <= v[i][j] && v[i][j] <= 'Z')) {
                idx = j;
                break;
            }
            if (v[i][j] == ']') {
                cout << "[]";
                j--;
            } else
                cout << v[i][j];
        }
        cout << ' ';
        for (int j = 0; j <= idx; j++) cout << v[i][j];
        cout << ";\n";
    }

    return 0;
}
