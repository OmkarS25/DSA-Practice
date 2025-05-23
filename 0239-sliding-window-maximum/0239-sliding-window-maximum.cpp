class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k){
        vector<int> ans;
        deque<int> dq;
        for (int i = 0; i < k; i++){
            while (!dq.empty() && nums[i] > nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        
        for (int i = k; i < nums.size(); i++){
            ans.push_back(nums[dq.front()]);
            if (i - dq.front() >= k) dq.pop_front();
            while (!dq.empty() && nums[i] > nums[dq.back()])
                dq.pop_back();
            dq.push_back(i);
        }
        ans.push_back(nums[dq.front()]);
        return ans;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();