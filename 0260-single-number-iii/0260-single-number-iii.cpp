class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> list;
        vector<int>res;
        for(int a: nums){
            list[a]++;
        }
        for(int a : nums){
            if(list[a] == 1){
                res.push_back(a);
            }
        }
        return res;
    }
};