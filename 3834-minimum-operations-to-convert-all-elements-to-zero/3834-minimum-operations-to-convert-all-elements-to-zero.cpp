class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> s;
        int ans = 0;
        for(auto num: nums){
            while(!s.empty() && s.back() > num){
                s.pop_back();
            }
            if(num == 0) continue;
            if(s.empty() || s.back() < num){
                ans++;
                s.push_back(num);
            }
        }
        return ans;
    }
};