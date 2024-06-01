class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> list;
        int maxfreq = 0, res = 0;
        for(int a: nums){
            list[a]++;
            maxfreq = max(maxfreq, list[a]);
        }
        for(int a: nums){
            if(list[a] == maxfreq) res++;
        }
        return res;
    }
};