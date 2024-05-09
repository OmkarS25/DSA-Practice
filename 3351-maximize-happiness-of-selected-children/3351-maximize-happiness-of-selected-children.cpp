#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        long long int sum = 0;
        int count = 0;
        sort(happiness.begin(), happiness.end(), greater<int>());
        for(int i=0; i<k; i++){
            if((happiness[i]-count) <= 0) break;
            sum =  sum + (happiness[i]-count);
            count++;
        }
        return sum;
    }
};