class Solution {
public:
    int maxOperations(string s) {
        int cnt1 = 0, ans = 0;
        bool prev0 = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == '1'){
                cnt1++;
                prev0 = 0;
            }
            else if(!prev0){
                prev0 = 1;
                ans += cnt1;
            }
        }
        return ans;
    }
};