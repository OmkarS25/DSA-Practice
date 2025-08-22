class Solution {
public:
    string reverseVowels(string s) {
        stack<char> st;
        for(char & ch : s)
            if(ch=='a' || ch=='A' || ch=='e' || ch=='E' 
            || ch=='i' || ch=='I' || ch=='o' || ch=='O' 
            || ch=='u' || ch=='U') st.push(ch);
        for(char& ch : s)
            if(ch=='a' || ch=='A' || ch=='e' || ch=='E' 
            || ch=='i' || ch=='I' || ch=='o' || ch=='O' 
            || ch=='u' || ch=='U') ch=st.top(), st.pop();
        return s;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();