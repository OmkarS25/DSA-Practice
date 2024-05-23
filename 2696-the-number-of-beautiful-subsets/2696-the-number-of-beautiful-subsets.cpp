class Solution {
public:
    int ans;
    unordered_map<int, int> rec;
    int beautifulSubsets(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        ans = 0;
        vector<int> tmp;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            rec[nums[i]]++;
            recursion(i+1, n, tmp, nums, k);
            rec[nums[i]]--;
        }
        return ans;
    }
    void recursion(int pos, int n, vector<int> &tmp, vector<int>& nums, int k) {
        if (pos == n) {
            ans++;
            return;
        }
        if (rec[nums[pos] - k] == 0) {
            rec[nums[pos]]++;
            recursion(pos + 1, n, tmp, nums, k);
            rec[nums[pos]]--;
        }   
        recursion(pos + 1, n, tmp, nums, k);   
    }
};

// Testcases
// nums = [16,1,18,12,11,5,17,15,14,8,20,2,4,6,19,7,13,10,9,3]
// k = 1
// nums = [18, 12, 10, 5, 6, 2, 18, 3]
// k = 8
    