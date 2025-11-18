class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        const int n = bits.size();
        if(n==1) return true;
        if(bits[n-2] == 0) return true; // Second last is 0
        // Second last is 1
        int count = 0;
        for(int i = n - 2; i >= 0 && bits[i] == 1; --i) {
            count++;
        }
        return count % 2 == 0;
    }
};