class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        string res = "";
        sort(s.begin(), s.end());
        int n = s.size();
        string first = s[0], last = s[n-1];
        for(int i=0; i<min(first.size(), last.size()); i++){
            if(first[i] != last[i]){
                return res;
            }
            res += first[i];
        }
        return res;
    }
};