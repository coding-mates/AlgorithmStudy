#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int n = name.length();
    int dircnt = 0, mvcnt = n-1;
    for(int i=0; i<n; i++){
        int down = name[i] - 'A';
        int up = 'Z' - name[i] + 1;
        
        dircnt += (down < up) ? down : up;
        
        int nxt = i+1;
        while(name[nxt] == 'A' && nxt < n) nxt++;
        
        mvcnt = min(mvcnt, i+n-nxt+min(i,n-nxt));
    }
    
    return dircnt + mvcnt;
}
