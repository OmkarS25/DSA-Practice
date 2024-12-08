class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events){
        sort(events.begin(),events.end());
        vector<vector<int>> dp(events.size(),vector<int>(2,-1));
        return fun(events,dp,0,0);
    }

    int fun(vector<vector<int>>& v, vector<vector<int>>& dp, int i, int t){
        if(t==2 || i>=v.size()) return 0;
        if(dp[i][t]!=-1) return dp[i][t];
        int res=fun(v,dp,i+1,t);
        int next=search(v,v[i][1],i);
        res=max(res,v[i][2]+fun(v,dp,next,t+1));
        
        return dp[i][t]=res;
    }

    int search(vector<vector<int>>& v, int val, int i){
        int l=i+1, r=v.size()-1, res=v.size();
        while(l<=r){
            int mid=(l+r)/2;
            if(v[mid][0]>val){
                res=mid;
                r=mid-1;
            }
            else l=mid+1;
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