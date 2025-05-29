class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,
                               vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;      // nodes in tree1
        int m = edges2.size() + 1;      // nodes in tree2

        // 1) Build adjacency lists for both trees
        vector<vector<int>> adj1(n), adj2(m);
        for (auto it : edges1) {
            adj1[it[0]].push_back(it[1]);
            adj1[it[1]].push_back(it[0]);
        }
        for (auto it : edges2) {
            adj2[it[0]].push_back(it[1]);
            adj2[it[1]].push_back(it[0]);
        }

        // 2) BFS on Tree 1, count odd vs. even, mark odd‐level nodes
        vector<int> ans(n), vis(n);
        int odd1 = 0, even1 = 1;      // root (0) is “even” level
        queue<pair<int,int>> q;
        vis[0] = 1;
        q.push({0, 0});               // {node, level}

        while (!q.empty()) {
            int u=q.front().first;
            int lvl=q.front().second;
             q.pop();
            for (int v : adj1[u]){
                 if (!vis[v]) {
                // next level = lvl+1 → check its parity
                    if ((lvl+1) & 1) {
                    odd1++;
                    ans[v] = 1;        // mark v as “reached at odd level”
                    } else {
                    even1++;
                    // ans[v] stays 0: means “even‐level” for now
                    }
                vis[v] = 1;
                q.push({v, lvl+1});
            }}
        }

        // 3) For each node i in tree1:
        //    if ans[i]==1 → it was odd, so set ans[i]=odd1; else ans[i]=even1
        for (int i = 0; i < n; i++) {
            ans[i] = (ans[i] ? odd1 : even1);
        }

        // 4) BFS on Tree 2, count odd vs. even (no per-node marking needed)
        vector<int> vis2(m);
        int odd2 = 0, even2 = 1;
        vis2[0] = 1;
        q.push({0, 0});
        while (!q.empty()) {
            auto [u, lvl] = q.front(); q.pop();
            for (int v : adj2[u]) if (!vis2[v]) {
                if ((lvl+1) & 1) odd2++;
                else            even2++;
                vis2[v] = 1;
                q.push({v, lvl+1});
            }
        }

        // 5) We can choose the larger of the two parity-groups in Tree 2
        int best2 = max(odd2, even2);

        // 6) Add that to each ans[i] and return
        for (int &x : ans) x += best2;
        return ans;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();