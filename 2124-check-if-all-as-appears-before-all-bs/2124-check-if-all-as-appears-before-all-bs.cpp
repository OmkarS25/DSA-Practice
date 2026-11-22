class Solution {
public:
    bool checkString(string s) {
        bool seen_b = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == 'b') seen_b = 1;
            if(s[i] == 'a' && seen_b == 1) return 0;
        }
        return 1;
    }
};