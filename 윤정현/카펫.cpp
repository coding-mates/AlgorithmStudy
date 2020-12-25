#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    for(int w = 3; w <= brown / 2; w++)
        for(int h = 3; h <= w; h++)
            if((w * h == brown + yellow) && ((w - 2) * (h - 2) == yellow)){
                answer.push_back(w);
                answer.push_back(h);
                return answer;
            }
    
}
