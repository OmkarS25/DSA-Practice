class Solution {
        inline static const unordered_map<int, bool> isprime = {{2,1},{3,1},{5,1},{7,1},{11,1},{13,1},{17,1},{19,1},{23,1},{29,1},{31,1}};
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        for(int i=left; i<=right; i++){
            int bits = __builtin_popcount(i);
            if (isprime.find(bits) != isprime.end()) ans++;
        }
        return ans;
    }
};