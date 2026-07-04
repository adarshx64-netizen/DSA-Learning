class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n, '.');

        for(int i = 0; i < n; i++) board[i] = s;

        solve(ans, board, n, 0);

        return ans;
    }

    void solve(vector<vector<string>>& ans, vector<string> &board, int n, int col) {

        if(col == n) {

            ans.push_back(board);
            return;
        }

        for(int row = 0; row < n; row++) {

            if(isSafe(board, n, col, row)) {

                board[row][col] = 'Q';
                solve(ans, board, n, col + 1);

                // remove last
                board[row][col] = '.';
            }
        }
    }

    bool isSafe(vector<string> &board, int n, int col, int row) {

        // we don't need to check Q horizontal right and vertical up and down direction 
        // b'cuz we place queen only once
        // we only check upper left diagonal, left and lower left diagonal

        int copy_row = row, copy_col = col;

        // check upper diagonal 
        while(row >= 0 && col >= 0) {
            if(board[row][col] == 'Q') return false;
            row--;
            col--;
        }

        // check left
        col = copy_col;
        row = copy_row;
        while(col >= 0) {
            if(board[row][col] == 'Q') return false;
            col--;
        }

        // check lower left diagonal
        col = copy_col;
        row = copy_row;
        while(col >= 0 && row < n) {
            if(board[row][col] == 'Q') return false;
            col--;
            row++;
        } 

        return true;
    }
};