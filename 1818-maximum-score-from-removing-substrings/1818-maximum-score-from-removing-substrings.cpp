class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int res=0, top_score, bot_score;
        string top, bot;
        if(y>x){
            top = "ba";
            top_score = y;
            bot = "ab";
            bot_score = x;
        }
        else{
            top = "ab";
            top_score = x;
            bot = "ba";
            bot_score = y;
        }
        vector<char> stack;
        for(char ch: s){
            if(ch == top[1] && !stack.empty() && stack.back() == top[0]){
                res += top_score;
                stack.pop_back();
            }
            else{
                stack.push_back(ch);
            }
        }
        vector<char> new_stack;
        for(char ch: stack){
            if (ch == bot[1] && !new_stack.empty() && new_stack.back() == bot[0]) {
                res += bot_score;
                new_stack.pop_back();
            } else {
                new_stack.push_back(ch);
            }
        }
        return res;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();