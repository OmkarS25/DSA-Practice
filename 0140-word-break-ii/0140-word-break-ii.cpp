class Solution {
public:
    void solve(const string& s, const unordered_set<string>& wordDict, int start, 
                string current, vector<string>& res){
        if(start >= s.length()){
            current.pop_back(); // Removing the extra space
            res.push_back(current);
            return;
        }
        for(int end = start; end < s.length(); end++){
            string sub = s.substr(start, end - start +1);
            if(wordDict.count(sub))
                solve(s, wordDict, end+1, current + sub + " ", res);
        }
        
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        vector<string> res;
        solve(s, wordSet, 0, "", res);
        return res;
    }
};