class Solution {
public:
    void addRE(string& num1, int p1, string& num2, int p2, int carry, string& ans){
        // base case
        if(p1 < 0 && p2 < 0 && carry == 0) return;

        // ek case solve karunga
        int n1 = (p1 >= 0 ? num1[p1] : '0') - '0';
        int n2 = (p2 >= 0 ? num2[p2] : '0') - '0';
        int csum = n1 + n2 + carry;
        carry = csum / 10;
        char digit = (csum % 10) + '0';
        ans = digit + ans;
        // recursive call
        addRE(num1, p1 - 1, num2, p2 - 1, carry, ans);
    }
    string addStrings(string num1, string num2) {
        string ans = "";
        addRE(num1, num1.size() - 1, num2, num2.size() - 1, 0, ans);
        return ans;
    }
};