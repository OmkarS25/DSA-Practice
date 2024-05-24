class Solution {
public:
    // Helper function to solve the problem using backtracking
    void solve(const vector<string>& words, int index, unordered_map<char, int>& letterCount, 
               int currentScore, unordered_map<char, int>& values, int& maxScore) {
        if (index == words.size()) {
            maxScore = max(maxScore, currentScore);
            return;
        }

        // Option 1: Skip the current word
        solve(words, index + 1, letterCount, currentScore, values, maxScore);

        // Option 2: Include the current word if possible
        string word = words[index];
        bool canInclude = true;
        int wordScore = 0;
        unordered_map<char, int> tempCount;

        // Check if the current word can be formed with the remaining letters
        for (char ch : word) {
            if (letterCount[ch] <= 0) {
                canInclude = false;
                break;
            }
            tempCount[ch]++;
            if (tempCount[ch] > letterCount[ch]) {
                canInclude = false;
                break;
            }
            wordScore += values[ch];
        }

        // If the word can be included, update the letter count and score, and recurse
        if (canInclude) {
            for (char ch : word) {
                letterCount[ch]--;
            }
            solve(words, index + 1, letterCount, currentScore + wordScore, values, maxScore);
            for (char ch : word) {
                letterCount[ch]++;
            }
        }
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        // Map the score of each character
        unordered_map<char, int> values;
        for (int i = 0; i < score.size(); i++) {
            char ch = 'a' + i;
            values[ch] = score[i];
        }

        // Map the count of each character present in letters
        unordered_map<char, int> letterCount;
        for (char ch : letters) {
            letterCount[ch]++;
        }

        int maxScore = 0;
        solve(words, 0, letterCount, 0, values, maxScore);

        return maxScore;
    }
};


// class Solution {
// public:
//     int a[26], b[26], ans = 0;
//     void solve(int idx, vector<string>& words, vector<int>& score) {
//         if (idx == words.size()) {
//             int sc = 0;
//             for (int i = 0; i < 26; i++) {
//                 if (b[i] > a[i])return;
//                 sc += score[i] * b[i];
//             }
//             ans = max(ans, sc);
//             return;
//         }
//         solve(idx + 1, words, score);
//         for (auto i : words[idx]) b[i - 'a']++;
//         solve(idx + 1, words, score);
//         for (auto i : words[idx]) b[i - 'a']--;
//     }
//     int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
//         for (auto i : letters) a[i - 'a']++;
//         solve(0, words, score);
//         return ans;
//     }
// };