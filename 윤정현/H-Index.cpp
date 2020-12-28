#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>());
    
    for(int i=0; i<citations.size(); i++)
        if(i >= citations[i]) return i;
}
