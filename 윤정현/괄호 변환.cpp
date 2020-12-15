#include <string>
#include <vector>
#include <stack>

using namespace std;

string answer = "";

bool correct(string s){
    stack<char> st;
    for(auto c : s){
        if(c == '(') st.push('(');
        else{
            if(st.empty()) return false;
            else st.pop();
        }
    }
    
    if(st.empty()) return true;
    else return false;
}

void recursive(string s){
    if(s == ""){
        answer += "";
        return;
    }
    
    int open = 0, close = 0;
    for(int i=0; i<s.length(); i++){
        (s[i] == '(') ? open++ : close++;
        
        if(open == close){
            string u = s.substr(0, i+1);
            string v = s.substr(i+1);
            
            bool flag = correct(u);
            if(flag){
                answer += u;
                recursive(v);
            } else{
                answer += "(";
                recursive(v);
                answer += ")";
                for(int i=1; i<u.length()-1; i++)
                    answer += (u[i] == '(') ? ')' : '(';
            }
            return;
        }
    }
}

string solution(string p) { 
    recursive(p);
    return answer;
}
