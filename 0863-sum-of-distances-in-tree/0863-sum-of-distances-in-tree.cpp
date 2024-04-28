class Solution {
public:
    void dfs(int node, int parent, unordered_map<int, vector<int>>& adjlist, vector<int>& count, vector<int>& sum) {
        for (int neighbor : adjlist[node]) {
            if (neighbor != parent) {
                dfs(neighbor, node, adjlist, count, sum);
                count[node] += count[neighbor];
                sum[node] += sum[neighbor] + count[neighbor];
            }
        }
    }
    
    void dfs2(int node, int parent, unordered_map<int, vector<int>>& adjlist, vector<int>& count, vector<int>& sum, vector<int>& ans, int n) {
        ans[node] = sum[node];
        for (int neighbor : adjlist[node]) {
            if (neighbor != parent) {
                int parentCount = count[node];
                int parentSum = sum[node];
                int childCount = count[neighbor];
                int childSum = sum[neighbor];
                
                count[node] -= count[neighbor];
                sum[node] -= sum[neighbor] + count[neighbor];
                count[neighbor] += count[node];
                sum[neighbor] += sum[node] + count[node];
                
                dfs2(neighbor, node, adjlist, count, sum, ans, n);
                
                count[node] = parentCount;
                sum[node] = parentSum;
                count[neighbor] = childCount;
                sum[neighbor] = childSum;
            }
        }
    }
    
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adjlist;
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
        
        vector<int> count(n, 1);
        vector<int> sum(n, 0);
        vector<int> ans(n, 0);
        
        dfs(0, -1, adjlist, count, sum);
        dfs2(0, -1, adjlist, count, sum, ans, n);
        
        return ans;
    }
};