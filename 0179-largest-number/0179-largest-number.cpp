#pragma GCC optimize("O3", "unroll-loops") 
static const auto init = [](){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b){
            string strA = to_string(a);
            string strB = to_string(b);
            return strA + strB > strB + strA;
        });
        if (nums[0] == 0) return "0";
        string res = "";
        for(int n : nums) res += to_string(n);
        return res;
    }
};