class Solution {
public:
    string prevHash = "";
    string currHash = "-1,";
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys,
        vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {

        queue<int> q;
        queue<int> closed;
        unordered_map<int, bool> vis;
        unordered_set<int> st;
        int res = 0;

        for (int i : initialBoxes) {
            q.push(i);
        }

        while (prevHash != currHash) {
            while (!q.empty()) {
                int node = q.front();
                q.pop();

                if (status[node] == 1 || st.find(node) != st.end()) {
                    vis[node] = true;
                    res += candies[node];
                    vector<int> keysArr = keys[node];
                    for (int k : keysArr) {
                        st.insert(k);
                    }

                    for (int n : containedBoxes[node]) {
                        if (!vis[n]) {
                            if (status[n] == 1) {
                                q.push(n);
                            } else {
                                if (st.find(n) != st.end()) {
                                    q.push(n);
                                } else {
                                    closed.push(n);
                                }
                            }
                        }
                    }
                } else {
                    closed.push(node);
                }
            }
            set<int> temp;
            while (!closed.empty()) {
                int top = closed.front();
                closed.pop();
                q.push(top);
                temp.insert(top);
            }
            string s = "-1,";
            for (int t : temp) {
                s += to_string(t);
                s += ",";
            }

            prevHash = currHash;
            currHash = s;
        }

        return res;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();