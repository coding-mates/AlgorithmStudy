#include <string>
#include <vector>

using namespace std;

string solution(int n) {
    string answer = "";
    char alpha[3] = {'1', '2', '4'};

    while (n >= 1) {
        answer = alpha[(n - 1) % 3] + answer;
        n = (n - 1) / 3;
    }

    return answer;
}