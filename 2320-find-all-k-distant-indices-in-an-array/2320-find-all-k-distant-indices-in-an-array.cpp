class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        const int n = nums.size();
        int start = 0;
        for(int i=0;i<n;i++){
            if (nums[i] == key){
                int left = max(0,i-k), right = min(n-1,i+k);
                while(start<=right){
                    if (start>=left) ans.push_back(start);
                    start++;
                }
            }
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