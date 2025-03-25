class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<vector<int>> merged;
        for(int i=0;i<meetings.size();i++){
            if(merged.empty()) merged.push_back(meetings[i]);
            else{
                if(merged[merged.size()-1][1]>=meetings[i][0]){
                    if(merged[merged.size()-1][1]<meetings[i][1]) merged[merged.size()-1][1]=meetings[i][1];
                }
                else merged.push_back(meetings[i]);
            }
        }
        int out=0;
        for(int i=0;i<merged.size();i++){
            if(i==0) out+=merged[i][0]-1;
            else out+=merged[i][0]-merged[i-1][1]-1;
        }
        out+=days-merged[merged.size()-1][1];
        return out;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();