#include <iostream>
#include <vector>
using namespace std;

int h, w, n;
int mx = 0;
vector<pair<int, pair<int, int>>> v;
pair<int, pair<int, int>> idx[2];

void sticker() {
    if (idx[0].first == idx[1].first) return;

    if ((idx[0].second.first + idx[1].second.first <= h &&
         idx[0].second.second <= w && idx[1].second.second <= w) ||
        (idx[0].second.second + idx[1].second.second <= w &&
         idx[0].second.first <= h && idx[1].second.first <= h)) {
        int area = idx[0].second.first * idx[0].second.second +
                   idx[1].second.first * idx[1].second.second;
        mx = max(mx, area);
    }
    return;
}

void select(int cnt, int start) {
    if (cnt == 2) {
        sticker();
        return;
    }

    for (int i = start; i < v.size(); i++) {
        idx[cnt] = v[i];
        select(cnt + 1, i + 1);
    }
}

int main() {
    cin >> h >> w >> n;

    int r, c;
    for (int i = 0; i < n; i++) {
        cin >> r >> c;
        v.push_back({i, {r, c}});
        if (r != c) v.push_back({i, {c, r}});
    }

    select(0, 0);
    cout << mx << "\n";

    return 0;
}
