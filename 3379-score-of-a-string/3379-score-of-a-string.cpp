class Solution {
public:
    int scoreOfString(string s) {
        int score = 0;
        for(int i=1; i<s.length(); i++){
            score += abs(int(s[i-1]) - int(s[i]));
        }
        return score;
    }
};