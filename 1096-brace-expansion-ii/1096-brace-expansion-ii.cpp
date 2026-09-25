class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        unordered_set<string> words;
        expand(expression, words);

        vector<string> answer(words.begin(), words.end());
        sort(answer.begin(), answer.end());
        return answer;
    }

private:
    void expand(const string& current, unordered_set<string>& words) {
        size_t close = current.find('}');
        if (close == string::npos) {
            words.insert(current);
            return;
        }

        size_t open = current.rfind('{', close);
        string prefix = current.substr(0, open);
        string suffix = current.substr(close + 1);

        size_t start = open + 1;
        for (size_t i = start; i <= close; ++i) {
            if (i == close || current[i] == ',') {
                string choice = current.substr(start, i - start);
                expand(prefix + choice + suffix, words);
                start = i + 1;
            }
        }
    }
};