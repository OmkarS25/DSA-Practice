class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int start = 0, maxLen = 0;
        unordered_map<int, int> basket;

        for (int end = 0; end < fruits.size(); ++end) {
            basket[fruits[end]]++;

            while (basket.size() > 2) {
                basket[fruits[start]]--;
                if (basket[fruits[start]] == 0) {
                    basket.erase(fruits[start]);
                }
                start++;
            }

            maxLen = max(maxLen, end - start + 1);
        }

        return maxLen;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();