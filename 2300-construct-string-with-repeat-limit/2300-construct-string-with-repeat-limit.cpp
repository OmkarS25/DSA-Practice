class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        sort(s.rbegin(), s.rend());

        string result;
        int freq = 1, pointer = 0;

        for (int i = 0; i < s.size(); ++i) {
            if (!result.empty() && result.back() == s[i]) {
                if (freq < repeatLimit) {
                    result += s[i];
                    freq++;
                } else {
                    pointer = max(pointer, i + 1);
                    while (pointer < s.size() && s[pointer] == s[i]) {
                        pointer++;
                    }

                    if (pointer < s.size()) {
                        result += s[pointer];
                        swap(s[i], s[pointer]);
                        freq = 1;
                    } else {
                        break;
                    }
                }
            } else {
                result += s[i];
                freq = 1;
            }
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