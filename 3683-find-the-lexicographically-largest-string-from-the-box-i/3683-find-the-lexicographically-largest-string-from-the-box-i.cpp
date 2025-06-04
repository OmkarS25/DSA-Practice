class Solution {
public:
    string answerString(string word, int num) {
        if(num == 1) return word;
        const int n=word.size();
        string ans="";
        
        for(int i=0; i<n; i++){
            string temp;
            for(int j=i; j<n; j++){
                int remleft = max(i, 0);
                int remright = max(n-j-1, 0);
                int cutspossible = remleft + remright;
                
                if(cutspossible >= (num-1)) temp.push_back(word[j]);
                else break;
            }
            ans = max(ans, temp);
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