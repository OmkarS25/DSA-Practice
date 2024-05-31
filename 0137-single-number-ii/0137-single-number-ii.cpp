class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> list;
        int res = 0;
        for(int a: nums){
            list[a]++;
        }
        for(int a : nums){
            if(list[a] == 1){
                res = a;
            }
        }
        return res;
    }
};