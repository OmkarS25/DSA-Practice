#pragma GCC optimize("O3", "unroll-loops") 
static const auto init = [](){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    unordered_map<string, int> um;
    unordered_map<int, int> memo;
    int solve(string& s, int ind) {
        if (ind >= s.size()) return 0;
        if (memo.find(ind) != memo.end()) return memo[ind];  
        int extra = INT_MAX;
        string tmp = "";
        for (int i = ind; i < s.size(); i++) {
            tmp += s[i];
            if (um.find(tmp) != um.end()) extra = min(extra, solve(s, i + 1));
        }
        extra = min(extra, 1 + solve(s, ind + 1));
        return memo[ind] = extra;
    }
    int minExtraChar(string s, vector<string>& dict) {
        for (auto& val : dict) um[val]++;
        return solve(s, 0);
    }
};

// class Solution {
// public:
//     unordered_map<string, int> um, memo;
//     int solve(string s) {
//         if (s.empty()) return 0;
//         if(memo.find(s) != memo.end()) return memo[s];
//         int extra = INT_MAX;
//         string tmp = "";
//         for (int i = 0; i < s.size(); i++) {
//             tmp += s[i];
//             if (um.find(tmp) != um.end()) extra = min(extra, solve(s.substr(i + 1)));
//         }
//         extra = min(extra, 1 + solve(s.substr(1)));
//         return  memo[s] = extra;
//     }
//     int minExtraChar(string s, vector<string>& dict) {
//         for (auto& val : dict) um[val]++;
//         return solve(s);
//     }
// };