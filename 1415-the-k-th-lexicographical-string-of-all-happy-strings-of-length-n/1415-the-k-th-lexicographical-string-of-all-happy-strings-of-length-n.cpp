class Solution {
private:
    void solve(int n, vector<string>& st, string s){
        if(s.size() == n){
            st.push_back(s);
            return;
        }
        if(s.size() == 0){
            solve(n, st, s+"a");
            solve(n, st, s+"b");
            solve(n, st, s+"c");
        }else{
            if(s.back() != 'a') solve(n, st, s+"a");
            if(s.back() != 'b') solve(n, st, s+"b");
            if(s.back() != 'c') solve(n, st, s+"c");
        }
    }
public:
    string getHappyString(int n, int k) {
        vector<string> st;
        string s;
        solve(n, st, s);
        if(st.size() < k) return "";
        return st[k-1];
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();