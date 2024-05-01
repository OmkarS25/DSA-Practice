class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i = 0;
        for(char a : word){
            i++;
            if(a==ch){
                reverse(word.begin(), word.begin()+i);
                return word;
            }
        }
        return word;
    }
};