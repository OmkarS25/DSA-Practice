class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int count = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            int val = arr[i];
            
            for (int k = i + 1; k < arr.size(); k++) {
                val ^= arr[k];
                
                if (val == 0) {
                    count += (k - i);
                }
            }
        }
        
        return count;
    }
};


// Loop in loop in loop approach
// class Solution {
// public:
//     int countTriplets(vector<int>& arr) {
//         int count = 0, n = arr.size();
//         for(int i=0; i<n; i++){
//             for(int j=i+1; j<n; j++){
//                 int a = 0;
//                 for(int k=i; k<j; k++){
//                     a ^= arr[k];
//                 }
//                 int b = 0;
//                 for(int k=j; k<n; k++){
//                     b ^= arr[k];
//                     if(a==b) count++;
//                 }
//             }
//         }
//         return count;
//     }
// };