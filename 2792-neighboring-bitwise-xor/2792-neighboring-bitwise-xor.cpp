class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int totalXOR = 0;
        for (const int num : derived) {
            totalXOR ^= num;
        }
        return totalXOR == 0;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();