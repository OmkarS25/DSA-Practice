class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        int stringLength = s.size(); 
        string smallestLexString = s; 
        for (int i = 0; i < stringLength; ++i) {
            s = s.substr(stringLength - b) + s.substr(0, stringLength - b);
            for (int j = 0; j < 10; ++j) {
                for (int k = 1; k < stringLength; k += 2) {
                    s[k] = ((s[k] - '0' + a) % 10) + '0';
                }
                if (b % 2 == 1) {
                    for (int p = 0; p < 10; ++p) {
                        for (int k = 0; k < stringLength; k += 2) {
                            s[k] = ((s[k] - '0' + a) % 10) + '0';
                        }
                        smallestLexString = min(smallestLexString, s);
                    }
                } else smallestLexString = min(smallestLexString, s);
            }
        }
        return smallestLexString;
    }
};

// class Solution {
// public:
//     string findLexSmallestString(string s, int a, int b) {
//         unordered_set<string> visited;
//         queue<string> q;
//         q.push(s);
//         string smallest = s;

//         auto addOperation = [&](string str) {
//             for (int i = 1; i < str.size(); i += 2) {
//                 str[i] = ((str[i] - '0' + a) % 10) + '0';
//             }
//             return str;
//         };

//         auto rotateOperation = [&](string str) {
//             int n = str.size();
//             int shift = b % n;
//             return str.substr(n - shift) + str.substr(0, n - shift);
//         };

//         while (!q.empty()) {
//             string cur = q.front();
//             q.pop();

//             if (visited.count(cur)) continue;
//             visited.insert(cur);
//             smallest = min(smallest, cur);

//             // Apply both operations
//             string added = addOperation(cur);
//             string rotated = rotateOperation(cur);

//             if (!visited.count(added)) q.push(added);
//             if (!visited.count(rotated)) q.push(rotated);
//         }

//         return smallest;
//     }
// };