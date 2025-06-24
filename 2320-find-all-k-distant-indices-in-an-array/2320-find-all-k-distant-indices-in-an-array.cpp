class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> v;
        const int n = nums.size();
        for(int i=0; i<n; i++){
            if(nums[i] ==  key) v.push_back(i);
        }
        set<int> ans;
        for(int ele : v){
            for(int i = ele - k; i <= ele+k; i++){
                if(i>=0 && i<n) ans.insert(i);
            }
        }
        vector<int> res;
        for(int i : ans){
            res.push_back(i);
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