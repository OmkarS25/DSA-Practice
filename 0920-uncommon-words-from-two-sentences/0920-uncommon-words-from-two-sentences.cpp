class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string s = s1 + " " + s2;
        cout<<s1.max_size();
        unordered_map<string, int> map;
        string temp = "";
        for(char & val : s){
            if(val == ' '){
                map[temp]++;
                temp = "";
            }
            else temp += val;
        }
        if(temp != ""){
            map[temp]++;
            temp = "";
        }
        vector<string> ans;
        for(auto& val : map){
            if(val.second == 1) ans.emplace_back(val.first);
        }
        return ans;
    }
};