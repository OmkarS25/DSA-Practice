class Solution {
public:
    string makeFancyString(string s) {
        string ans = "";
        int cnt =1;
        ans.push_back(s[0]);
        for(int i=1;i<s.size();i++){
            if(s[i]==ans.back()){
                if(cnt==2) continue;
                else {
                    ans.push_back(s[i]);
                    cnt++;
                }
            }
            else {
                ans.push_back(s[i]);
                cnt=1;
            }
        }
        return ans;
    }
};

#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("-ffloat-store")
#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();