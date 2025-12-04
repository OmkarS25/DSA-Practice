class Solution {
public:
    static int countCollisions(string& D) {
        int n=D.size(), l=0, r=n-1;
        if (n==1) return 0;
        // Removing Leding L's and Trailing R's
        while (D[l]=='L') l++;
        while (l<r && D[r]=='R') r--;
        if (l>=r) return 0;
        // Count no. of cars in the zone except S cars
        int col=0;
        for( ; l<=r; l++){
           col+=D[l]!='S';
        }
        return col;      
    }
};