class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<bool>> isvis(n, vector<bool>(m));
        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        vector<int> answer;
        int row = 0;
        int col = 0;
        int direction = 0;
        while (answer.size() < n * m) {
            answer.push_back(matrix[row][col]);
            isvis[row][col] = true;
            if (answer.size() == n * m) {
                break;
            }

            int nextRow = row + directions[direction][0];
            int nextCol = col + directions[direction][1];
            if (nextRow < 0 || nextRow >= n || nextCol < 0 || nextCol >= m
                || isvis[nextRow][nextCol]) {
                direction = (direction + 1) % 4;
                nextRow = row + directions[direction][0];
                nextCol = col + directions[direction][1];
            }

            row = nextRow;
            col = nextCol;
        }

        return answer;
    }
};
