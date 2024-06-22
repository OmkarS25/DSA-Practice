class Solution {
public:
    int titleToNumber(string columnTitle) {
        int total = 0;
        for(char ch : columnTitle){
            total *= 26;
            total += int(ch - 64);
        }
        return total;
    }
};