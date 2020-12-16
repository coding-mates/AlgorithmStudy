#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <set>
#define MAX 10000000
using namespace std;

int len = 0;
string s;
bool sosu[MAX];
bool isused[8];
set<int> num;

void mksosu(string n){
    if(!sosu[stoi(n)]) num.insert(stoi(n));
    if(n.length() == len) return;
    
    for(int i=0; i<len; i++){
        if(!isused[i]){
            isused[i] = 1;
            mksosu(n + s[i]);
            isused[i] = 0;
        }
    }
}

void check(){
    sosu[0] = 1;
    sosu[1] = 1;
    
    for(int i=2; i<=sqrt(MAX); i++){
        if(sosu[i]) continue;
        for(int j=i*2; j<MAX; j+=i) sosu[j] = 1;
    }
    
    return;
}

int solution(string numbers) {
    check();
    
    len = numbers.length();
    s = numbers;
    
    for(int i=0; i<len; i++){
        string tmp = "";
        if(!isused[i]){
            isused[i] = 1;
            mksosu(tmp + s[i]);
            isused[i] = 0;
        }
    }
    
    return num.size();
}
