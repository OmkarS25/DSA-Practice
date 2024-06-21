class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int mins) {
        int n = customers.size();
        int totalSatisfied = 0, additionalSatisfied = 0;

        // Calculate the total satisfaction for non-grumpy times
        for (int i = 0; i < n; i++) {
            if (!grumpy[i]) {
                totalSatisfied += customers[i];
            }
        }

        // Calculate the additional satisfaction for the initial window
        int maxAdditionalSatisfied = 0;
        for (int i = 0; i < mins; i++) {
            if (grumpy[i]) {
                maxAdditionalSatisfied += customers[i];
            }
        }

        additionalSatisfied = maxAdditionalSatisfied;

        // Sliding window to find the maximum additional satisfaction
        for (int i = mins; i < n; i++) {
            if (grumpy[i]) {
                additionalSatisfied += customers[i];
            }
            if (grumpy[i - mins]) {
                additionalSatisfied -= customers[i - mins];
            }
            maxAdditionalSatisfied = max(maxAdditionalSatisfied, additionalSatisfied);
        }

        // Return the sum of non-grumpy satisfaction and the maximum additional satisfaction in any window
        return totalSatisfied + maxAdditionalSatisfied;
    }
};


// My code but it is not running properly.
// class Solution {
// public:
//     int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int mins) {
//         int n = customers.size();
//         if(n <= mins){
//             int sum = 0;
//             for(int a : customers){
//                 sum += a;
//             }
//             return sum;
//         }
//         int index = 0, diff = INT_MIN;
//         int max_sum_grumpy = 0, max_sum_no_grumpy = 0;
//         // Calculating the first mins for sliding window
//         for(int i=0; i<mins; i++){
//             max_sum_no_grumpy += customers[i];
//             if(!grumpy[i]) max_sum_grumpy += customers[i];
//             if((max_sum_no_grumpy - max_sum_grumpy) >= diff){
//                 diff = max_sum_no_grumpy - max_sum_grumpy;
//                 index = i-mins+1;
//             }
//         }

//         // The main slinding window logic
//         for(int i=mins; i<n; i++){
//             max_sum_no_grumpy += customers[i] - customers[i-mins];
//             if(!grumpy[i]) max_sum_grumpy += customers[i];
//             if(!grumpy[i-mins]) max_sum_grumpy -= customers[i-mins];
//             if((max_sum_no_grumpy - max_sum_grumpy) > diff){
//                 diff = max_sum_no_grumpy - max_sum_grumpy;
//                 index = i-mins+1;
//             }
//         }

//         // Making the grumpy array
//         for(int i=0; i<mins, index<n; i++){
//             grumpy[index] = 0;
//             index++;
//         }

//         // Calculate the max total
//         int res = 0;
//         for(int i=0; i<n; i++){
//             if(!grumpy[i]) res += customers[i];
//         }
//         return res;
//     }
// };

// Testcases
// 1. customers = [10,1,7] grumpy = [0,0,0] minutes = 2
// 2. customers = [8,8] grumpy = [1,0] minutes = 2
// 3. customers = [4,10,10] grumpy = [1,1,0] minutes = 2
// 4. customers = [9,10,4,5] grumpy = [1,0,1,1] minutes = 1