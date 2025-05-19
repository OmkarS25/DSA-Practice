class Solution
{
public:
    string triangleType(vector<int> &nums)
    {
        if ((nums[0] == nums[1]) && (nums[1] == nums[2]))
            return "equilateral";

        if ((nums[0] + nums[1]) > nums[2] && (nums[0] + nums[2]) > nums[1] && (nums[1] + nums[2]) > nums[0])
        {
            if (nums[0] == nums[1] || nums[0] == nums[2] || nums[1] == nums[2])
                return "isosceles";
            else
                return "scalene";
        }
        else
            return "none";
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();