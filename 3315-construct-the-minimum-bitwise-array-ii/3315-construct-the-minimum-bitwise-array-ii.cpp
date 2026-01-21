class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        ans.reserve(nums.size());
        for (int n : nums)
            ans.push_back((n % 2 == 0) ? -1 : (n - ((n+1 & -(n+1)) >> 1)));
        return ans;
    }
};



// else {
//     int t = n + 1;
//     int lowbit = t & -t;
//     ans.push_back(n - (lowbit >> 1));
// }