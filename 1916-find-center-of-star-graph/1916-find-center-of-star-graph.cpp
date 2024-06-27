class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adjlist;
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjlist[u].push_back(v);
            if(adjlist[u].size() > 1) return u;
            adjlist[v].push_back(u);
            if(adjlist[v].size() > 1) return v;
        }
        return 0;
    }
};