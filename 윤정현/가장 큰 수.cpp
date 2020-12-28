#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(int a, int b){
    string x = to_string(a);
    string y = to_string(b);
    
    return x + y > y + x;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    sort(numbers.begin(), numbers.end(), compare);
    
    for(int number : numbers)
        answer += to_string(number);
    
    if(answer[0] == '0'){
        int idx = -1;
        for(int i=0; i<answer.length(); i++)
            if(answer[i] != '0'){
                idx = i;
                break;
            }
        answer = (idx == -1) ? "0" : answer.substr(idx);
    }
    
    return answer;
}
