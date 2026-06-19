class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans = 0, total = 0;
        for(int i=0; i<gain.size(); i++){
            total += gain[i];
            ans = max(ans, total);
        }
        return ans;
    }
};