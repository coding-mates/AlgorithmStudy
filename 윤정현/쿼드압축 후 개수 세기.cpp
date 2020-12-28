#include <string>
#include <vector>
using namespace std;

vector<vector<int>> board;
vector<int> answer(2, 0);

void map(int x, int y, int w){
    if(w == 1){
        answer[board[x][y]]++;
        return;
    }
    
    bool flag = false;
    int n = board[x][y];
    for(int i=x; i<x+w; i++){
        for(int j=y; j<y+w; j++){
            if(board[i][j] != n){
                flag = true;
                break;
            }
        }
        if(flag) break;
    }
    
    if(flag){
        map(x, y, w/2);
        map(x+w/2, y, w/2);
        map(x, y+w/2, w/2);
        map(x+w/2, y+w/2, w/2);
    } else{
        answer[n]++;
    }
    return;
}

vector<int> solution(vector<vector<int>> arr) {
    board = arr;
    map(0, 0, arr.size());
    return answer;
}
