class Solution {
public:
    int passThePillow(int n, int time) {
        int remainder = time % (n-1), cycles = time / (n-1);
        if(cycles&1) return n-remainder;
        return remainder+1;
    }
};