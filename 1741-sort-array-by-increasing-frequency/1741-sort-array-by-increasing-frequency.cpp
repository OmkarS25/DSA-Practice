class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> list;
        for(int a: nums){
            list[a]++;
        }
        // sort(nums.begin(), nums.end(), customcomp);
        sort(nums.begin(), nums.end(), [&list] (int a, int b){
            if(list[a] != list[b]){
                return list[a] < list[b];
            }
            return a > b;
        });
        return nums;
    }
};