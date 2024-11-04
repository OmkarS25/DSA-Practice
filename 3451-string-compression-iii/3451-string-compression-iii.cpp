class Solution {
public:
    string compressedString(string word) {
        string res = "";
        char stack[9];
        int top = -1;
        for (char ch : word) {
            if (top == -1) stack[++top] = ch; 
            else if (top == 8) {
                res += to_string(top + 1) + stack[top];
                top = -1;
                stack[++top] = ch;
            }
            else if (stack[top] == ch) stack[++top] = ch;
            else {
                res += to_string(top + 1) + stack[top];
                top = 0;
                stack[top] = ch;
            }
        }
        if (top != -1) res += to_string(top + 1) + stack[top];
        return res;
    }
};

#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("-ffloat-store")
#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();