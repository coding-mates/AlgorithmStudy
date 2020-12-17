#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int num_size = number.size() - k;
    int start = 0;
    for (int i = 0; i < num_size; i++){
        char max = number[start];
        int maxIdx = start;
        for (int j = start; j <= k+i; j++){
            if (max < number[j]) {
                max = number[j];
                maxIdx = j;
            }
        }
        start = maxIdx + 1;
        answer += max;
    }
    return answer;
}