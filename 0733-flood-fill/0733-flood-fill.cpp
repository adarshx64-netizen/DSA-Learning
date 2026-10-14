class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int px = image[sr][sc];
        image[sr][sc] = color;
        bfs(px, sr, sc, color, image);
        return image;
    }

    void bfs(int px, int sr, int sc, int color, vector<vector<int>>& image) {
        int n = image.size();
        int m = image[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vis[sr][sc] = 1;

        queue<pair<int, int>> q;
        q.push({sr, sc});

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int delcol = -1; delcol <= 1; delcol++) {
                for(int delrow = -1; delrow <= 1; delrow++) {

                    int nr = r + delrow;
                    int nc = c + delcol;

                    int x = abs(nr - r);
                    int y = abs(nc - c);
                    // skip the diagonal 
                    if(x == 1 && y == 1) continue;

                    if((nr >= 0 && nr < n) && (nc >= 0 && nc < m) && (image[nr][nc] == px) && (!vis[nr][nc])) {
                        
                        image[nr][nc] = color;
                        vis[nr][nc] = 1;
                        q.push({nr, nc});
                    }
                }
            }
        }
    }

};

        // // Visit every cell of the grid
        // for(int r = 0; r < n; r++) {
        //     for(int c = 0; c < m; c++) {

        //         // Found a new island (land that is not visited)
        //         if(!vis[r][c] && grid[r][c] == 'L') {
        //             cnt++;  // Count this new island

        //             // Visit all land cells connected to this island
        //             bfs(r, c, grid, vis);
        //         }
        //     }
        // }

        // return cnt;  // Return the total number of islands