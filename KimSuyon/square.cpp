using namespace std;

long long solution(int w,int h) {
    long long answer = 1;
    int gcd;
    long long sq = (long long)w * (long long)h;
        if (w<h) {
            for (int i = w; i > 0; i--){
                if ((w%i == 0) && (h%i == 0)){
                    gcd = i;
                    break;
                }
            }
        }
        else {
            for (int i = h; i > 0; i--){
                if ((w%i == 0) && (h%i == 0)){
                    gcd = i;
                    break;
                }
            }
        }
    answer = sq - gcd * (w/gcd + h/gcd -1);
    
    return answer;
}