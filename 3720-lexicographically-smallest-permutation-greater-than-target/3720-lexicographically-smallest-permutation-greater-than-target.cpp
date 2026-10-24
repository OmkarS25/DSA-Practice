class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        map<char, int> mp;

        for (char c : s)
            mp[c]++;

        string ans = "";

        // Build the longest prefix equal to target
        for (int i = 0; i < n; i++) {

            // Same character available
            if (mp.count(target[i]) && mp[target[i]] > 0) {
                ans += target[i];
                mp[target[i]]--;

                if (mp[target[i]] == 0)
                    mp.erase(target[i]);
            }
            else {
                // Try to make this position greater
                auto it = mp.upper_bound(target[i]);

                if (it != mp.end()) {
                    ans += it->first;
                    mp[it->first]--;

                    if (mp[it->first] == 0)
                        mp.erase(it->first);

                    // Fill remaining characters
                    for (auto p : mp) {
                        for (int j = 0; j < p.second; j++)
                            ans += p.first;
                    }

                    return ans;
                }

                // Cannot continue
                break;
            }
        }

        if (ans > target)
            return ans;

        // Backtrack
        for (int i = (int)ans.size() - 1; i >= 0; i--) {

            // Put ans[i] back into map
            mp[ans[i]]++;

            // Remove it from answer
            ans.pop_back();

            // Try a character greater than target[i]
            auto it = mp.upper_bound(target[i]);

            if (it != mp.end()) {
                ans += it->first;
                mp[it->first]--;

                if (mp[it->first] == 0)
                    mp.erase(it->first);

                // Add remaining characters in sorted order
                for (auto p : mp) {
                    for (int j = 0; j < p.second; j++)
                        ans += p.first;
                }

                return ans;
            }
        }

        return "";
    }
};