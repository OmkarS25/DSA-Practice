class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string res;

        // Handle sign
        if ((numerator < 0) ^ (denominator < 0)) {
            res += "-";
        }

        // Convert to long long to avoid overflow (e.g., INT_MIN case)
        long long n = llabs((long long)numerator);
        long long d = llabs((long long)denominator);

        // Integer part
        res += to_string(n / d);
        long long remainder = n % d;

        if (remainder == 0) return res;

        res += ".";
        unordered_map<long long, int> remainderIndex;

        while (remainder != 0) {
            if (remainderIndex.count(remainder)) {
                // Insert '(' at the index where this remainder was first seen
                res.insert(remainderIndex[remainder], "(");
                res += ")";
                break;
            }

            remainderIndex[remainder] = res.size();
            remainder *= 10;
            res += to_string(remainder / d);
            remainder %= d;
        }

        return res;
    }
};