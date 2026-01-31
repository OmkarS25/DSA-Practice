// Solution Using Binary Search
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int beg = 0, end = letters.size() - 1;
        char ans = letters[0];

        while (beg <= end) {
            int mid = beg + (end - beg) / 2;
            if (letters[mid] > target) {
                ans = letters[mid];
                end = mid - 1;
            } 
            else beg = mid + 1;
        }
        return ans;
    }
};

// Solution Using For Loop
// class Solution {
// public:
//     char nextGreatestLetter(vector<char>& letters, char target) {
//         for(char ch : letters){
//             if(ch > target) return ch;
//         }
//         return letters[0];
//     }
// };