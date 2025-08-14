class Solution {
public:
    string largestGoodInteger(string num) {
        int ans = -1;
        for(int i=0; i<num.size()-2; i++){
            if(num[i] == num[i+1] && num[i] == num[i+2]){
                // string temp = string(num[i]) + string(num[i+1]) + string(num[i+2]);
                // string temp = num.substr(i,3);
                // ans = max(ans, stoi(temp));
                ans = max(ans, stoi(num.substr(i,3)));
            }
        }
        return ans==-1 ? "" : (ans==0 ? "000" : to_string(ans));
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();