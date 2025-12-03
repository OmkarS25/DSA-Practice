class Solution {
public:
    int countTrapezoids(vector<vector<int>>& pts) {
        unordered_map<int, unordered_map<int, int>> t, v;

        for (int i = 0; i < pts.size(); ++i) {
            for (int j = i + 1; j < pts.size(); ++j) {
                int dx = pts[j][0] - pts[i][0], dy = pts[j][1] - pts[i][1];

                if (dx < 0 || (dx == 0 && dy < 0)) dx = -dx, dy = -dy;

                int g = std::gcd(dx, std::abs(dy));
                int sx = dx / g, sy = dy / g;
                int des = sx*pts[i][1] - sy*pts[i][0];
                int key1 = (sx << 12) | (sy + 2000);
                int key2 = (dx << 12) | (dy + 2000);

                ++t[key1][des];
                ++v[key2][des];
            }
        }

        return count(t) - count(v) / 2;
    }

    int count(unordered_map<int, unordered_map<int, int>>& mp) {
        long long ans = 0;

        for (auto& [k1, inner] : mp) {
            long long sum = 0;
            for (auto& [k2, val] : inner)
                sum += val;

            for (auto& [k2, val] : inner)
                ans += val * (sum -= val);
        }

        return ans;
    }
};