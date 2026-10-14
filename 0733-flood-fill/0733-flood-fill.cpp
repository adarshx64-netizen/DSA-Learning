class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int px = image[sr][sc];
        image[sr][sc] = color;
        bfs(image, sr, sc, color, px);
        return image;
    }

    void bfs(vector<vector<int>> &image, int &sr, int &sc, int &color, int &px) {
        int n = image.size();
        int m = image[0].size();

        queue<pair<int, int>> q;
        q.push({sr, sc});

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vis[sr][sc] = 1;

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            // visit nbrs
            for(int delcol = -1; delcol <= 1; delcol++) {
                for(int delrow = -1; delrow <= 1; delrow++) {

                    // for skipping diagonal nbrs
                    if(abs(delrow) == abs(delcol)) continue;

                    int nr = r + delrow;
                    int nc = c + delcol;

                    if((0 <= nr && nr < n) && (0 <= nc && nc < m) &&
                       (image[nr][nc] == px) && !vis[nr][nc]) {

                        vis[nr][nc] = 1;
                        q.push({nr, nc});
                        image[nr][nc] = color;
                    }
                }
            }
        }
    }
};