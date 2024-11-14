class Solution {  
public:  
    int minimizedMaximum(int n, vector<int>& quantities) {  
        int start = 1, end = *max_element(quantities.begin(), quantities.end());  
        while (start <= end) {  
            int mid = start + (end - start) / 2, total = 0;  
            for (int element : quantities) {  
                total += (element + mid - 1) / mid;  
            }
            if (total <= n) end = mid - 1;  
            else start = mid + 1;
        }  
        return start;  
    }  
};

#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("-ffloat-store")
#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);return 0;}();