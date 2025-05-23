class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int def=0, bal=0, start=0;
        for(int i=0; i<gas.size(); i++){
            bal =  bal + gas[i] - cost[i];
            if(bal < 0){
                def += abs(bal);
                start = i+1;
                bal = 0;
            }
        }
        if(bal-def >= 0) return start;
        else return -1;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();