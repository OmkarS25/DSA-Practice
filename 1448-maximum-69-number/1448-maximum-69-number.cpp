class Solution {
public:
    int maximum69Number (int num) {
        string n = to_string(num);
        for(int i=0; i<n.size(); i++){
            if(n[i] == '6') {
                n[i] = '9';
                break;
            }
        }
        return stoi(n);
    }
};

#pragma GCC optimize ("O3", "unroll-loops")
static const int _=[]()noexcept{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    return 0;
}();