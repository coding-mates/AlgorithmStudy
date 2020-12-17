#include <string>
#include <vector>
using namespace std;

string solution(string number, int k) {
    for(k; k>0; k--){
        for(int i=0; i<number.length(); i++){
            if(number[i] < number[i+1]){
                number = number.substr(0,i) + number.substr(i+1);
                break;
            } else if(i == number.length() - 1){
                number = number.substr(0,i);
                break;
            }
        }
    }
    return number;
}
