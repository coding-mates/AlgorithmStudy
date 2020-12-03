#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(string str : skill_trees){
        bool flag = false;
        for(int i = 0; i<skill.length()-1; i++){
            int prev = str.find(skill[i]);
            int nxt = str.find(skill[i+1]);
            
            if(prev == -1) prev = str.length();
            if(nxt == -1) nxt = str.length();
            
            if(prev > nxt){
                flag = true;
                break;
            }
        }
        
        if(!flag) answer++;
        
    }
    return answer;
}
