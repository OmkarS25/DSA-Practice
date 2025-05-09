static const auto init = [](){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int nNumsSum = 0;
        for(int i : rolls) nNumsSum += i;
        int m=rolls.size();
        int totalLength = n+m;
        int mNumsSum = mean*totalLength - nNumsSum; 
        if(n*6 < mNumsSum || mNumsSum<n) return {};  
        int rem = mNumsSum % n;
        int q   = mNumsSum / n;
        vector<int> res(n,q);
        for(int i=1; i<=rem; i++)res[i]++;
        return res;
    }
};