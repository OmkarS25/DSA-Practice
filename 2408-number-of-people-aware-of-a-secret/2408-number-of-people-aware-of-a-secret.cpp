class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        long long know = 1, shared = 0;

        unordered_map<int, int> forgetDay, beginSharedDay;

        beginSharedDay[delay + 1] = 1;
        forgetDay[forget + 1] = 1;

        for(int day=2; day<=n; day++){
            shared = (shared + beginSharedDay[day] - forgetDay[day] + MOD) % MOD;
            know = (know + shared - forgetDay[day] + MOD) % MOD;

            beginSharedDay[day + delay] = shared;
            forgetDay[day + forget] = shared;
        }

        return know;
    }
};