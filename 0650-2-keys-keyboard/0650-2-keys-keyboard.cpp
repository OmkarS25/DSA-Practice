auto init = [](){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    int minSteps(int n) {
        if(n==1) return 0;
        int steps = 0, factor = 2;
        while(n > 1){
            while(n % factor == 0){
                steps += factor;
                n /= factor;
            }
            factor++;
        }
        return steps;
    }
};