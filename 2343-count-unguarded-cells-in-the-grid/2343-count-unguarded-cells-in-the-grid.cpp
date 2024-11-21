class Solution {
public:

    int countUnguarded(int n, int m, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int vis[n][m]; 
        memset(vis, 0, sizeof(vis)); 
        for (auto &it: guards) {
            vis[it[0]][it[1]] = 1; 
        }
        for (auto &it: walls) {
            vis[it[0]][it[1]] = 2; 
        }
  
        int f = 0; 
        // Left to right and right to left
        for (int i = 0; i < n; i++) {
            f = 0; 
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 1) {
                    f = 3; 
                } else if (vis[i][j] == 2) {
                    f = 0; 
                } else {
                    if (f)
                        vis[i][j] = f; 
                }
            }
            f = 0; 
            for (int j = m - 1; j >= 0; j--) {
                if (vis[i][j] == 1) {
                    f = 3; 
                } else if (vis[i][j] == 2) {
                    f = 0;
                } else {
                    if (f)
                        vis[i][j] = f; 
                }
            }
        }

        f = 0; 
        // up to down and down to up
        for (int j = 0; j < m; j++) {
            f = 0; 
            for (int i = 0; i < n; i++) {
                if (vis[i][j] == 1) {
                    f = 3; 
                } else if (vis[i][j] == 2) {
                    f = 0; 
                } else {
                    if (f)
                        vis[i][j] = f; 
                }
            }
            f = 0; 
            for (int i = n - 1; i >= 0; i--) {
                if (vis[i][j] == 1) {
                    f = 3; 
                } else if (vis[i][j] == 2) {
                    f = 0; 
                } else {
                    if (f)
                        vis[i][j] = f; 
                }
            }
        }
        int ans = 0; 
        // Counting the unvisited cells
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j]) {
                    ans++; 
                }
            }
        }
        return ans; 
    }
};

#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("-ffloat-store")
#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();