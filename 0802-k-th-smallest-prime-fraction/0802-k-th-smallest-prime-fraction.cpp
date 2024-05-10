class Solution {
public:
    static bool customcomp(const vector<int>& a, const vector<int>& b) {
        return double(a[0]) / a[1] < double(b[0]) / b[1];
    }
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<vector<int>> res;
        int n=arr.size();
        for (int j = n - 1; j > 0; j--) {
            for (int i = 0; i < j; i++) {
                res.push_back({arr[i], arr[j]});
            }
        }
        sort(res.begin(), res.end(), customcomp);
        return res[k-1];
    }
};