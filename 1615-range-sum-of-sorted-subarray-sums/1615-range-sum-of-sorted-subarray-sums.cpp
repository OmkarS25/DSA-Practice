class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // int arr[n * (n+1) / 2];
        vector<int> arr(n * (n+1) / 2, 0);
        for(int i=0, k=0; i<n; i++){
            for(int s=0, j=i; j<n; j++){
                s += nums[j];
                arr[k++] = s;
            }
        }
        // sort(arr, arr+n*(n+1)/2);
        sort(arr.begin(), arr.end());
        int ans = 0; 
        const int mod = 1e9 + 7;
        for(int i = left-1; i<right; i++){
            ans = (ans + arr[i]) % mod;
        }
        return ans;
    }
};