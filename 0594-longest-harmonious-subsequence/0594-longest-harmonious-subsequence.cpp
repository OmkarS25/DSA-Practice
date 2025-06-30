class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> fq;
        for(int a : nums){
            fq[a]++;
        }
        int ans = 0;
        for(int a : nums){
            if(fq.find(a+1) != fq.end()){
                ans = max(ans, fq[a]+fq[a+1]);
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