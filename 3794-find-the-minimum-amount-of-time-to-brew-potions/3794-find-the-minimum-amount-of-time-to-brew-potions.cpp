class Solution {
public:
    long long minTime(vector<int>& skill, vector<int>& mana) {
        const int n = skill.size(), m = mana.size();
        vector<long long> prev(n), curr(n);
        long long run = 0;
        for (int i = 0; i < n; ++i) {
            run += (long long)skill[i] * mana[0];
            prev[i] = run;
        }
        for (int j = 1; j < m; ++j) {
            long long running_pre = 0;
            long long maxv = LLONG_MIN;
            for (int i = 0; i < n; ++i) {
                long long val = prev[i] - running_pre;
                if (val > maxv) maxv = val;
                running_pre += (long long)skill[i] * mana[j];
            }
            long long sj = max(0LL, maxv);
            long long running_sum = 0;
            for (int i = 0; i < n; ++i) {
                running_sum += (long long)skill[i] * mana[j];
                curr[i] = sj + running_sum;
            }
            prev.swap(curr);
        }
        return prev[n-1];
    }
};