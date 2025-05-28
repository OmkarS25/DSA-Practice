class Solution {
public:
    int bfsCount(int node, vector<vector<int>> adj, int size, int k){
        queue<int> q;
        vector<int> vis(size, 0);
        q.push(node);
        vis[node] = 1;
        int dis = 0, cnt = 0;
        while(!q.empty() && dis <= k){
            int sz = q.size();
            while(sz-- > 0){
                int qnode = q.front();
                q.pop();
                cnt++;
                for(auto it: adj[qnode]){
                    if(!vis[it]){
                        vis[it] = true;
                        q.push(it);
                    }
                }
            }
            dis++;
        }
        return cnt;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size(), m = edges2.size();
        vector<vector<int>> adj1(n+1), adj2(m+1);
        for(int i = 0; i < n; i++){
            adj1[edges1[i][0]].push_back(edges1[i][1]);
            adj1[edges1[i][1]].push_back(edges1[i][0]);
        } 
        
        for(int i = 0; i < m; i++){
            adj2[edges2[i][0]].push_back(edges2[i][1]);
            adj2[edges2[i][1]].push_back(edges2[i][0]);
        } 

        vector<int> cnt(n+1, 0);
        for(int i = 0; i <= n; i++){
            cnt[i] = bfsCount(i, adj1, n+1, k);
        }

        int powerNodeCnt = 0;
        for(int i = 0; i <= m; i++){
            int currCnt = bfsCount(i, adj2, m+1, k-1);
            if(currCnt > powerNodeCnt) powerNodeCnt = currCnt;
        }

        vector<int> totalTargets(n+1, 0);
        for(int i = 0; i <= n; i++){
            totalTargets[i] = cnt[i] + powerNodeCnt;
        }
        return totalTargets;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();