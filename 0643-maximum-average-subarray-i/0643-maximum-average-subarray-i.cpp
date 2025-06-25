class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double curr = 0, maxi = DBL_MIN;
        for(int i=0; i<k; i++){
            curr += nums[i];
        }
        curr /= k;
        maxi = curr;
        for(int i=k; i<nums.size(); i++){
            curr = curr*k + nums[i] - nums[i-k];
            curr /=k;
            maxi = max(maxi, curr);
        }
        return maxi;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();