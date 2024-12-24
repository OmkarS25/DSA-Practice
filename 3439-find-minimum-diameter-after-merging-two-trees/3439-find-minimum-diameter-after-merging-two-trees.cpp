class Solution {
    vector<vector<int>> buildAdjList(vector<vector<int>>& edges) {
        vector<vector<int>> adjList(edges.size() + 1);

        for(auto& edge : edges) {
            int parent = edge[0];
            int child  = edge[1];
            adjList[parent].push_back(child);
            adjList[child].push_back(parent);
        } 

        return adjList;
    }

    int getTreeDiameter(vector<vector<int>>& adjList, int root, int parent, int& diameter) {
        int maxHeight1 = 0, maxHeight2 = 0;

        for(int child : adjList[root]) {
            if(child != parent) {
                int childHeight = getTreeDiameter(adjList, child, root, diameter);
                if(childHeight > maxHeight1) {
                    maxHeight2 = maxHeight1;
                    maxHeight1 = childHeight;
                } else if(childHeight > maxHeight2) {
                    maxHeight2 = childHeight;
                }
            }
        }

        diameter = max(diameter, maxHeight1 + maxHeight2);

        int rootHeight = 1 + max(maxHeight1, maxHeight2);
        return rootHeight;
    }

public:
    // O(N+M) & O(N+M)
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<vector<int>> adjList1 = buildAdjList(edges1);
        vector<vector<int>> adjList2 = buildAdjList(edges2);

        int diameter1 = 0; getTreeDiameter(adjList1, 0, -1, diameter1);
        int diameter2 = 0; getTreeDiameter(adjList2, 0, -1, diameter2);
        int diameterCombined = ceil((double)diameter1/2) + ceil((double)diameter2/2) + 1;

        return max({diameter1, diameter2, diameterCombined});
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();