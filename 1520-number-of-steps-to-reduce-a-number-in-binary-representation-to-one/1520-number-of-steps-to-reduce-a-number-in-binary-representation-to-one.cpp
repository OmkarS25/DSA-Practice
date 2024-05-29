class Solution {
public:
    int numSteps(string s) {
       int count = 0, len = s.length();
       while(len > 1){
            if(s[len-1] == '0'){
                s.pop_back();
                len--;
            }
            else{
                int i = len - 1;
                while (i >= 0 && s[i] == '1') {
                    s[i] = '0';
                    i--;
                }
                if (i >= 0) {
                    s[i] = '1';
                } else {
                    s.insert(s.begin(), '1');
                    len++;
                }
            }
            count++;
        } 
        return count; 
    }
};

// More simple solution that I liked
// class Solution {
// public:
//     int numSteps(string s) {
//         int sol = 0, carry = 0;
//         for (int i = s.size()-1; i > 0; i--) {
//             sol++;
//             if (s[i] + carry == '1') {
//                 sol++;
//                 carry = 1;
//             }
//         }
//         return sol + carry;
//     }
// };