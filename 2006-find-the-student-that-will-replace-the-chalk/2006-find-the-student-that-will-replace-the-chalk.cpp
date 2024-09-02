static const auto init = [](){ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();

// class Solution {
// public:
//     int chalkReplacer(vector<int>& chalk, int k) {
//         int i=0, n=chalk.size();
//         unsigned long long int total = accumulate(chalk.begin(), chalk.end(), 0);
//         k = k%total;
//         while(k){
//             if(k < chalk[i]) return i;
//             k -=  chalk[i];
//             ++i;
//             i = i%n;
//         }
//         return i;  
//     }
// };

class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int initialChalkPieces) {
        long long totalChalkNeeded = 0;
        for (int studentChalkUse : chalk) {
            totalChalkNeeded += studentChalkUse;
        }
        
        int remainingChalk = initialChalkPieces % totalChalkNeeded;
        
        for (int studentIndex = 0; studentIndex < chalk.size(); studentIndex++) {
            if (remainingChalk < chalk[studentIndex]) {
                return studentIndex;
            }
            remainingChalk -= chalk[studentIndex];
        }
        
        return 0;
    }
};