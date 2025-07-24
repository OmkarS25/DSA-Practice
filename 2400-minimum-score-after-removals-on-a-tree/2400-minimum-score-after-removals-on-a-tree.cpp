class Solution {
private:
    void dfs(int node,int parent,vector<int>&subXor,vector<int>&inTime,vector<int>&outTime,vector<int>& nums,int &timer,vector<vector<int>>&adj)
    {
       subXor[node]=nums[node];
       inTime[node]=timer;
       timer++;
       for(auto it:adj[node]){
         if(it!=parent){
            dfs(it,node,subXor,inTime,outTime,nums,timer,adj);
            subXor[node]^=subXor[it];
         }
        }
        outTime[node]=timer;
        timer++;
    }
    bool isAncestor(int n1,int n2,vector<int>&inTime,vector<int>&outTime){
        return inTime[n1]<=inTime[n2] and outTime[n1]>=outTime[n2];
    }
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>>adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int ans = INT_MAX;
        vector<int>subXor(n,0);
        vector<int>inTime(n,0);
        vector<int>outTime(n,0);
        int timer = 0;
        dfs(0,-1,subXor,inTime,outTime,nums,timer,adj);
        for(int node1=1;node1<n;node1++){
            for(int node2=node1+1;node2<n;node2++){
                int xor1,xor2,xor3;
                if(isAncestor(node1,node2,inTime,outTime)){         //node1 is ancestor of node2
                    xor1 = subXor[node2];
                    xor2 = subXor[node1]^subXor[node2];
                    xor3 = subXor[0]^xor1^xor2;
                }
                else if(isAncestor(node2,node1,inTime,outTime)){    //node2 is ancestor of node1
                    xor1 = subXor[node1];
                    xor2 = subXor[node2]^subXor[node1];
                    xor3 = subXor[0]^xor1^xor2;
                }
                else{
                    xor1 = subXor[node1];
                    xor2 = subXor[node2];
                    xor3 = subXor[0]^xor1^xor2;
                }
                int mini = min(xor1,min(xor2,xor3));
                int maxi = max(xor1,max(xor2,xor3));
                ans = min(maxi-mini,ans);
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