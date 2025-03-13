class Solution{
public:
    int minZeroArray(vector<int> &v, const vector<vector<int>> &q){
        long long total_subtract = 0;
        for (const auto &query : q)
            total_subtract += query[2];

        long long max_val = *max_element(v.begin(), v.end());
        if (total_subtract < max_val) return -1;

        int n = v.size();
        if (accumulate(v.begin(), v.end(), 0LL) == 0) return 0;

        vector<int> diff(n + 1, 0); // Difference array
        int step = 1;

        for (const auto &query : q){
            int l = query[0], r = query[1], val = query[2];
            diff[l] -= val;
            diff[r + 1] += val;

            int current_diff = 0;
            bool all_non_positive = true;

            for (int i = 0; i < n; ++i){
                current_diff += diff[i];
                if (current_diff + v[i] > 0){
                    all_non_positive = false;
                    break;
                }
            }
            if (all_non_positive) return step;
            ++step;
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