#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end(), greater<int>());
    for(int i=0, j=people.size()-1; i<=j ; i++){
        if(people[i] + people[j] <= limit) j--;
        answer++;
    }
    
    return answer;
}g
