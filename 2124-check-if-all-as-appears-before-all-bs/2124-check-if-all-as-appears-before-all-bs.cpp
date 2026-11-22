class Solution {
public:
    bool checkString(string &s) {
        for(size_t i=1; i<s.size(); i++){
            if (s[i-1] == 'b' && s[i] == 'a') return 0;
        }
        return 1;
    }
};