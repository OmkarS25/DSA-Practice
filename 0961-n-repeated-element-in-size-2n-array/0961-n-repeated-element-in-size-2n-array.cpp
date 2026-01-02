class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        const int n = nums.size()/2;
        unordered_map<int, int> mp;
        for(int i: nums) mp[i]++;
        for(auto it : mp){
            if(it.second == n) return it.first;
        }
        return -1;
    }
};