class Solution {
    bool isVowel(char& ch){
        return (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ||
        ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ) ? true : false;
    }
public:
    string sortVowels(string s) {
        string vowels = "";
        for(char& ch : s) if(isVowel(ch)) vowels += ch;
        sort(vowels.begin(), vowels.end());
        int index = 0;
        for(char& ch : s){
            if(isVowel(ch)) ch = vowels[index++];
        }
        return s;
    }
};