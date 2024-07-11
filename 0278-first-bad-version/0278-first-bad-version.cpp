// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i=1, j=n, last_bad = 0;
        while(i<=j){
            int mid = i + ((j - i) / 2);
            if(isBadVersion(mid)){
                last_bad = mid;
                j = mid-1;
            }
            else i = mid+1;
        }
        return last_bad;
    }
};