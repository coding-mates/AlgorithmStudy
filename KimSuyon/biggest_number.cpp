#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp (string a, string b){
    if (a+b > b+a) return true;
    return false;
}

string solution(vector<int> numbers) {
    string answer = "";
    
    vector <string> sol;
    for (int i = 0; i < numbers.size(); i++){
        sol.push_back(to_string(numbers[i]));
    }
    sort(sol.begin(), sol.end(), cmp);
    
    if (sol[0] == "0"){
        return "0";
    }
    for (int i = 0; i < sol.size(); i++){
        answer += sol[i];
    }
    return answer;
}