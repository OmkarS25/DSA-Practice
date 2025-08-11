class Solution {
public:
int mod=1e9 + 7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers, ans;

        for(int i=0;i<32;i++){
            if((n & (1<<i)) !=0) powers.push_back(1<<i);
        }

        for(auto q:queries){
            int start=q[0], end=q[1]; 
            long long pro=1;

            for(int i=start;i<=end;i++){
                pro=(pro*powers[i])%mod;
            }
            ans.push_back(pro);
        }

        return ans;
    }
};