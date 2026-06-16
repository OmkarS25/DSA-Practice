class Solution {
public:
    string processStr(string s) {
        string ans = "";
        for(int i=0; i<s.length(); i++){
            if(s[i] == '*' || s[i] == '#' || s[i] == '%') {
                if(ans.size()>0) {
                    if(s[i] == '*') ans = ans.substr(0, ans.length()-1);
                    else if(s[i] == '#') ans += ans;
                    else if(s[i] == '%') reverse(ans.begin(), ans.end());
                }
            }
            else ans += s[i];
        }
        return ans;
    }
};