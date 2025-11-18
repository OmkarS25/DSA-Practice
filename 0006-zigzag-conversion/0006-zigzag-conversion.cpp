class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;

        vector<string> zigzag(numRows, "");
        int i = 0, row = 0;

        while(i < s.size()){
            // Downward direction
            while(row < numRows && i < s.size()){
                zigzag[row++] += s[i++];
            }
            row -= 2; // Adjust row to start moving upward
            // Upward direction
            while(row > 0 && i < s.size()){
                zigzag[row--] += s[i++];
            }
        }
        string result;
        for(const string& str : zigzag){
            result += str;
        }
        return result;
    }
};