#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("-ffloat-store")
#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size(), maxWidth = 0;
        stack<int> st;
        for(int i=0; i<n; i++){
            if(st.empty() || nums[st.top()] > nums[i]) st.push(i);
        }
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                maxWidth = max(maxWidth, i - st.top());
                st.pop();
            }
            if(st.empty()) break;
        }
        return maxWidth;
    }
};