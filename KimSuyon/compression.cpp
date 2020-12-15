#include <string>
#include <vector>
using namespace std;

int solution (string s){
    int len = s.size();
    int answer = len;

    for (int i=1; i<= len/2; i++){
        string result = "";
        string unit = s.substr(0, i);

        int cnt = 1;

        for(int j=i; j<=len; j+= i){
            if (unit == s.substr(j,i)){
                cnt += 1;
            }
            else {

                if (cnt == 1){
                    result += unit;
                }
                else{
                result += (to_string(cnt) + unit);
                }

            unit = s.substr(j,i);
            cnt = 1;
        }
    }

    if ((len%i) != 0){
        result += s.substr((len/i)*i);
    }

    if (answer > result.size()) answer = result.size();
    }

return answer;
}