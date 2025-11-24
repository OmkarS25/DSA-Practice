class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector<bool> ans;
        int rem = 0;
        for(int i : nums){
            if(rem == 0) rem += i;
            else rem = (rem*2 + i)%5;
            ans.push_back(rem?0:1);
        }
        return ans;
    }
};