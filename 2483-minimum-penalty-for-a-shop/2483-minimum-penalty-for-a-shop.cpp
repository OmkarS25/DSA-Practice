class Solution {
public:
    int bestClosingTime(string& customers) {
        int n = customers.size();
    
        int penalty=0;//without adding y_rem does not matter 
        int minP=penalty, minI=0;
        // cout<<0<<": nn="<<nn<<" penalty="<<penalty<<endl;
        for (int i=1; i<=n; i++) {
            int y=customers[i-1]=='Y'?1:-1;
            penalty-=y;
        // cout<<i<<": nn="<<nn<<" penalty="<<penalty<<endl;
            if (minP>penalty) {
                minP=penalty;
                minI=i;
            }
        }
        // cout<<"minI="<<minI<<endl;
        return minI;
    }
};


