class Solution {
public:
    int numSub(string s) { 
        long long n = 0, ans = 0; 
        for(int i=0; i<s.size(); i++){
            if(s[i]=='0'){
                ans += n*(n+1)/2;
                n = 0;
            }
            else n++;
        }
        ans += n*(n+1)/2;
        return ans%1000000007;
    }
};