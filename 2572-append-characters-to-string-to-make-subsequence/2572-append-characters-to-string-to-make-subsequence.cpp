class Solution {
public:
    int appendCharacters(string s, string t) {
        int slen = s.length(), tlen = t.length(), j = 0;
        for(int i=0; i<slen; i++){
            if(s[i] == t[j]){
                if(j<tlen) j++;
                else break;
            }
        }
        return (tlen - j);
    }
};