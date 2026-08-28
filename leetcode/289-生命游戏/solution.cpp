class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int rows = board.size();
        int cols = board[0].size();

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                int liveNeighbors = 0;
                for (int dr = -1; dr <= 1; ++dr) {
                    for (int dc = -1; dc <= 1; ++dc) {
                        if (dr == 0 && dc == 0) {
                            continue;
                        }

                        int nextRow = row + dr;
                        int nextCol = col + dc;
                        if (nextRow >= 0 && nextRow < rows && nextCol >= 0 && nextCol < cols
                            && (board[nextRow][nextCol] == 1 || board[nextRow][nextCol] == 3)) {
                            ++liveNeighbors;
                        }
                    }
                }

                if (board[row][col] == 1 && (liveNeighbors < 2 || liveNeighbors > 3)) {
                    board[row][col] = 3;
                } else if (board[row][col] == 0 && liveNeighbors == 3) {
                    board[row][col] = 2;
                }
            }
        }

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                board[row][col] = board[row][col] == 1 || board[row][col] == 2;
            }
        }
    }
};
