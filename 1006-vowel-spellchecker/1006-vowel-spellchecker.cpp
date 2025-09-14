class Solution {
    string devowel(string word) {
        for (char& ch : word) 
            if (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') ch = '*';
        return word;
    }
    string toLower(string word) {
        for (char& ch : word) ch = tolower(ch);
        return word;
    }


public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact;
        unordered_map<string, string> capMap;
        unordered_map<string, string> vowelMap;

        for (string word : wordlist) {
            exact.insert(word);

            string lower = toLower(word);
            if (capMap.find(lower) == capMap.end()) capMap[lower] = word;

            string devow = devowel(lower);
            if (vowelMap.find(devow) == vowelMap.end()) vowelMap[devow] = word;
        }

        vector<string> answer;
        for (string query : queries) {
            if (exact.count(query)) {
                answer.push_back(query);
            } else {
                string lower = toLower(query);
                if (capMap.count(lower)) {
                    answer.push_back(capMap[lower]);
                } else {
                    string devow = devowel(lower);
                    if (vowelMap.count(devow)) {
                        answer.push_back(vowelMap[devow]);
                    } else {
                        answer.push_back("");
                    }
                }
            }
        }

        return answer;
    }
};



// This Solution gives TLE

// class Solution {
//     string vowel (string word){
//         for(char& ch : word){
//             if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') ch = '*';
//         }
//         return word;
//     }
//     string capital(string word){
//         for(char& ch : word) ch = (char)tolower(ch);
//         return word;
//     }
// public:
//     vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
//         const int n = queries.size(), m = wordlist.size();
//         vector<string> answer(n, "");

//         for(int i=0; i<n; i++){
//             bool wordFound = 0;
//             // Exact match
//             for(int j=0; j<m; j++){
//                 if(wordlist[j] ==  queries[i]){
//                     answer[i] = wordlist[j];
//                     wordFound = 1;
//                     break;
//                 }
//             }
//             if(wordFound) continue;
//             // Only Case error
//             for(int j=0; j<m; j++){
//                 string word = capital(wordlist[j]);
//                 string query = capital(queries[i]);
//                 if(word ==  query){
//                     answer[i] = wordlist[j];
//                     wordFound = 1;
//                     break;
//                 }
//             }
//             if(wordFound) continue;
//             // Case error + Vowel error
//             for(int j=0; j<m; j++){
//                 string word = vowel(capital(wordlist[j]));
//                 string query = vowel(capital(queries[i]));
//                 if(word ==  query){
//                     answer[i] = wordlist[j];
//                     wordFound = 1;
//                     break;
//                 }
//             }
//         }
//         return answer;
//     }
// };