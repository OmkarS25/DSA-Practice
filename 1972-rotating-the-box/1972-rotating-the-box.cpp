class Solution
{
public:
    // rotateTheBox - stub provided by LeetCode.
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        // Base case - matrix size 1x1.
        if (box.size() == 1ul && box.front().size() == 1ul)
            return box;

        // Go over rows.
        size_t row;
        int    col;
        size_t nextStoneOrObstacle;
        for (row = 0ul; row != box.size(); ++row)
        {
            // Go over columns from last to first.
            nextStoneOrObstacle = box.front().size();
            for (col = box.front().size()-1ul; col != -1; --col)
                switch (box[row][col])
                {
                case '#':
                    // Move stone to just before next obstacle or other stone.
                    box[row][col] = '.';
                    box[row][--nextStoneOrObstacle] = '#';
                    break;
                case '*':
                    // Encountered obstacle - this is now the next obstacle or
                    // stone.
                    nextStoneOrObstacle = col;
                }
        }

        // Rotate matrix clockwise.
        const size_t rowsMinus1 = box.size()-1ul;
        if (box.size() == box.front().size())
        {
            // Square matrix - rotate inplace by mirroring lines and transposing.
            const size_t halfRows = box.size() >> 1ul;
            for (row = 0ul; row != halfRows; ++row)
                box[row].swap(box[rowsMinus1-row]);
            for (row = 1ul; row != box.size(); ++row)
                for (col = 0; col != row; ++col)
                    swap(box[col][row], box[row][col]);
            return box;
        }

        // Non-square matrix - create new rotated matrix.
        vector<vector<char>> result(box.front().size(),
                                    vector<char>(box.size()));
        for (row = 0ul; row != box.size(); ++row)
            for (col = 0; col != box.front().size(); ++col)
                result[col][rowsMinus1 - row] = box[row][col];
        return result;
    }
};

static const int speedup = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();