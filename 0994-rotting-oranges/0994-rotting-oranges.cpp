class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
            }
        }

        // bfs
        int tm = 0;
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, -1, 0, 1};

        int ans = 0;
        while(!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;

            tm = max(tm, t);

            q.pop();

            // visit nbrs
            for(int i = 0; i < 4; i++) {
                int nr = r + drow[i];
                int nc = c + dcol[i];

                if(0 <= nr && nr < n && 0 <= nc && nc < m &&
                vis[nr][nc] != 2 && grid[nr][nc] == 1) {
                    vis[nr][nc] = 2;
                    q.push({{nr, nc}, t+1});
                }
            }
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && vis[i][j] != 2) return -1;
            }
        }

        return tm;
    }
};















