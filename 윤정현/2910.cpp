#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int n, c;
map<int, pair<int, int>> m;

bool compare(pair<int, pair<int, int>>& a, pair<int, pair<int, int>>& b) {
    if (a.second.first == b.second.first)
        return a.second.second < b.second.second;
    return a.second.first > b.second.first;
}

int main() {
    cin >> n >> c;

    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (m.find(x) == m.end())
            m[x] = {1, i};
        else
            m[x].first++;
    }

    vector<pair<int, pair<int, int>>> v(m.begin(), m.end());
    sort(v.begin(), v.end(), compare);

    for (auto n : v)
        while (n.second.first--) cout << n.first << ' ';

    return 0;
}
