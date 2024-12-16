class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        vector<int> ans(nums.size());
        using P = pair<int, int>;
        priority_queue<P, vector<P>, greater<>> minHeap;

        for (int i = 0; i < nums.size(); ++i) {
            minHeap.emplace(nums[i], i);
        }

        while (k-- > 0) {
            P top = minHeap.top();
            int num = top.first;
            int idx = top.second;
            minHeap.pop();
            minHeap.emplace(num * multiplier, idx);
        }

        while (!minHeap.empty()) {
            P top = minHeap.top();
            int num = top.first;
            int idx = top.second;
            minHeap.pop();
            ans[idx] = num;
        }

        return ans;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();