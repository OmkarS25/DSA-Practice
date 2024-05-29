class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int moves = 0;
        while(target > 1){
            if(target&1){
                target--;
            }
            else{
                if(maxDoubles) {
                    target /= 2;
                    maxDoubles--;
                }
                else {
                    moves +=target-1;
                    return moves;
                }
            }
            moves++;
        }
        return moves;
    }
};