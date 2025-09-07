class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res;
        for(int i=-n/2; i<=n/2; i++){
            if(i==0){
                if(n%2 != 0) res.push_back(0);
            }
            else res.push_back(i);
        }
        return res;
    }
};