class Solution {
public:
    int XORSum(vector<int>& nums, int index, int currentXOR) {
        // Return currentXOR when all elements in nums are already considered
        if (index == nums.size()) return currentXOR;

        // Calculate sum of subset xor with current element
        int withElement = XORSum(nums, index + 1, currentXOR ^ nums[index]);

        // Calculate sum of subset xor without current element
        int withoutElement = XORSum(nums, index + 1, currentXOR);

        // Return sum of xor totals
        return withElement + withoutElement;
    }

    int subsetXORSum(vector<int>& nums) {
        // return subsets(nums,{0},0);
        return XORSum(nums, 0, 0);
    }

    // int subsets(vector<int> nums, vector<int> res, int index){
    //     if(index >= nums.size()) return 0;
    //     int sum = 0;
    //     sum += subsets(nums, res, index+1);
    //     res.push_back(nums[index]);
    //     sum += subsets(nums, res, index+1);
    //     for(int a : res){
    //         res[0] = res[0] ^ a;
    //     }
    //     sum += res[0];
    //     return sum;
    // }

};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();