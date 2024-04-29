class Solution {
public:
    int minBitFlips(int start, int goal) {
        int res =0, maxi = max(start,goal);
        while(maxi){
            if((start&1) != (goal&1)) res++;
            start >>=1;
            goal >>=1;
            maxi >>=1;
        }
        return res;
    }
};