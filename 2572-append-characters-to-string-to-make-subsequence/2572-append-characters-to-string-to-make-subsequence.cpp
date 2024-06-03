class Solution {
public:
    int appendCharacters(string s, string t) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        int slen = s.length(), tlen = t.length(), j = 0;
        for(int i=0; i<slen && j<tlen; i++){
            if(s[i] == t[j]) j++;
        }
        return (tlen - j);
    }
};