#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;

	queue<pair<int, int>> q;
	priority_queue<int> pq;
	for (int i = 0; i < priorities.size(); i++) {
		q.push(make_pair(i, priorities[i]));
		pq.push(priorities[i]);
	}

	while (!q.empty()) {
		if (q.front().second == pq.top()) {
			if (q.front().first == location) {
				return answer + 1;
			}
			else {
				answer++;
				q.pop();
				pq.pop();
			}
		}
		else {
			q.push(q.front());
			q.pop();
		}
	}
	return answer;
}

