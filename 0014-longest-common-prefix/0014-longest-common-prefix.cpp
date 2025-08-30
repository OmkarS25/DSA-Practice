class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        string ans = "";
        int i=0; 
        while (true){
            char curr_ch = 0;
            for(auto &str : s){
                if(i >= str.size()){
                    // out of bound
                    curr_ch = 0;
                    break;
                }
                // just started
                if(curr_ch == 0) curr_ch = str[i];
                else if(str[i] != curr_ch){
                    curr_ch = 0;
                    break;
                }
            }
            if(curr_ch == 0) break;
            ans += curr_ch;
            i++;
        }
        return ans;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();