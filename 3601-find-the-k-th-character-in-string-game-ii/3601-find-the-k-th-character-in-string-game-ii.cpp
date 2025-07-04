class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        char ch = 'a';
        
        // Simulate recursion from bottom to top
        for (int i = 62; i >= 0; --i) {
            long long half = 1LL << i;
            if (k > half) {
                k -= half;
                if (operations[i]) ch = (ch == 'z') ? 'a' : ch + 1;
            }
        }

        return ch;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();