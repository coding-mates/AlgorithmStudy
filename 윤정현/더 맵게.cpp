#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<int> scoville, int K) {
    priority_queue<int, vector<int>, greater<int>> mix;
    for(int s : scoville) mix.push(s);
    
    int answer = 0;
    int mixedFood = 0;
    while(mix.size() != 1){
        if(mix.top() >= K) break;
        mixedFood = mix.top();
        mix.pop();
        mixedFood += mix.top() * 2;
        mix.pop();
        mix.push(mixedFood);
        answer++;
    }
    
    if(mix.size() == 1 && mix.top() < K) return -1;
    else return answer;
}
