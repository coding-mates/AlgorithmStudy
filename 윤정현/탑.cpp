#include <iostream>
#include <stack>
#include <vector>
#define height first
#define index second
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> answer;
    stack<pair<int, int>> tower;
    int x;
    for (int idx = 1; idx <= n; idx++) {
        cin >> x;
        while (!tower.empty() && tower.top().height <= x) tower.pop();
        (tower.empty()) ? answer.push_back(0)
                        : answer.push_back(tower.top().index);
        tower.push({x, idx});
    }

    for (int idx : answer) cout << idx << ' ';
    return 0;
}
