class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> map(26,0);
        for(string &x:words2){
            vector<int> temp(26,0);
            for(char c:x) temp[c-'a']++;
            for(int i=0;i<26;i++){
                map[i] = max(temp[i],map[i]);
            }
        }
        vector<string> ans;
        for(string i: words1){
            bool flag = true;
            vector<int> temp(26,0);
            for (char c : i) temp[c-'a']++;
            for(int j=0;j<26;j++){
                if(temp[j] < map[j]){
                    flag = false;
                    break;
                }
            }
            if(flag) ans.push_back(i);
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