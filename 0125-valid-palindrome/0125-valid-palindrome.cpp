class Solution {
public:
    bool isPalindrome(string s) {
        string res;
        for(char ch : s){
            if('A' <= ch && ch <= 'Z'){
                res.push_back(ch+32);
            }
            else if('a' <= ch && ch <= 'z'){
                res.push_back(ch);
            }
            else if (ch >= '0' && ch <= '9') {
                res.push_back(ch);
            }
        }
        int i=0, j=res.length()-1;
        while(i<j){
            if(res[i++] != res[j--]) return false;
        }
        return true;
    }
};