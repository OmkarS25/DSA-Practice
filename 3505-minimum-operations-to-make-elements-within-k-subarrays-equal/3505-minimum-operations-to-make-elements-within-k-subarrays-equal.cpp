class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());
        sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

        int m = sorted.size();

        vector<int> rank(n);
        for (int i = 0; i < n; i++) {
            rank[i] = lower_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin() + 1;
        }
        vector<int> cnt(m + 1, 0);
        vector<long long> sum(m + 1, 0);

        int highest = 1;
        while (highest * 2 <= m) highest *= 2;

        int medianPos = (x + 1) / 2;
        int windows = n - x + 1;

        vector<long long> cost(windows);
        long long windowSum = 0;

        for (int i = 0; i < n; i++) {
            windowSum += nums[i];

            for (int j = rank[i]; j <= m; j += j & -j) {
                cnt[j]++;
                sum[j] += nums[i];
            }

            if (i >= x) {
                windowSum -= nums[i - x];

                for (int j = rank[i - x]; j <= m; j += j & -j) {
                    cnt[j]--;
                    sum[j] -= nums[i - x];
                }
            }

            if (i >= x - 1) {
                int pos = 0;
                int remaining = medianPos;
                long long leftSum = 0;
                for (int j = highest; j > 0; j >>= 1) {
                    int next = pos + j;

                    if (next <= m && cnt[next] < remaining) {
                        pos = next;
                        remaining -= cnt[next];
                        leftSum += sum[next];
                    }
                }

                long long median = sorted[pos];
                long long leftCount = medianPos - remaining;

                cost[i - x + 1] =
                    median * leftCount - leftSum +
                    (windowSum - leftSum) - median * (x - leftCount);
            }
        }

       
        const long long INF = 1e18;

        vector<long long> prev(n + 1, 0);
        vector<long long> curr(n + 1, 0);

        for (int j = 0; j < k; j++) {

            for (int i = 0; i < x; i++)
                curr[i] = INF;

            for (int i = x; i <= n; i++) {
                curr[i] = min(
                    curr[i - 1],
                    prev[i - x] + cost[i - x]
                );
            }

            swap(prev, curr);
        }

        return prev[n];
    }
};