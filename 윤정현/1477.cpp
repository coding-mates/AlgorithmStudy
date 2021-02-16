#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int n, m, l;
vector<int> road;

int main() {
    cin >> n >> m >> l;
    road.push_back(0);

    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        road.push_back(tmp);
    }
    road.push_back(l);
    sort(road.begin(), road.end());

    int left = 1, right = l - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        int cnt = 0;
        for (int i = 1; i < road.size(); i++) {
            int dist = road[i] - road[i - 1];
            cnt += (dist / mid);
            if (dist % mid == 0) cnt--;
        }

        if (cnt > m)
            left = mid + 1;
        else
            right = mid - 1;
    }

    cout << left << "\n";

    return 0;
}
