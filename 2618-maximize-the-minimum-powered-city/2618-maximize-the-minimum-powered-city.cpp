class Solution {
    int n;
    long long defaultSweep[100000] = {0};
    long long minusSweep[100000] = {0};
    // If all statins have at least val power, return true
    bool helper(long long val, int r, long long k){
        long long cur = 0;
        for(int i=0; i<n; ++i){
            int right = i + 1 + 2 * r;
            cur += defaultSweep[i] - minusSweep[i];
            if(cur < val){ // put some stations
                long long diff = val - cur;
                if(k < diff) return false;
                k -= diff;
                cur += diff;
                if(right < n) minusSweep[right] = diff;
            } 
            else if(right < n) minusSweep[right] = 0;
        }
        return true;
    }
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        n = stations.size();
        // preprocessing to create defaultSweep
        for(int i=0; i<n; ++i){
            int left = i-r, right = i+r + 1; 
            defaultSweep[left < 0 ? 0 : left] += stations[i];
            if(right < n) defaultSweep[right] -= stations[i];
        }
        // run BS
        long long left = 0, right = 1LL<<34; 
        while(left < right){
            long long mid = (right + left + 1) / 2;
            if(helper(mid, r, k)){ 
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};