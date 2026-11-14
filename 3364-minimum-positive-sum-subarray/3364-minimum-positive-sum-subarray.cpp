class Solution {
public:
    void fun(vector<vector<int>>& ans, vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                vector<int> temp;
                for (int k = i; k <= j; k++) {
                    temp.push_back(nums[k]);
                }
                ans.push_back(temp);
            }
        }
    }

    void fun1(vector<vector<int>>& ans, int l, int r) {
        vector<vector<int>> temp;
        for (int i = 0; i < ans.size(); i++) {
            int len = ans[i].size();

            if (len >= l && len <= r) {
                temp.push_back(ans[i]);
            }
        }
        ans = temp;
    }

    int sum(vector<int> temp) {
        int n = temp.size();
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += temp[i];
        }
        return sum;
    }

    void fun2(vector<vector<int>>& ans) {
        vector<vector<int>> temp;
        for (int i = 0; i < ans.size(); i++) {
            if (sum(ans[i]) > 0) {
                temp.push_back(ans[i]);
            }
        }
        ans = temp;
    }

    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        vector<vector<int>> ans;
        fun(ans, nums);
        fun1(ans, l, r);
        fun2(ans);
        if (ans.size() == 0) return -1;
        int mini = INT_MAX;
        for (int i = 0; i < ans.size(); i++) {
            mini = min(mini, sum(ans[i]));
        }
        return mini;
    }
};