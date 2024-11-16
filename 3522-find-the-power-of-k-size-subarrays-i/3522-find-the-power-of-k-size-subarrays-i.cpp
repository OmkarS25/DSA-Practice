class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        if (k == 1) {
            return nums;
        }
        
        int n = nums.size();
        vector<int> result;
        deque<int> window;
        
        for (int i = 0; i < n; i++) {
            // Remove elements outside window
            while (!window.empty() && i - window.front() >= k) {
                window.pop_front();
            }
            
            // Check consecutive sequence
            if (window.empty() || nums[i] - nums[i-1] == 1) {
                window.push_back(i);
            } else {
                window.clear();
                window.push_back(i);
            }
            
            // Add result when window size is k
            if (i >= k-1) {
                result.push_back(window.size() == k ? nums[i] : -1);
            }
        }
        
        return result;
    }
};

#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("-ffloat-store")
#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();