class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // Got the xor of two numbers.
        // int xornum = 0;
        long xornum = 0;
        for(int a: nums){
            xornum ^= a;
        }
        // Now getting LSB which is 1, which will be 
        // the differece between the two numbers.
        // int diff_bit = 1;
        // while(!(xornum & diff_bit)){
        //     diff_bit = diff_bit << 1;
        // }
        int diff_bit = (xornum & xornum-1)^xornum;
        // Calculating the two different numbers.
        int a = 0, b = 0;
        for(int n : nums){
            if(diff_bit & n){
                a = a ^ n;
            }
            else{
                b = b ^ n;
            }
        }
        return {a,b};
    }
};