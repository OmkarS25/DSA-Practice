static const int _=[]()noexcept{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        stack<int> st;
        st.push(0);
        for(int i = 1; i < n; i++){
            if(nums[st.top()] > nums[i]) st.push(i);
        }
        for(int i = n-1; i >= 0; i--){
            while(!st.empty() and nums[st.top()] <= nums[i]){
                ans = max(ans, i - st.top());
                st.pop();
            }
            if(st.empty()) break;
        }
        return ans;
    }
};