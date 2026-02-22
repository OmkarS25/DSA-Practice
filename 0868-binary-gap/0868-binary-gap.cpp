class Solution {
public:
    int binaryGap(int n) {
        int prev = -1; // to store the prev index of 1 in binary representation
        int mexi = -1; //store longest length
        int idx = 0;
        while(n) {
            if(n&1) { // means 1 found
                if(prev == -1) prev = idx; // if encountered for first time
                else { // check for longest and make current as prev
                    mexi = max(mexi,idx-prev);
                    prev = idx;
                }
            }
            n = n>>1;
            idx++;
        }
        return mexi == -1 ? 0 : mexi;
        
    }
};