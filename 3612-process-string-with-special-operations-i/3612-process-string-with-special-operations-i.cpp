class Solution {
public:
    string processStr(string s) {
        string ans = "";
        for(int i=0; i<s.length(); i++){
            if(s[i] == '*' && ans.size() > 0) {
                ans = ans.substr(0, ans.length()-1);
            }
            else if(s[i] == '#' && ans.size() > 0) {
                ans += ans;
            }
            else if(s[i] == '%' && ans.size() > 1) {
                reverse(ans.begin(), ans.end());
            }
            else if(s[i] != '*' && s[i] != '#' && s[i] != '%') {
                ans += s[i];
            }
        }
        return ans;
    }
};