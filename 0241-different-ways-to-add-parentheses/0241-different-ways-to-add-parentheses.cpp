// #pragma GCC optimize("O3", "unroll-loops") 
// static const auto init = [](){ 
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cout.tie(0);
//     return 'c';
// }();

class Solution {
public:
    vector<int> diffWaysToCompute(string s) {
        vector<int> res;
        for(int i=0; i<s.size(); i++){
            char oper = s[i];
            if(oper == '+' || oper == '-' || oper =='*'){
                vector<int> s1 = diffWaysToCompute(s.substr(0, i));
                vector<int> s2 = diffWaysToCompute(s.substr(i+1));
                for(int a : s1){
                    for(int b : s2){
                        if(oper == '+') res.push_back(a + b);
                        else if(oper == '-') res.push_back(a - b);
                        else if(oper == '*') res.push_back(a * b);
                    }
                }
            }
        }
        if(res.empty()) res.push_back(stoi(s));
        return res;
    }
};