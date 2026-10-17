class Solution {
public:
    int minSwaps(vector<int>& nums) {
        unordered_map<int, int> mp; // i will store initial indexing of numbers as they are distinct
        vector<vector<int>> store(81);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]] = i;
            string curr = to_string(nums[i]);
            int sum = 0;
            for (int j = 0; j < curr.size(); j++) {
                sum += (curr[j] - '0');
            }
            store[sum].push_back(nums[i]);
        }
        vector<int> result;
        for (int i = 0; i < 81; i++) {
            if (store[i].size() != 0) {
                sort(store[i].begin(), store[i].end());
                result.insert(result.end(), store[i].begin(), store[i].end());
            }
        }
        // now we will compare this sorted with original map mp to get their
        // index and new index compared and change them
        int swaps = 0;
        for (int i = 0; i < result.size(); i++) {
            int currr = result[i];
            int index = mp[currr];
            if (index != i) {
                swaps++;
                int original = nums[i];
                swap(nums[i], nums[index]);
                mp[original] = index;
                mp[currr] = i;
            }
        }
        return swaps;
    }
};