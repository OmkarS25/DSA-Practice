class Solution {
public:
    bool isPossibleDivide(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if (n % groupSize != 0) return false;
        map<int,int> mp;
        for(int a: hand){
            mp[a]++;
        }
        for(auto it : mp){
            if(mp[it.first] > 0){
                for(int i=1; i<groupSize; i++){
                    mp[it.first+i] -= mp[it.first];
                    if(mp[it.first+i] < 0) return false;
                }
            }
        }
        return true;
    }
};