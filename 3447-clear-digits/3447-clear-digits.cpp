class Solution {
public:
    string clearDigits(string s) {
        string ans = "";
        int index = -1;
        for(auto ch : s){
            if(ch >= 'a' && ch <= 'z'){
                ans = ans + ch;
                ++index;
            }
            else if((ch >= '0' && ch <='9') && index >=0){
                ans.erase(ans.begin() + index);
                --index;
            }
        }
        return ans;
    }
};