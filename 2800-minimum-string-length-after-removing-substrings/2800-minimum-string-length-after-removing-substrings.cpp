#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("-ffloat-store")
#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

class Solution {
public:
    int minLength(string s) {
        stack<char> st;
        for(char c : s) {
            if(!st.empty() && ((st.top() == 'A' && c == 'B') || (st.top() == 'C' && c == 'D'))) st.pop();
            else st.push(c);
        }
        return st.size();  
    }
};