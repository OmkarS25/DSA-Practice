class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";

        for (int i = 0; i < words.size(); i++) {
            int sum = 0;

            for (char ch : words[i]) {
                sum += weights[ch - 'a'];
            }

            int index = sum % 26;
            ans += (char)('z' - index);
        }

        return ans;
    }
};