class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        const int m = edges.size();
        vector<vector<pair<int, int>>> adj(n);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, 2 * w});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        vector<int> minCosts(n, 1e9);
        minHeap.push({0, 0});
        minCosts[0] = 0;
        while (!minHeap.empty()) {
            auto [currentCost, currentNode] = minHeap.top();
            minHeap.pop();
            if (currentCost > minCosts[currentNode]) continue;
            for (auto [neighbor, travelCost] : adj[currentNode]) {
                int newCost = currentCost + travelCost;
                if (newCost < minCosts[neighbor]) {
                    minHeap.push({newCost, neighbor});
                    minCosts[neighbor] = newCost;
                }
            }
        }
        if (minCosts[n-1] == 1e9) return -1;
        return minCosts[n-1];
    }
};