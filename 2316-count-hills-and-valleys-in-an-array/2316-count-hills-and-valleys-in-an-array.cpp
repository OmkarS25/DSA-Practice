class Solution {
public:
    int countHillValley(vector<int>& v) {
        const int n = v.size();
        int high = 0, low = 0, cnt = 0;

        for(int i = 1; i < n; ++i){
            if(v[i] != v[i-1]){
                bool state = (v[i] > v[i-1]);

                if(state && low) cnt++;
                else if(!state && high) cnt++;

                high = state;
                low = !state;
            }
        }

        return cnt;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();