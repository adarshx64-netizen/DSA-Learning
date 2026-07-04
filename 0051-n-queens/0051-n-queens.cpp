// class Solution {
// public:
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>> ans;
//         vector<string> board(n);
//         string s(n, '.');

//         for(int i = 0; i < n; i++) board[i] = s;

//         solve(ans, board, n, 0);

//         return ans;
//     }

//     void solve(vector<vector<string>>& ans, vector<string> &board, int n, int col) {

//         if(col == n) {

//             ans.push_back(board);
//             return;
//         }

//         for(int row = 0; row < n; row++) {

//             if(isSafe(board, n, col, row)) {

//                 board[row][col] = 'Q';
//                 solve(ans, board, n, col + 1);

//                 // remove last
//                 board[row][col] = '.';
//             }
//         }
//     }

//     bool isSafe(vector<string> &board, int n, int col, int row) {

//         // we don't need to check Q horizontal right and vertical up and down direction 
//         // b'cuz we place queen only once
//         // we only check upper left diagonal, left and lower left diagonal

//         int copy_row = row, copy_col = col;

//         // check upper diagonal 
//         while(row >= 0 && col >= 0) {
//             if(board[row][col] == 'Q') return false;
//             row--;
//             col--;
//         }

//         // check left
//         col = copy_col;
//         row = copy_row;
//         while(col >= 0) {
//             if(board[row][col] == 'Q') return false;
//             col--;
//         }

//         // check lower left diagonal
//         col = copy_col;
//         row = copy_row;
//         while(col >= 0 && row < n) {
//             if(board[row][col] == 'Q') return false;
//             col--;
//             row++;
//         } 

//         return true;
//     }
// };


// Optimal Approach
class Solution {
public:
    void solve(int col, vector<string>& board, int n, vector<int>& leftRow, vector<int>& upperDiagonal, vector<int>& lowerDiagonal, vector<vector<string>>& ans) {
        // If all queens are placed
        if (col == n) {
            ans.push_back(board);
            return;
        }

        // Iterate through all rows
        for (int row = 0; row < n; row++) {
            // Check if it's safe to place the queen
            if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 &&
                upperDiagonal[n - 1 + col - row] == 0) {

                // Place the queen
                board[row][col] = 'Q';

                // Mark the row and diagonals
                leftRow[row] = 1;
                lowerDiagonal[row + col] = 1;
                upperDiagonal[n - 1 + col - row] = 1;

                // Recurse to next column
                solve(col + 1, board, n, leftRow, upperDiagonal, lowerDiagonal, ans);

                // Backtrack and remove the queen
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[row + col] = 0;
                upperDiagonal[n - 1 + col - row] = 0;
            }
        }
    }

    // Main function
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
        solve(0, board, n, leftRow, upperDiagonal, lowerDiagonal, ans);
        return ans;
    }
};