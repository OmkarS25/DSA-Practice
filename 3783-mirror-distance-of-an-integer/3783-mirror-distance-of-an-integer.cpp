class Solution {
public:
    int reverseNum(int x){
        int rev = 0;
        while(x){
            rev = rev*10 + x%10;
            x/=10;
        }
        return rev;
    }
    int mirrorDistance(int n) {
        return abs(n - reverseNum(n));
    }
};