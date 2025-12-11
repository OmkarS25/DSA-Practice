class Solution {
public:
    string addStringsUtil(string &num1, string &num2, int i, int j, int carry) {
        // Base Case
        if (i < 0 && j < 0 && carry == 0) return "";

        // Ek Case Hum Solve Kar Rahe Hain
        int n1 = (i >= 0) ? num1[i] - '0' : 0;
        int n2 = (j >= 0) ? num2[j] - '0' : 0;
        
        int sum = n1 + n2 + carry;
        carry = sum / 10;
        char digit = (sum % 10) + '0';
        // Recursive Call (Adding digits from right side to avoid reversing at the end)
        string ans = addStringsUtil(num1, num2, i - 1, j - 1, carry) + digit;
        return ans;
    }
    
    string addStrings(string num1, string num2) {
        return addStringsUtil(num1, num2, num1.size() - 1, num2.size() - 1, 0);
    }
};