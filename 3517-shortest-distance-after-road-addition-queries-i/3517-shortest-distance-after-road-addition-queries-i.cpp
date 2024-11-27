class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<pair<int, int>>> neighbors(n);
        for (int i = 0; i < n - 1; i++) {
            neighbors[i].push_back({i + 1, 0});
        }

        int m = queries.size();
        for (int i = 0; i < m; i++) {
            neighbors[queries[i][0]].push_back({queries[i][1], i});
        }

        const int LAST_NODE = n - 1;
        vector<int> minStep(m, -1);         // min steps of each query
        vector<int> visitedIdx(n, INT_MAX); // min queries index of visited node
        queue<pair<int, int>> qu;           // {current node, max queries index of path}
        qu.push({0, 0});
        visitedIdx[0] = 0;
        int step = 0;
        bool finished = false;
        while (!qu.empty() && !finished) {
            int size = qu.size();
            while (size-- > 0) {
                int currNode = qu.front().first;
                int currIdx = qu.front().second;
                qu.pop();

                if (currNode == LAST_NODE) {
                    for (int i = currIdx; i < m && minStep[i] == -1; i++) {
                        minStep[i] = step;
                    }

                    if (currIdx == 0) { // all queries are done
                        finished = true;
                        break;
                    }
                }

                for (const pair<int, int>& p : neighbors[currNode]) {
                    int neighborNode = p.first;
                    int neighborIdx = p.second;
                    int pathMaxIdx = max(currIdx, neighborIdx);

                    if (pathMaxIdx >= visitedIdx[neighborNode]) {
                        continue;
                    }

                    qu.push({neighborNode, pathMaxIdx});
                    visitedIdx[neighborNode] = pathMaxIdx;
                }
            }
            step++;
        }

        return minStep;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();