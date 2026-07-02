class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> res;
        int cnt = 0, n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] < pivot) res.push_back(nums[i]);
            if (nums[i] == pivot) cnt++;
        }

        for (int i = 0; i < cnt; i++) {
            res.push_back(pivot);
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] > pivot) res.push_back(nums[i]);
        }

        return res;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();