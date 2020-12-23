#include <vector>
#include <map>
using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string, int> dress;
    
    for(auto c : clothes) dress[c[1]]++;
    
    for(auto it=dress.begin(); it!=dress.end(); it++)
        answer *= it -> second + 1;
    
    return answer - 1;
}
