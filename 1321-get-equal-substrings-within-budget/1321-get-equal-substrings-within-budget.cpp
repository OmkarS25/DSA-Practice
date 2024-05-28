class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int maxlen=0, n=s.length();
        int currentCost = 0;
        int start = 0;

        for (int end = 0; end < n; ++end) {
            currentCost += abs(s[end] - t[end]);

            // If the currentCost exceeds maxCost, move the start pointer to the right
            while (currentCost > maxCost) {
                currentCost -= abs(s[start] - t[start]);
                ++start;
            }

            // Update the maximum length of the valid substring
            maxlen = max(maxlen, end - start + 1);
        }
        
        return maxlen;
    }
};