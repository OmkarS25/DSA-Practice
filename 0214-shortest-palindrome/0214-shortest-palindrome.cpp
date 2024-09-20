#pragma GCC optimize("O3", "unroll-loops") 
static const auto init = [](){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

// Solution 2
class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        int i = 0; //  i = 0 to n-1
        int j = n - 1; // j = n-1 to 0
        
        // Find the largest prefix palindrome
        while (j >= 0) {
            if (s[i] == s[j]) i++;
            j--;
        }
        
        // calculate remain
        string remain = s.substr(i); // s trim from i to end
        
        // If the entire string is already a palindrome
        // means remain = ""
        if(remain.size() == 0) return s;

        string rev_remain = remain;
        reverse(rev_remain.begin(), rev_remain.end());
        
        // Uncomment Below to see How LPP is printing for each step
        // cout<< rev_remain <<" "<< s.substr(0,i) <<" "<< remain <<endl;
        
        // recurively calculate shortest palindrome in the longest prefix string
        return rev_remain + shortestPalindrome(s.substr(0, i)) + remain;
    }
};

// Solution 1 (Getting TLE)
// class Solution {
// public:
//     bool is_palindrome(int i, int j, string s){
//         while(i < j){
//             if(s[i] != s[j]) return false;
//             i++, j--;
//         }
//         return true;
//     }
//     string shortestPalindrome(string s) {
//         int n = s.size();
//         for(int i = n-1; i >= 0; i--){
//             if(is_palindrome(0, i, s)){
//                 string temp = s.substr(i+1);
//                 reverse(temp.begin(), temp.end());
//                 return temp + s;
//             }
//         }
//         return s;
//     }
// };