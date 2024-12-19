class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int right = 0, left = 0, res = 0;

        while(left < arr.size()) {
            right = max(right, arr[left]);

            if(right == left) {
                ++right;
                ++res;
            } 
            ++left;
        }

        return res;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();