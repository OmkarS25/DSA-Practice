#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("-ffloat-store")
#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();

class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        auto splitWords = [](const string& sentence) {
            vector<string> words;
            string word = "";
            for (char c : sentence) {
                if (c == ' ') {
                    if (!word.empty()) {
                        words.push_back(word);
                        word = "";
                    }
                } else word += c;
            }
            if (!word.empty()) words.push_back(word);
            return words;
        };
        vector<string> words1 = splitWords(sentence1), words2 = splitWords(sentence2);
        if (words1.size() < words2.size()) swap(words1, words2);
        int start = 0, end = 0;
        const int n1 = words1.size(), n2 = words2.size();
        while (start < n2 && words1[start] == words2[start]) start++;
        while (end < n2 && words1[n1 - end - 1] == words2[n2 - end - 1]) end++;
        return start + end >= n2;
    }
};