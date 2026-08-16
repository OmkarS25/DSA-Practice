class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int mod_3[3] = {0, 0, 0};

        for (auto& s : stones)
            mod_3[s % 3]++;

        if (~mod_3[0] & 1)
            return min(mod_3[1], mod_3[2]) >= 1;

        return abs(mod_3[1] - mod_3[2]) >= 3;
    }
};