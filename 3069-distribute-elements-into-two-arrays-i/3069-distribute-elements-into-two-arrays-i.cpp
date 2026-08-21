class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        const int n = nums.size();
        vector<int> arr1 = {nums[0]}, arr2 = {nums[1]};
        int last_arr1 = nums[0], last_arr2 = nums[1];

        for(int i=2; i<n; i++) {
            if(last_arr1 > last_arr2) {
                arr1.push_back(nums[i]);
                last_arr1 = nums[i];
            }
            else {
                arr2.push_back(nums[i]);
                last_arr2 = nums[i];
            }
        }

        // Pre-allocate memory to optimize performance
        arr1.reserve(arr1.size() + arr2.size()); 

        // Concatenate arr2 into arr1
        arr1.insert(arr1.end(), arr2.begin(), arr2.end());
        
        return arr1;
    }
};