class Solution {
public:
    int MOD = 1e9 + 7;

    int dfs(int node, vector<vector<int>>& adj, vector<bool>& visited){
        visited[node] = true;
        int maxDepth = 0;
        for(auto& nei : adj[node]){ // traversal the node of the parent node
            if(!visited[nei]){ // if not visited the child node
                int depth = 1 + dfs(nei, adj, visited); // what every is full depth + 1
                maxDepth = max(maxDepth, depth); // compare the depth of all nodes and return the maxdepth for this parent node.
            }
        }
        return maxDepth;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        const int n = edges.size() + 1; // Bcz the edges.size == n-1
        vector<vector<int>> adj(n + 1);
        vector<bool> visited(n +1, false);

        for(auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int maxDepth = dfs(1, adj, visited);

        cout<<"Max Depth: "<<maxDepth;

        vector<vector<long long>> dp(maxDepth+1, vector<long long>(2, 0));

        // Base Case
        dp[0][0] = 1; // To make even no. odd we need to start with 1. 
        dp[0][1] = 0; // To make odd no. even we need to start with 0.

        // 1  1  2  4  8
        // 0  1  2  4  8

        for(int i=1; i<=maxDepth; i++){
            dp[i][0] = (dp[i-1][0] + dp[i-1][1]) % MOD; // even sum
            dp[i][1] = (dp[i-1][0] + dp[i-1][1]) % MOD; // odd sum
        }
        
        return dp[maxDepth][1] % MOD;
    }
};