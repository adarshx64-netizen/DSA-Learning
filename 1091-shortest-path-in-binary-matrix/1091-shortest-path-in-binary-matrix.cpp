class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        // Source and destination must be open cells (value 0)
        if(mat[0][0] == 1 || mat[n-1][m-1] == 1) {
            return -1;
        }

        // Queue stores {distance, {row, column}}
        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});  // Path length includes the source cell

        // Distance of every cell is initially infinity
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 1;

        // If the matrix contains only one cell
        if(n == 1 && m == 1) return 1;

        // 8 directions: up, down, left, right, and 4 diagonals
        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dc[] = {-1,  0,  1, -1, 1, -1, 0, 1};

        // Apply BFS to find the shortest path
        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            int d = it.first;
            int r = it.second.first;
            int c = it.second.second;

            // Explore all 8 neighbouring cells
            for(int i = 0; i < 8; i++) {
                int newr = r + dr[i];
                int newc = c + dc[i];

                // Check boundaries, open cell, and shorter distance
                if(newr >= 0 && newr < n &&
                   newc >= 0 && newc < m &&
                   mat[newr][newc] == 0 &&
                   d + 1 < dist[newr][newc]) {

                    // Update the shortest distance
                    dist[newr][newc] = d + 1;

                    // Destination reached
                    if(newr == n-1 && newc == m-1) {
                        return d + 1;
                    }

                    // Add the neighbour to the queue
                    q.push({d + 1, {newr, newc}});
                }
            }
        }

        // Destination is unreachable
        return -1;
    }
};

// Time Complexity: O(n * m)
// Space Complexity: O(n * m)