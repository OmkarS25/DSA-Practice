class Solution {
public:
    string findTheString(vector<vector<int>>& lcp) {
        const int n = lcp.size();
        vector<char> v(n, 'a');
        char ch = 'b';
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= i; j--) {
                int mini = min(n - i, n - j);
                if (lcp[i][j] > mini) return "";
                if (lcp[i][j] > 0) {
                    if (v[i] == 'a' and v[j] == 'a') {
                        if(ch - 1 > 'z') return ""; 
                        v[i] = ch;
                        v[j] = ch;
                        ch++;
                    } 
                    else if (v[i] == 'a') v[i] = v[j];
                    else v[j] = v[i];
                }
            }
        }
        map<char, char> mp;
        ch = 'a';
        string ans = "";
        for (int i = 0; i < n; i++) {
            if (mp.count(v[i])) v[i] = mp[v[i]];
            else {
                mp[v[i]] = ch;
                v[i] = ch++;
            }
            ans += v[i];
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int k = 0;
                while (i + k < n && j + k < n && ans[i + k] == ans[j + k]) {
                    k++;
                }
                if (lcp[i][j] != k) return "";
            }
        }
        return ans;
    }
};