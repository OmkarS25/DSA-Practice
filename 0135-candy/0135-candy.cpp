class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(); // Total number of children

        // Step 1: Initialize each child with at least 1 candy
        vector<int> cand(n, 1);

        // Step 2: Traverse from left to right
        // If current child's rating is greater than previous child's rating,
        // then give one more candy than the previous child
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                cand[i] = cand[i - 1] + 1;
            }
        }

        // Step 3: Traverse from right to left
        // If current child's rating is greater than next child's rating,
        // then make sure they have more candies than the next child
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                // Only update if current child has equal or fewer candies than the next child
                if (cand[i] <= cand[i + 1]) {
                    cand[i] = cand[i + 1] + 1;
                }
            }
        }

        // Step 4: Sum all the candies to get the minimum required
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += cand[i];
        }

        return ans; // Return the total number of candies needed
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();