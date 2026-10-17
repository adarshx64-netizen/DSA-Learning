class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // Directions to move: up, left, down, right
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};

        // Track visited cells
        vector<vector<int>> vis(n, vector<int>(m, 0));

        // Traverse the entire matrix to find boundary O cells
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                // Start DFS from an unvisited boundary O
                if(!vis[i][j] && grid[i][j] == 1 &&
                   ((i == 0 || i == n-1) || (j == 0 || j == m-1))) {

                    // vis[i][j] = 1;
                    dfs(i, j, drow, dcol, grid, vis);
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(vis[i][j] == 0 && grid[i][j] == 1) ans++;
            }
        }

        return ans;
    }

    void dfs(int r, int c, int drow[], int dcol[], vector<vector<int>>& grid, vector<vector<int>>& vis) {
        vis[r][c] = 1;
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0; i < 4; i++) {
            int nr = r + drow[i];
            int nc = c + dcol[i];

            if(0 <= nr && nr < n && 0 <= nc && nc < m && !vis[nr][nc] && grid[nr][nc] == 1) {
                dfs(nr, nc, drow, dcol, grid, vis);
            }
        }
    }
};