#pragma GCC optimize("O3", "unroll-loops") 
static const auto init = [](){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string s = s1 + " " + s2, tmp;
        stringstream str(s);
        unordered_map<string,int> um;
        while(str>>tmp){
            um[tmp]++;
        }
        vector<string> ans;
        for(auto& val:um){ // auto it=um.begin();it<um.end();it++
            if(val.second==1) ans.emplace_back(val.first); // can use push_back also
        }
        return ans;
    }
};