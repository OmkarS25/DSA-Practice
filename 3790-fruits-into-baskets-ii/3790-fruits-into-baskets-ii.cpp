class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int count=0;
        for(int i=0; i<fruits.size(); i++){
            int j=0;
            while(j<baskets.size() && fruits[i]>baskets[j]) j++;
         
            if(j==baskets.size()){
                count++;
                continue;
            }
            baskets[j]=0;
        }
        return count;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();