class Solution {
public:
    bool isIsomorphic(string s, string t) {
        char s_to_t[256] = {0};
            char t_to_s[256] = {0};
            for (int i = 0; i < s.size(); i++) {
                if (s_to_t[s[i]] != 0) {
                    if (s_to_t[s[i]] != t[i]) return false;
                } else if (t_to_s[t[i]] != 0) {
                    return false;
                } else {
                    s_to_t[s[i]] = t[i];
                    t_to_s[t[i]] = s[i];
                }
            }
            return true;
    }
};