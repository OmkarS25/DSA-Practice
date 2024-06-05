class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> result;
        // Loop through each character from 'a' to 'z'
        for (char ch = 'a'; ch <= 'z'; ch++) {
            int minCount = INT_MAX;
            // Count occurrences of the current character in each word
            for (string word : words) {
                int count = 0;
                for (char c : word) {
                    if (c == ch) count++;
                }
                minCount = min(minCount, count);
            }
            // Add the character to the result list the required number of times
            for (int i = 0; i < minCount; i++) {
                string s(1, ch);
                result.push_back(s);
            }
        }
        return result;
    }
};

// class Solution {
// public:
//     vector<string> commonChars(vector<string>& words) {
//         vector<int> last = count(words[0]);
//         for(int i=1; i<words.size(); i++){
//             last = intersection(last, count(words[1]));
//         } 
//         vector<string> result;
//         for(int i=0; i<26; i++){
//             while(last[i]>0){
//                 result.push_back(string(1, 'a'+i));
//                 last[i]--;
//             }
//         }
//         return result;
//     }
// private:
//     vector<int> count(const string & str){
//         vector<int> frequency(26,0);
//         for(char c : str){
//             frequency[c-'a']++;
//         }
//         return frequency;
//     }
//     vector<int> intersection(const vector<int>& a, const vector<int>& b){
//         vector<int> t(26,0);
//         for(int i=0; i<26; i++){
//             t[i] =  min(a[i], b[i]);
//         }
//         return t;
//     }
// };