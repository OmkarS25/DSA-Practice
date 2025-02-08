class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ball_count;
        unordered_map<int, int> color_count;
        vector<int> result(queries.size());
        int i = 0;
        
        for (auto& q : queries) {
            int ball = q[0], color = q[1];
            if (ball_count.count(ball)) {
                int prev_color = ball_count[ball];
                if (--color_count[prev_color] == 0) {
                    color_count.erase(prev_color);
                }
            }
            ball_count[ball] = color;
            color_count[color]++;
            result[i++] = color_count.size();
        }
        return result;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();