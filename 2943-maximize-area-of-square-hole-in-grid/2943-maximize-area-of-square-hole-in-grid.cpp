class Solution {
public:
    int cal(vector<int>& nums){
        int c = 1, ans = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) c++;
            else c = 1;
            ans = max(ans, c);
        }
        return ans;
    }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int side = min(cal(hBars), cal(vBars)) + 1;
        return side * side;
    }
};

// Sorted the horizontal and vertical bars, then found the longest consecutive sequences in each.
// The side of the largest square is determined by the smaller of these sequences plus one, and the area is the square of that.