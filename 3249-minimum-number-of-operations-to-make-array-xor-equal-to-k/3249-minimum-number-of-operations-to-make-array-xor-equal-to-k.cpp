class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int res = 0, count =0;
        for(int i : nums) res = res^i;
        while(k || res){
            if((k%2) != (res%2)) count++;
            k >>=1;
            res >>=1;
        }
        return count;
    }
};