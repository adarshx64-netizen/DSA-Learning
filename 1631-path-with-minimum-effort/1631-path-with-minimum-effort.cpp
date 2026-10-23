class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        // Min-heap: {effort, {row, col}}
        // The cell with the minimum effort is processed first.
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});

        // dist[r][c] stores the minimum effort needed to reach cell (r, c).
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;

        // Directions: up, left, down, right.
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};

        while(!pq.empty()) {
            auto it = pq.top();
            pq.pop();

            int diff = it.first;
            int row = it.second.first;
            int col = it.second.second;

            // Skip an outdated entry if a better effort is already found.
            if(diff > dist[row][col]) continue;

            // Destination reached with minimum possible effort.
            if(row == n - 1 && col == m - 1) return diff;

            // Explore the four neighboring cells.
            for(int i = 0; i < 4; i++) {
                int newr = row + dr[i];
                int newc = col + dc[i];

                // Check whether the neighbor is inside the grid.
                if(0 <= newr && newr < n &&
                    0 <= newc && newc < m) {

                    // Effort of a path is the maximum height difference
                    // encountered along that path.
                    int newEffort = max(
                        abs(heights[newr][newc] - heights[row][col]),
                        diff
                    );

                    // Update if this path gives a smaller effort.
                    if(newEffort < dist[newr][newc]) {
                        dist[newr][newc] = newEffort;
                        pq.push({newEffort, {newr, newc}});
                    }
                }
            }
        }

        return 0;
    }
};