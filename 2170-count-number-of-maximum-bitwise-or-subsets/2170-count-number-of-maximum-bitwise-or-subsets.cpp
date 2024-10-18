class Solution{
public:
    void backtrack(const vector<int> &nums, int index, int currentOR, int maxOR, int &count){
        if (currentOR == maxOR) count++;
        for (int i = index; i < nums.size(); ++i){
            backtrack(nums, i + 1, currentOR | nums[i], maxOR, count);
        }
    }

    int countMaxOrSubsets(vector<int> &nums){
        int maxOR = 0, count = 0;
        for (int num : nums){
            maxOR |= num;
        }
        backtrack(nums, 0, 0, maxOR, count);
        return count;
    }
};

#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("-ffloat-store")
#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();