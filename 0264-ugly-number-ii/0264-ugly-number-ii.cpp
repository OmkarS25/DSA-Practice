class Solution {
public:
    // int anotherSolution(int n){
    //     if(n==1) return 1;
    //     int count = 1, i=1;
    //     while(true){
    //         long long int a = 2*i, b = 3*i, c = 5*i;
    //         count++;
    //         if(count == n) return a;
    //         if(a != b) count++;
    //         if(b != c) count++;
    //     }
    //     return -1;
    // }
    int nthUglyNumber(int n) {
        if (n == 1) return 1;
        vector<long long int> nums(n);
        nums[0] = 1;
        int index2 = 0, index3 = 0, index5 = 0;
        long long int next_multiple_of_2 = 2, next_multiple_of_3 = 3, next_multiple_of_5 = 5;
        for (int i = 1; i < n; i++) {
            long long int next_ugly = min(next_multiple_of_2, min(next_multiple_of_3, next_multiple_of_5));
            nums[i] = next_ugly;
            if (next_ugly == next_multiple_of_2) next_multiple_of_2 = nums[++index2] * 2;
            if (next_ugly == next_multiple_of_3) next_multiple_of_3 = nums[++index3] * 3;
            if (next_ugly == next_multiple_of_5) next_multiple_of_5 = nums[++index5] * 5;
        }
        return nums[n-1];
    }
};