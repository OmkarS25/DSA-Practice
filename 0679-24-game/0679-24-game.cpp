class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> nums(cards.begin(), cards.end());
        return solve(nums);
    }

private:
    bool solve(vector<double>& cards) {
        if (cards.size() == 1) {
            return fabs(cards[0] - 24) < 0.001;
        }

        int n = cards.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                vector<double> rem;
                for (int k = 0; k < n; k++) {
                    if (k != i && k != j) rem.push_back(cards[k]);
                }

                double a = cards[i], b = cards[j];
                vector<double> comp = {a + b, a - b, b - a, a * b};
                if (fabs(b) > 1e-6) comp.push_back(a / b);
                if (fabs(a) > 1e-6) comp.push_back(b / a);

                for (double res : comp) {
                    rem.push_back(res);
                    if (solve(rem)) return true;
                    rem.pop_back();
                }
            }
        }
        return false;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();