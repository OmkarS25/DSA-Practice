class Solution {
public:
    bool dfs(int node, int destination, unordered_map<int, vector<int>>& adjlist, unordered_set<int>& visited){
        if(node == destination) return true;
        visited.insert(node);
        for(int neighbor : adjlist[node]){
            if(visited.find(neighbor) == visited.end())
                if(dfs(neighbor, destination, adjlist, visited))
                    return true;
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int, vector<int>> adjlist;
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adjlist[u].push_back(v);
            adjlist[v].push_back(u);
        }
        unordered_set<int> visited;
        return dfs(source, destination, adjlist, visited);
    }
};