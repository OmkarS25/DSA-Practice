class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count=0, sum=0;
        unordered_map<int,int> map;
        map[0]=1;
        for(int i=0; i<nums.size(); i++){
            sum += nums[i];
            int remainder = sum % k;
            if(remainder < 0){
                remainder += k;
            }
            if(map.find(remainder) != map.end()){
                count += map[remainder];
                map[remainder]++;
            }
            else{
                map[remainder] = 1;
            }
        }
        return count;
    }
};