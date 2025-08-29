class Solution {
public:
    long long flowerGame(int n, int m) {
        if(m==1 && n==1) return 0;
        long long odd=(n+1)/2, even=m/2;
        long long odd1=(m+1)/2, even1=n/2;
        return odd1*even1 + odd*even;
    }
};