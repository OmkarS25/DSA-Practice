class Solution {
public:
    string addSpaces(string& s, vector<int>& spaces) {
        const int m = spaces.size(), n = s.size();
        string t(n + m, ' ');
        spaces.push_back(n);// reduce number of branches

        int j = 0, i=0; // Pointer for spaces
        for (i = 0; i < n; i++) {
            while (i < n && i != spaces[j]) {
                t[i + j] = s[i];
                i++;
            }
            if (j < m) {
                t[i + j + 1] = s[i];
                j++;
            }
        }
        return t;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();