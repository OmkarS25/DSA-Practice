class Solution {
public:
    string reverseOnlyLetters(string s) {
        stack<char> st;
        for(char ch : s){
            if((ch >= 97 && ch<=122) || (ch >= 65 && ch<=90)) st.push(ch);
        }
        for(char & ch : s){
            if((ch >= 97 && ch<=122) || (ch >= 65 && ch<=90)){
                ch = st.top();
                st.pop();
            }
        }
        return s;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();