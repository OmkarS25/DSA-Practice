class Solution {
public:
    string robotWithString(string s) {
        string res = "";
        string t = "";
        vector<int> freq(26, 0);

        for (char ch : s) freq[ch - 'a']++;

        char minChar = 'a';
        for (char ch : s) {
            t += ch;
            freq[ch - 'a']--;

            // Update minChar to the smallest char that still has freq > 0
            while (minChar <= 'z' && freq[minChar - 'a'] == 0) {
                minChar++;
            }

            // Pop from t while possible
            while (!t.empty() && t.back() <= minChar) {
                res += t.back();
                t.pop_back();
            }
        }

        // Append remaining chars from stack
        while (!t.empty()) {
            res += t.back();
            t.pop_back();
        }

        return res;
    }
};
