class Solution {
public:
    bool sumGame(string& num) {
        const int n = num.size(), n2 = n >> 1;
        int diff = 0;
        for (int i = 0; i < n; i++) {
            const char c = num[i]; // get c
            // Set the boolean isq=1 if c=='?' else  0
            // half=1 if i<n2 else 0
            bool isq = c == '?', half = i < n2;
            // set sgn=1 if half else -1
            int sgn = (half << 1) - 1;
            // if isq set d=9, else set d=2*(c-'0')
            // avoid of float arithmetic, every number is times 2
            int d = (-isq & 9) + (-!isq & (c - '0') << 1);
            diff += sgn * d; // add sgn*d to diff
        }
        return diff != 0;
    }
};