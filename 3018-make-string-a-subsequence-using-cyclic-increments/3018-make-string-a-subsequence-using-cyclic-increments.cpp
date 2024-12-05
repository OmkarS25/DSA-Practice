class Solution {
public:
    static bool canMakeSubsequence(string& source, string& target) {
        const int srcLen = source.size(), tgtLen = target.size();
        char targetChar = target[0];
        
        int srcIdx, tgtIdx;
        for(srcIdx = 0, tgtIdx = 0; srcIdx < srcLen && tgtIdx < tgtLen; srcIdx++) {
            char srcChar = source[srcIdx];
            
            if (srcChar == targetChar || 
                srcChar + 1 == targetChar || 
                (srcChar == 'z' && targetChar == 'a')) {
                targetChar = target[++tgtIdx];
            }
        }
        
        return tgtIdx == tgtLen;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();