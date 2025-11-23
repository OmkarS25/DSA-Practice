class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        int total = 0, m1 = 1e5, m2 = 1e5, m = 0;
        for(auto& i : nums){
            total += i;
            m = i % 3;
            if(m == 1){
                m2 = min(m2, m1 + i);
                m1 = min(m1, i);
            }
            else if(m == 2){
                m1 = min(m1, m2 + i);
                m2 = min(m2, i);
            }
        }
        m = total % 3;
        if(m == 1) total -= m1;
        else if(m == 2) total -= m2;
        return total;
    }
};