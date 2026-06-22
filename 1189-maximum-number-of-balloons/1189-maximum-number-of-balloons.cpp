class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int freq[26] = {0};

        for(int i=0; i<text.size(); i++) {
            freq[text[i] - 'a']++;
        }

        int ans = min(freq[0], freq[1]); // a, b
        ans = min(ans, freq[13]); // n
        ans = min(ans, freq[11] / 2); // l
        ans = min(ans, freq[14] / 2); // o

        return ans;
    }
};