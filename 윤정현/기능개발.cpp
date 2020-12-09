#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<int> date;
    for(int i=0; i<progresses.size(); i++){
        int n = (100-progresses[i]) / speeds[i];
        if((100-progresses[i]) % speeds[i]) n++;
        date.push(n);
    }
    
    while(!date.empty()){
        int first = date.front();
        date.pop();
        
        int cnt = 1;
        while(!date.empty() && date.front() <= first){
            cnt++;
            date.pop();
        }
        answer.push_back(cnt);
    }
    
    return answer;
}
