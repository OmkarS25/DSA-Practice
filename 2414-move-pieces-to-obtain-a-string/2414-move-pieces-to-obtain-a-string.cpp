class Solution {
public:
    bool canChange(string s, string t) {
        string temp1="", temp2="";
        for(int i=0; i<s.size(); i++){
            if(s[i] != '_') temp1+=s[i];
        }
        for(int i=0; i<t.size(); i++){
            if(t[i] != '_') temp2+=t[i];
        }

        if(temp1 != temp2) return false;

        int sl=0, tl=0, sr=0, tr=0;
        for(int i=0,j=0; i<s.size(); i++,j++){
            if(s[i] == 'L') sl++;
            if(t[i] == 'L') tl++;
            if(s[i] == 'R') sr++;
            if(t[i] == 'R') tr++;
            if(sl>tl || tr>sr) return false;
        }

        return true;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();