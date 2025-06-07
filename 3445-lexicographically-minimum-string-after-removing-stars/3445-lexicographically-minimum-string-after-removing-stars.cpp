class Solution {
public:
    struct compare {
        bool operator()(const pair<char, int>& a, const pair<char, int>& b) {
            if (a.first != b.first)
                return a.first > b.first; // min-heap based on character
            // if characters are same, prefer larger index
            return a.second < b.second;
        }
    };

    string clearStars(string s) {
        // Min-heap to track the smallest character and its index
        priority_queue<pair<char, int>, vector<pair<char, int>>, compare>
            minHeap;

        int minIndex = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '*') {
                if (!minHeap.empty()) {
                    minIndex = minHeap.top().second;
                    minHeap.pop();
                }
                // Mark character at that index as deleted
                s[minIndex] = '*';
            } else
                // Push each non-'*' character with its index into the heap
                minHeap.push({s[i], i});
        }
        // Build the result string from non-deleted (non-'*') characters
        string result = "";
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] != '*') result += s[i];
        }

        return result;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();