class Solution {
public:
    int sumOfDigits(int n){
        int digs = 0, rem;
        while(n){
            rem = n%10;
            digs += rem;
            n /= 10;
        }
        return digs;
    }

    int countLargestGroup(int n) {
        vector<int> freq(37, 0);
        int maxfreq = 0, cnt = 0;
        for(int i=1; i<=n; i++) freq[sumOfDigits(i)]++;
        for(int i=1; i<37; i++){
            if(freq[i] > maxfreq){
                maxfreq = freq[i];
                cnt = 1;
            }
            else if(freq[i] == maxfreq) cnt++;
        }
        return cnt;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();