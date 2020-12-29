#include <iostream>
#include <vector>
#define MAX 1000 + 5
using namespace std;

int solution(vector<vector<int>> board){
    int r = board.size();
    int c = board[0].size();
    
    for(int i=1; i<r; i++)
        for(int j=1; j<c; j++)
            if(board[i][j])
                board[i][j] += min(board[i-1][j], min(board[i][j-1], board[i-1][j-1]));
            
    int mx = 0;
    for(int i=0; i<r; i++)
        for(int j=0; j<c; j++)
            mx = max(mx, board[i][j]);
            
    return mx * mx;
}
