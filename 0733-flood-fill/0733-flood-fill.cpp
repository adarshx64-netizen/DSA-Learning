class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        // Store the original color of the starting pixel
        int initialColor = image[sr][sc];

        // Create a copy so that the original image remains unchanged
        vector<vector<int>> ans = image;

        // These arrays represent 4 directions: up, left, down, right
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, -1, 0, 1};

        // Use DFS to change all connected pixels having initialColor
        dfs(sr, sc, image, ans, initialColor, newColor, delRow, delCol);

        // Return the modified image
        return ans;
    }

    void dfs(int row, int col, vector<vector<int>> &image,
             vector<vector<int>> &ans, int initialColor, int newColor,
             int delRow[], int delCol[]) {

        // Change the current pixel to the new color
        ans[row][col] = newColor;

        // Get the number of rows and columns
        int n = image.size();
        int m = image[0].size();

        // Check all 4 neighboring pixels
        for(int i = 0; i < 4; i++) {

            // Calculate the neighbor's row and column
            int nr = row + delRow[i];
            int nc = col + delCol[i];

            // Check whether the neighbor is inside the image,
            // has the original color, and has not already been recolored
            if(0 <= nr && nr < n &&
               0 <= nc && nc < m &&
               image[nr][nc] == initialColor &&
               ans[nr][nc] != newColor) {

                // Mark the neighbor with the new color before DFS
                // This prevents visiting it repeatedly
                ans[nr][nc] = newColor;

                // Explore the neighbor's connected pixels
                dfs(nr, nc, image, ans, initialColor, newColor, delRow, delCol);
            }
        }
    }

    void bfs(vector<vector<int>> &image, int &sr, int &sc,
             int &color, int &px) {

        // Get the number of rows and columns
        int n = image.size();
        int m = image[0].size();

        // Queue stores pixels whose neighbors need to be checked
        queue<pair<int, int>> q;
        q.push({sr, sc});

        // Track which pixels have already been visited
        vector<vector<int>> vis(n, vector<int>(m, 0));
        vis[sr][sc] = 1;

        // Process pixels until the queue becomes empty
        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            // Check all possible neighboring positions
            for(int delcol = -1; delcol <= 1; delcol++) {
                for(int delrow = -1; delrow <= 1; delrow++) {

                    // Skip the center and diagonal positions.
                    // Only up, down, left, and right are allowed.
                    if(abs(delrow) == abs(delcol)) continue;

                    // Calculate the neighbor's position
                    int nr = r + delrow;
                    int nc = c + delcol;

                    // Check boundaries, original color, and visited status
                    if((0 <= nr && nr < n) &&
                       (0 <= nc && nc < m) &&
                       image[nr][nc] == px &&
                       !vis[nr][nc]) {

                        // Mark the pixel as visited
                        vis[nr][nc] = 1;

                        // Add it to the queue for further exploration
                        q.push({nr, nc});

                        // Change its color
                        image[nr][nc] = color;
                    }
                }
            }
        }
    }
};