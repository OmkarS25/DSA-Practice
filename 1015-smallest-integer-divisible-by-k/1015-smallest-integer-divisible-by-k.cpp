class Solution {
public:
    int smallestRepunitDivByK(int k) {
        int rem = 0; // Remainder after forming repunit numbers step-by-step
        // Try repunits of increasing length: 1, 11, 111, ...
        // Bound = 2*k ensures we detect cycles and avoid infinite loops
        for (int length = 1; length <= k * 2; length++) {
            rem = (rem * 10 + 1) % k; // Add a new digit '1': (previous_number * 10 + 1) % k
            if(rem == 0) return length; // If remainder becomes 0, this repunit is divisible by k
        }
        return -1; // If no repunit divides k
    }
};

// class Solution {
// public:
//     int smallestRepunitDivByK(int k) {
//         unsigned long long int n = 11111111111111111111;
//         int count = 20, ans = 0;
//         while(n){
//             if(n%k == 0) ans = count;
//             n /= 10;
//             count--;
//         }
//         return ans ? ans : -1;
//     }
// };