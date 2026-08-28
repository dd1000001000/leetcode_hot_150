class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool rowUsed[9][9] = {};
        bool colUsed[9][9] = {};
        bool boxUsed[9][9] = {};

        for (int row = 0; row < 9; ++row) {
            for (int col = 0; col < 9; ++col) {
                if (board[row][col] == '.') {
                    continue;
                }

                int number = board[row][col] - '1';
                int box = (row / 3) * 3 + col / 3;
                if (rowUsed[row][number] || colUsed[col][number] || boxUsed[box][number]) {
                    return false;
                }

                rowUsed[row][number] = true;
                colUsed[col][number] = true;
                boxUsed[box][number] = true;
            }
        }

        return true;
    }
};
