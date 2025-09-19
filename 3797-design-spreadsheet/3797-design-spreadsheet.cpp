class Spreadsheet {
    vector<vector<int>> sheet;

public:
    Spreadsheet(int rows) : sheet(rows, vector<int>(26, 0)) {}

    void setCell(string cell, int value) {
        int col = cell[0] - 'A'; // Column from letter
        int row = stoi(cell.substr(1)) - 1; // Row from number
        sheet[row][col] = value;
    }

    void resetCell(string cell) {
        int col = cell[0] - 'A';
        int row = stoi(cell.substr(1)) - 1;
        sheet[row][col] = 0;
    }

    int getValue(string formula) {
        int ans = 0;
        int plusPos = formula.find('+');

        auto parseOperand = [&](string operand) -> int {
            if (isdigit(operand[0])) return stoi(operand); 
            int col = operand[0] - 'A';
            int row = stoi(operand.substr(1)) - 1;
            return sheet[row][col];
        };

        string operand1 = formula.substr(1, plusPos - 1); 
        string operand2 = formula.substr(plusPos + 1);

        ans += parseOperand(operand1);
        ans += parseOperand(operand2);

        return ans;
    }
};
