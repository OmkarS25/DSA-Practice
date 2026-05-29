class Solution {
public:
    int tempFunc(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    int minElement(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            nums[i] = tempFunc(nums[i]);
        }
        return *min_element(nums.begin(), nums.end());
    }
};