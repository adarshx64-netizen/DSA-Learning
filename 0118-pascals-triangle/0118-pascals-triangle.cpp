class Solution {
public:


// Formula -> ans -> (ans*(row-col))/col;
// in every step ans is multiplied and update
// TC -> O(N)  Sc -> O(1)
vector<vector<int>> generate(int n) {

    return BF(n);
        vector<vector<int>> mat;

        for(int r = 0; r < n; r++){
            vector<int> row;
            int ans = 1;
            row.push_back(1);

            for(int c = 1; c <= r; c++){
                ans = (ans * (r - c + 1)) / c;
                row.push_back(ans);
            }

            mat.push_back(row);
        }

        return mat;
    }

    // TC -> O(N^3), SC -> O(N^2)
    vector<vector<int>> BF(int n) {

        vector<vector<int>> res;

        for(int r = 0; r < n; r++) {

            vector<int> col;

            for(int c = 0; c <= r; c++) {

                col.push_back(ncr(r, c));
            }

            res.push_back(col);
        }

        return res;
    }

    // TC -> O(N)
    int ncr(int r, int c) {
        int res = 1;

        for(int i = 0; i < c; i++) {

            res *= (r - i);
            res /= (i + 1);
        }
        return res;
    }
};