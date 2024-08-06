class Solution {
public:
    int minimumPushes(string word) {
        vector<int> letterFreq(26, 0);
        for (char c : word) {
            letterFreq[c - 'a']++;
        }
        sort(letterFreq.rbegin(), letterFreq.rend());
        int totalPresses = 0;
        for (int i = 0; i < 26; i++) {
            if (letterFreq[i] == 0) break;
            totalPresses += (i / 8 + 1) * letterFreq[i];
        }
        return totalPresses;
    }
};

// class Solution {
// public:
//     int minimumPushes(string word) {
//         unodered_map<char, int> charCount;
//         for(char ch: word){
//             charCount[ch]++;
//         }
//         priority_queue<int> freqHeap;
//         for(const auto & pair: charCount){
//             freqHeap.push(pair.second);
//         }
//         int totalPresses = 0, keyPosition = 0;
//         while(!freqHeap.empty()){
//             totalPresses += (keyPosition / 8+1) * freqHeap.top();
//             freqHeap.pop();
//             keyPosition++;
//         }
//         return totalPresses;
//     }
// };


// class Solution {
// public:
//     int minimumPushes(string word) {
//         vector<int> freq(26, 0);
//         for (char c : word) {
//             freq[c - 'a']++;
//         }
//         sort(freq.begin(), freq.end());
//         int totalPushes = 0, multiplier = 1;
//         for (int i = 25; i >= 0; i--) {
//             if (freq[i] == 0) break;
//             if ((25 - i) % 8 == 0 && i != 25) multiplier++;
//             totalPushes += freq[i] * multiplier;
//         }
//         return totalPushes;
//     }
// };