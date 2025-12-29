class Solution {
    unordered_map<string, vector<char>> mpp;
    
    bool dfs(string bot, int i, string tem) {
        // DFS function to try building pyramid
        // bot-curr bottom row, i-curr idx in bot, tem-temp str for nxt row
        
        if (bot.size() == 1) return true; // Base case: pyramid successfully built
        if (i == bot.size() - 1) return dfs(tem, 0, ""); // If we finished building the next row
        string key = bot.substr(i, 2); // Take current adjacent pair

        // Try all possible characters that can go above this pair
        for (char v : mpp[key]) {
            tem.push_back(v);              // choose
            if (dfs(bot, i + 1, tem))      // explore
                return true;               // valid pyramid found
            tem.pop_back();                // backtrack
        }

        return false; // No valid configuration found
    }

public:
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        // Build the mapping from allowed transitions
        for (auto &a : allowed) {
            mpp[a.substr(0, 2)].push_back(a[2]);
        }
        return dfs(bottom, 0, "");
    }
};