#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    int day = 0;
    int max_day = 0;
    for (int i = 0; i < progresses.size(); i++) {
        
        day = (100 - progresses[i]) / speeds[i];
        
        if (max_day < day) {
            answer.push_back(1);
            max_day = day;
        }
        else
            answer.back()++;
    }
    return answer;
}