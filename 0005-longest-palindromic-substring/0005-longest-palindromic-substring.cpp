class Solution {
    bool isPalindrome(string& s, int i, int j){
        while(i<j){
            if(s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }
public:
    string longestPalindrome(string s) {
        int start=0, end=0;
        for(int i=0; i<s.size(); i++){
            for(int j=i; j<s.size(); j++){
                if(isPalindrome(s, i, j)){
                    if(end-start < j-i){
                        start=i;
                        end=j;
                    }
                }
            }
        }
        return s.substr(start, end - start + 1);
    }
};