// class Solution {
// public:
//     vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
//         sort(nums.begin(), nums.end(), [&mapping](int a, int b){
//             int a_val = 0, b_val = 0;
//             while(a){
//                 a_val *= 10;
//                 a_val += a%10;
//                 a /= 10;
//             }
//             while(a_val){
//                 a *= 10;
//                 a += mapping[a_val%10];
//                 a_val /= 10;
//             }
//             while(b){
//                 b_val *= 10;
//                 b_val += b%10;
//                 b /= 10;
//             }
//             while(b_val){
//                 b *= 10;
//                 b += mapping[b_val%10];
//                 b_val /= 10;
//             }
//             return a < b;
//         });
//         return nums;
//     }
// };

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        auto transform = [&mapping](int num) -> int {
            string mappedValue;
            if (num == 0) {
                mappedValue += mapping[0] + '0';
            } else {
                while (num > 0) {
                    mappedValue += mapping[num % 10] + '0';
                    num /= 10;
                }
                reverse(mappedValue.begin(), mappedValue.end());
            }
            return stoi(mappedValue);
        };
        sort(nums.begin(), nums.end(), [&mapping, &transform](int a, int b) {
            return transform(a) < transform(b);
        });
        
        return nums;
    }
};
