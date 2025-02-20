class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        for (int i = 0; i < nums.size(); i++)
            nums[0][i] = nums[i][i] == '1' ? '0' : '1';
        return nums[0];
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();