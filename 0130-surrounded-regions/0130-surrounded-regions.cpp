class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && board[i][j] == 'O' && ((i == 0 || i == n-1) || (j == 0 || j == m-1))) {
                    vis[i][j] = 1;
                    dfs(i, j, board, vis, drow, dcol);
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!vis[i][j] && board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(int r, int c, vector<vector<char>>& board, vector<vector<int>>& vis, int drow[], int dcol[]) {
        vis[r][c] = 1;

        int n = board.size();
        int m = board[0].size();

        // visit nbr
        for(int i = 0; i < 4; i++) {
            int nr = r + drow[i];
            int nc = c + dcol[i];

            if(0 <= nr && nr < n && 0 <= nc && nc < m &&
            !vis[nr][nc] && board[nr][nc] == 'O') {

                vis[nr][nc] = 1;
                dfs(nr, nc, board, vis, drow, dcol);
            }
        }
    }
};