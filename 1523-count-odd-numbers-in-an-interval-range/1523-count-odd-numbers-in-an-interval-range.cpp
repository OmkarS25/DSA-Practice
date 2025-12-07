class Solution {
public:
    int countOdds(int low, int high) {
        return (low&1) ? (high-low+2)/2 : (high-low+1)/2;
        
        // if(low==high) return low&1;
        // if(low%2 == 0) low++;
        // int diff = high - low + 1;
        // return (diff&1) ? (diff+1)/2 : diff/2; 
    }
};