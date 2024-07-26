class Solution {
public:
    int dijkstra(unordered_map<int, vector<pair<int, int>>>& adjList, int start, int dist, int n) {
        vector<int> minDist(n, INT_MAX);
        minDist[start] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start});
        while (!pq.empty()) {
            auto [currDist, u] = pq.top();
            pq.pop();
            if (currDist > dist) break;
            for (auto [v, weight] : adjList[u]) {
                int newDist = currDist + weight;
                if (newDist < minDist[v]) {
                    minDist[v] = newDist;
                    pq.push({newDist, v});
                }
            }
        }
        return count_if(minDist.begin(), minDist.end(), [&](int d) { return d <= dist; }) - 1;
    }

    int findTheCity(int n, vector<vector<int>>& edges, int dist) {
        unordered_map<int, vector<pair<int, int>>> adjList;
        for (const auto& edge : edges) {
            int u = edge[0], v = edge[1], dis = edge[2];
            adjList[u].emplace_back(v, dis);
            adjList[v].emplace_back(u, dis);
        }
        int minCount = INT_MAX, city = -1;
        for (int i = 0; i < n; ++i) {
            int count = dijkstra(adjList, i, dist, n);
            if (count <= minCount) {
                minCount = count;
                city = i;
            }
        }
        return city;
    }

    // int findTheCity(int n, vector<vector<int>>& edges, int dist) {
    //     vector<vector<int>> distMatrix(n, vector<int>(n, INT_MAX));
    //     // Initialize the distance matrix with the given edges
    //     for (const auto& edge : edges) {
    //         int u = edge[0];
    //         int v = edge[1];
    //         int d = edge[2];
    //         distMatrix[u][v] = d;
    //         distMatrix[v][u] = d;
    //     }
    //     // Distance from a node to itself is 0
    //     for (int i = 0; i < n; ++i) {
    //         distMatrix[i][i] = 0;
    //     }
    //     // Floyd-Warshall algorithm to compute shortest paths between all pairs of nodes
    //     for (int k = 0; k < n; ++k) {
    //         for (int i = 0; i < n; ++i) {
    //             for (int j = 0; j < n; ++j) {
    //                 if (distMatrix[i][k] != INT_MAX && distMatrix[k][j] != INT_MAX) {
    //                     distMatrix[i][j] = min(distMatrix[i][j], distMatrix[i][k] + distMatrix[k][j]);
    //                 }
    //             }
    //         }
    //     }
    //     int minCount = INT_MAX, city = -1;
    //     // Count the number of reachable cities for each city
    //     for (int i = 0; i < n; ++i) {
    //         int count = 0;
    //         for (int j = 0; j < n; ++j) {
    //             if (distMatrix[i][j] <= dist) count++;
    //         }
    //         // We subtract 1 because the city itself is included in the count
    //         if (count - 1 < minCount || (count - 1 == minCount && i > city)) {
    //             minCount = count - 1;
    //             city = i;
    //         }
    //     }
    //     return city;
    // }
};
