class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size() ;
        vector<string> ans ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(words[i] == words[j]) continue ;
                if(words[j].find(words[i]) != string::npos){
                    ans.push_back(words[i]) ;
                    break ;
                }
            }
        }
        return ans ;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();