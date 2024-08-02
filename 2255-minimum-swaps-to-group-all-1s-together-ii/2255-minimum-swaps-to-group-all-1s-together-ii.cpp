auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    static int minSwaps(vector<int>& nums) {
        const int n=nums.size(), n1=count(nums.begin(), nums.end(), 1), n0=n-n1;
        int mswap, cnt1=mswap=count(nums.begin(), nums.begin()+n0, 1);
        for(int l=0, r=n0; r < n+n0; r++, l++){
            cnt1 += nums[r%n] - nums[l];
            mswap = min(mswap, cnt1); //change all to 0 for nums[l+1..r]
        }
        return mswap;
    }
};