class Solution {
    bool validWord(const string& word, const unordered_set<char>& brokenSet) {
        for (char ch : word) {
            if (brokenSet.count(ch)) return false;
        }
        return true;
    }

public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> brokenSet(brokenLetters.begin(), brokenLetters.end());
        int res = 0;
        stringstream ss(text);
        string word;

        while (ss >> word) {
            if (validWord(word, brokenSet)) res++;
        }

        return res;
    }
};
