// SOLUTION - 3 : Greedy + Freq Counting + Two Pointers

class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        const int n = s.size();
        string ans(n, ' ');

        int left = 0, right = n - 1;

        for (int i = 0; i < 26; i++) {
            while (freq[i] >= 2) {
                ans[left++] = char('a' + i);
                ans[right--] = char('a' + i);
                freq[i] -= 2;
            }

            if (freq[i] == 1)
                ans[s.size() / 2] = char('a' + i);
        }

        return ans;
    }
};





// SOLUTION - 2 : Better For Loops

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
//                 if(charmap[i]%2 != 0){
//                     odd = i;
//                     --charmap[i];
//                 }

//                 for(int j=0; j<charmap[i]/2; j++){
//                     ans.push_back(i + 'a');
//                 }
//             }
//         }

//         if(odd != -1) ans.push_back(odd + 'a');

//         for(int i=25; i>=0; i--){
//             if(charmap[i] != 0){
//                 for(int j=0; j<charmap[i]/2; j++){
//                     ans.push_back(i + 'a');
//                 }
//             }
//         }

//         return ans;
//     }
// };


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