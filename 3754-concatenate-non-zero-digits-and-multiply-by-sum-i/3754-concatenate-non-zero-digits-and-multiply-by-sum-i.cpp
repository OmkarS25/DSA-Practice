class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum = 0, x = 0, mul_ten = 0;
        while(n){
            int digit = n % 10;
            n /= 10;
            if(digit != 0){
                sum += digit;
                int final_digit = digit;
                for(int i=0; i<mul_ten; i++){
                    final_digit *= 10;
                }
                x += final_digit;
                ++mul_ten;
            }
        }
        long long ans = static_cast<long long>(x) * static_cast<long long>(sum);
        return ans;
    }
};