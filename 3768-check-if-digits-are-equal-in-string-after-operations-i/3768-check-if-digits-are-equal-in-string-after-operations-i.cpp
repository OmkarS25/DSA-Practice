class Solution {
public:
    bool hasSameDigits(string s) {
        while(s.size()>2){
            string temp="";
            for(int i=0;i<s.size()-1;i++){
                int x = s[i]-'0';
                int y = s[i+1]-'0';
                int z = (x+y) % 10;
                temp.push_back(z+'0');
            }
            s=temp;
        }
        if(s.size()<2) return false;
        return s[0]==s[1];
    }
};