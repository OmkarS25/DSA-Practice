class Solution {
public:
    int numberOfSteps(int num) {
        int moves = 0;
        while(num){
            if(num&1) num--;
            else num /= 2;
            moves++;
        }
        return moves;
    }
};