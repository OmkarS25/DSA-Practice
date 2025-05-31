#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        
        // to get (row, col) in the board given the number of position
        auto getPos = [&](int num) {
            int r = n - 1 - (num - 1) / n;
            int c = (num - 1) % n;
            if ((n - r) % 2 == 0) c = n - 1 - c;
            return make_pair(r, c);
        };
        //BFS 
        vector<bool> visited(n * n + 1, false); // +1 since 1 indexed
        queue<pair<int, int>> q; // (square, moves)
        q.push({1, 0}); 
        visited[1] = true;

        while (!q.empty()) {
            auto [curr, moves] = q.front(); q.pop();
            for (int dice = 1; dice <= 6; dice++) {
                int next = curr + dice;
                if (next > n * n) continue;

                auto [r, c] = getPos(next);
                if (board[r][c] != -1) next = board[r][c];
                // merge the destination and the prev next into
                // one single vertex and we represent it with
                // destination since we finally end up there
                // notice that we do not go across multiple snakes or 
                // ladders,since we update next only once 

                if (next == n * n) return moves + 1;
                if (!visited[next]) {
                    visited[next] = true;
                    q.push({next, moves + 1});
                }
            }
        }
        return -1;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();