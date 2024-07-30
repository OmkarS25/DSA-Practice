auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();

class Solution {
public:
    int minimumDeletions(string s) {
        int ans = 0, count_b = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='b') count_b++;
            else ans = min(ans+1,count_b);
        }
        return ans;
    }
};

