class Solution {
public:
    int compareVersion(string version1, string version2) {
        const int n = version1.length(), m = version2.length();
        int i = 0, j = 0;
        while (i < n || j < m) {
            int num1 = 0, num2 = 0;
            while (i < n && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i++] - '0');
            }
            while (j < m && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j++] - '0');
            }
            if (num1 > num2)  return 1;
            else if (num1 < num2) return -1;
            else  i++, j++;
        }
        return 0;
    }
};