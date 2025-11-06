

class Solution {
    vector<int> bfs(int start, const vector<vector<int>>& adj,
                    vector<char>& visited, map<int, int>& pos, int _pos) {
        vector<int> all;
        queue<int> q;
        q.push(start);
        visited[start] = 1;
        pos[start] = _pos;
        all.push_back(start);
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (!visited[v]) {
                    visited[v] = 1;
                    pos[v] = _pos;
                    q.push(v);
                    all.push_back(v);
                }
            }
        }
        sort(all.begin(), all.end());
        return all;
    }

public:
    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        vector<int> res;
        vector<vector<int>> adj(c + 1);
        vector<char> visited(c + 1, 0);
        map<int, int> pos;
        vector<int> on(c + 1, 1);
        for (auto& e : connections) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<int>> components;
        for (int i = 1; i <= c; ++i) {
            if (!visited[i]) {
                int id = components.size();
                components.push_back(bfs(i, adj, visited, pos, id));
            }
        }
        for (auto& q : queries) {
            int x = q[0], y = q[1];
            if (x == 1) {
                if (on[y]) res.push_back(y);
                else {
                    if (components[pos[y]].empty()) res.push_back(-1);
                    else res.push_back(components[pos[y]][0]);
                }
            } 
            else {
                on[y] = 0;
                if (pos.find(y) != pos.end()) {
                    vector<int>& comp = components[pos[y]];
                    auto it = lower_bound(comp.begin(), comp.end(), y); // binary search
                    if (it != comp.end() && *it == y) comp.erase(it);
                }
            }
        }
        return res;
    }
};
