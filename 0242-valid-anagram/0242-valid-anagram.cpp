#pragma GCC optimize ("O3", "unroll-loops")
static const bool _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();

// Frequecy Table
class Solution {
public:
    bool isAnagram(string s, string t){
        if(s.size() != t.size()) return 0;
        uint16_t freqTable[26] = {0};
        uint16_t i=0;
        for(i=0; i<s.size(); i++){
            freqTable[s[i]-97]++;
            freqTable[t[i]-97]--;
        }
        for(i=0; i<26; i++){
            if(freqTable[i] != 0) return 0;
        }
        return 1;
    }
};

// // Sorting Approach
// class Solution {
// public:
//     bool isAnagram(string s, string t){
//         int n = s.size(), m = t.size();
//         if(n != m) return 0;
//         sort(s.begin(), s.end());
//         sort(t.begin(), t.end());
//         for(int i=0; i<n; i++)
//             if(s[i] != t[i]) return 0;
//         return 1;
//     }
// };

// // HashMap Method
// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         int n = s.size(), m = t.size();
//         if(n != m) return 0;
//         unordered_map<char,int> mp1, mp2;
//         for(int i=0; i<n; i++){
//             mp1[s[i]]++;
//             mp2[t[i]]++;
//         }
//         std::unordered_map<char,int>::iterator it;
//         for(it = mp1.begin(); it!=mp1.end(); it++){
//             if(mp2.find(it->first) == mp2.end()) return 0;
//             if(it->second != mp2[it->first]) return 0;
//         }
//         return 1;
//     }
// };
