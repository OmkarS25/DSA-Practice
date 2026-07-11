class Solution {
public:
    void dfs(vector<vector<int>> &adj , int u , vector<int>&vis , int &nodes , int &edges){
        vis[u] = true;
        nodes++;
        for(int &v : adj[u]){
            edges++;
            if(!vis[v]) dfs(adj,v,vis,nodes,edges);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        vector<int> vis(n,false);
        int count = 0;
        for(int i=0 ; i<n ; i++){
            if(!vis[i]){
                int nodes = 0;
                int edges = 0;
                dfs(adj,i,vis,nodes,edges);
                if(edges/2 == nodes*(nodes-1)/2) count++;
            }
        }
        return count;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();