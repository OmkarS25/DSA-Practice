class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        const int n = nums.size();
        unordered_map<int,int>mp;
        for(auto &it: nums){
            if(it>0) mp[it%value]++;
            else mp[(it%value + value)%value]++;
        }
        int mex = 0;
        while(1){
            int x = mex%value;
            if(mp.find(x)!=mp.end()){
                mp[x]--;
                if(mp[x]==0) mp.erase(x);
                mex++;
            }
            else break;
        }
        return mex;  
    }
};