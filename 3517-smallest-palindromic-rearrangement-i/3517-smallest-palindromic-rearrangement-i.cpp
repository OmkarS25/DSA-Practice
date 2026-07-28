class Solution {
public:
    string smallestPalindrome(string s) {
        int charmap[26] = {0};
        string ans = "";
        int odd = -1; // Odd char index
        
        // Mapping the chars
        for(char ch : s){
            charmap[ch-'a']++;
        }

        for(int i=0; i<26; i++){
            if(charmap[i] != 0){
                if(charmap[i]%2 != 0){
                    odd = i;
                    --charmap[i];
                }

                for(int j=0; j<charmap[i]/2; j++){
                    ans.push_back(i + 'a');
                }
            }
        }

        if(odd != -1) ans.push_back(odd + 'a');

        for(int i=25; i>=0; i--){
            if(charmap[i] != 0){
                for(int j=0; j<charmap[i]/2; j++){
                    ans.push_back(i + 'a');
                }
            }
        }

        return ans;
    }
};


// SOLUTION - 1 : Basic

// class Solution {
// public:
//     string smallestPalindrome(string s) {
//         int charmap[26] = {0};
//         string ans = "";
//         int odd = -1; // Odd char index
        
//         // Mapping the chars
//         for(char ch : s){
//             charmap[ch-'a']++;
//         }

//         for(int i=0; i<26; i++){
//             if(charmap[i] != 0){
//                 if(charmap[i]%2 != 0) odd = i;
//                 int count = charmap[i]/2;
//                 for(int j=0; j<count; j++){
//                     ans.push_back(i + 'a');
//                 }
//             }
//         }
//         string other_half = ans;
//         reverse(other_half.begin(), other_half.end());
//         if(odd != -1) ans.push_back(odd + 'a');
//         ans += other_half;
//         return ans;
//     }
// };