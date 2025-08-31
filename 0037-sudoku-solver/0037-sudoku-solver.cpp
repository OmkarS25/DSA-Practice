class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>>& board, char value) {
        for(int i=0; i<9; i++) {
            //row check
            if(board[row][i] == value)
                return false;
            
            //col check
            if(board[i][col] == value) 
                return false;

            //3*3 box check
            if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)] == value) 
                return false;
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                //check for empty cell
                if(board[i][j] == '.') {
                    //try to fill with values ranging from 1 to 9
                    for(char val = '1'; val<='9'; val++) {
                        //check for safety
                        if(isSafe(i,j, board, val)) {
                            board[i][j] = val; //insert
                            if(solve(board)) return true;  //recursion sambal lega
                            else board[i][j] = '.'; //backtrack
                        }
                    }
                    //if 1 se 9 tak koi bhi value se solution nahi nikla ,current cell pr, 
                    //that means piche kahin pr galti hai, go back by returning false
                    return false;
                }
            }
        }
        return true; //all cells filled 
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};