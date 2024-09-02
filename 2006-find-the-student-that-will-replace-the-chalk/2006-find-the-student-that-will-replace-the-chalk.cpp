static const auto init = [](){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        unsigned long long int total = 0;
        for(int a : chalk) total += a;
        k = k%total;
        for(int i=0; i<chalk.size(); i++){
            if(k < chalk[i]) return i;
            k -=  chalk[i];
        }
        return 0;  
    }
};