class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string digits = "123456789";
        vector<int> res;

        int n = to_string(low).size();
        int m = to_string(high).size();

        for (int length = n; length <= m; length++) {
            for (int i = 0; i < 10 - length; i++) {
                int num = stoi(digits.substr(i, length));

                if (low <= num && num <= high) {
                    res.push_back(num);
                }
            }
        }

        return res;
    }
};