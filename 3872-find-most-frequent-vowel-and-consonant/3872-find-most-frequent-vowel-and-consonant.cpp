class Solution {
public:
    int maxFreqSum(string s) {
        int arr[26] = {0};
        for(char& ch : s) arr[ch-'a']++;
        int vowels = 0, consonants = 0;
        for(int i=0; i<26; i++){
            if(i == 'a'-'a' || i == 'e'-'a' || i == 'i'-'a' 
            || i == 'o'-'a' || i == 'u'-'a') vowels = max(vowels, arr[i]);
            else consonants = max(consonants, arr[i]);
        }
        return vowels+consonants;
    }
};