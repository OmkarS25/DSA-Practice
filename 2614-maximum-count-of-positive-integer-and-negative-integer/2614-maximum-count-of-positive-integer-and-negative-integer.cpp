class Solution {
public:
    int maximumCount(vector<int>& nums) {
        const int n = nums.size();
        int st = 0, end = n - 1, pos, neg, mid;

        while(st <= end){
            mid = st + (end - st) / 2;
            if(nums[mid] > 0) end = mid - 1;
            else st = mid + 1;
        }

        pos = n - st;
        st = 0;
        end = n - 1;

        while(st <= end){
            mid = st + (end - st) / 2;
            if(nums[mid] < 0) st = mid + 1;
            else end = mid - 1;
        }

        neg = end + 1;

        return max(pos, neg);
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();