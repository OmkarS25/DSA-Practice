class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        // SOLUTION OF TIN LE
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int res = 0, mp[k];
        memset(mp, 0, sizeof(mp));
        mp[0] = 1;
        int sum = 0;
        for(auto& num : nums)
        {
            sum += num;
            int rem = (sum % k + k) % k;
            res += mp[rem]++;
        }
        return res;
    }
};

// class Solution {
// public:
//     int subarraysDivByK(vector<int>& nums, int k) {
//         int count=0, sum=0;
//         unordered_map<int,int> map;
//         map[0]=1;
//         for(int i=0; i<nums.size(); i++){
//             sum += nums[i];
//             int remainder = sum % k;
//             if(remainder < 0){
//                 remainder += k;
//             }
//             if(map.find(remainder) != map.end()){
//                 count += map[remainder];
//                 map[remainder]++;
//             }
//             else{
//                 map[remainder] = 1;
//             }
//         }
//         return count;
//     }
// };