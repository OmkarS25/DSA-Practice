class Solution {
public:    
    bool solve(string s, string temp, int ans, int& target){
        if( s == ""){
            if(ans == target) return true;
            return false;
        }
        int len = s.size();
        bool res = true;

        for(int i = 1 ; i<= s.size();i++){
            int abc = stoi(s.substr(0,i));
            res = solve(s.substr(i,len-1), (temp+s.substr(0,i)), abc+ans, target);
            if(res == true) return true;
        }
        return res;
    }
    int punishmentNumber(int n) {
        int ans = 1;
        for(int i = 2 ;i<= n;i++) 
            if(solve(to_string(i*i), "", 0, i) ) ans +=(i*i);
        return ans;
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();