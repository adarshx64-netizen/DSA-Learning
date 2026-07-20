class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        k %= (m*n);

        vector<int> temp;
        vector<vector<int>> ans(m, vector<int>(n));

        // Store last k elements
        for (int r = m - 1; r >= 0; r--) {
            for (int c = n - 1; c >= 0; c--) {
                if (k > 0) temp.push_back(grid[r][c]);
                k--;
            }
        }

        reverse(temp.begin(), temp.end());

        // Insert last k element to the start 
        int ind = 0;
        int r = 0, c = 0;
        while(ind < temp.size()) {
            ans[r][c] = temp[ind];

            ind++; c++;

            if(c >= n) {r++; c = 0;}
        }

        // Store remaining element
        int i = 0, j = 0;
        while(r < m) {
            ans[r][c] = grid[i][j];

            c++;
            if(c >= n) {c = 0; r++;}

            j++;
            if(j >= n) {j = 0; i++;}
        }

        return ans;
    }
};