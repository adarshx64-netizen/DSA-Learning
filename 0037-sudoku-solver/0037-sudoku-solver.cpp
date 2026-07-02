// TC -> O((^(n^2))), in worst case, for each cell in the n^2 board, we have 9 possible numbers
// SC -> O(1)

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    bool solve(vector<vector<char>>& board) {

        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {

                // If current cell is empty
                if(board[i][j] == '.') {

                    // Try all possible digits
                    for(char c = '1'; c <= '9'; c++) {

                        // Check if placing c is valid here
                        if(isValid(board, i, j, c)) {
                            board[i][j] = c;    // place c tentatively

                            // Recur to solve rest of the board
                            if(solve(board) == true) return true; // If successful, return true
                            else board[i][j] = '.';  // If not successful, remmove and backtrack
                        }
                    }
                    // If no digit can be placed here, return false to backtrack
                    return false;
                }
            }
        }
        // If all cells are filled crrectly, return true
        return true;
    }

    // Function to check if placing character c at board[row][col] is valid
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {

        for(int i = 0; i < 9; i++) {

            if(board[i][col] == c) return false;    // If character already exists in column, not valid
            if(board[row][i] == c) return false;    // If character already exists in row, not valid
            if(board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c) return false;  // If character found in 3x3 sub-box, not valid
        }
        // If all checks passed, placement is valid
        return true;
    }

};