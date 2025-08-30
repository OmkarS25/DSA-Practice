class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Row & Col Checking
        for(int i=0; i<9; i++){
            bool rowChecked[9] = {0}, colChecked[9] = {0};
            for(int j=0; j<9; j++){
                char ch = board[i][j];
                if(ch != '.') {
                    if(rowChecked[ch-'1']) return 0;
                    else rowChecked[ch-'1'] = 1;
                }
                ch = board[j][i];
                if(ch != '.') {
                    if(colChecked[ch-'1']) return 0;
                    else colChecked[ch-'1'] = 1;
                }
            }
        }
        // Matrix Checking
        for(int row=0; row<9; row+=3){
            for(int col=0; col<9; col+=3){
                bool Checked[9] = {0};
                for(int i=row; i<row+3; i++){
                    for(int j=col; j<col+3; j++){
                        char ch = board[i][j];
                        if(ch != '.') {
                            if(Checked[ch-'1']) return 0;
                            else Checked[ch-'1'] = 1;
                        }
                    }
                }
            }
        }
        return true;
    }
};