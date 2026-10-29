class DisjointSet {
    vector<int> par, size;

public:
    DisjointSet(int n) {
        par.resize(n);
        size.resize(n, 1);

        for(int i = 0; i < n; i++) par[i] = i;
    }

    int findUltPar(int node) {
        if(node == par[node]) return node;

        return par[node] = findUltPar(par[node]);
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUltPar(u);
        int ulp_v = findUltPar(v);

        if(ulp_u == ulp_v) return;

        if(size[ulp_u] > size[ulp_v]) {
            par[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }

        else {
            par[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DisjointSet ds(n);

        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {

                // If two stones share a row or column, merge their components
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    ds.unionBySize(i, j);
                }
            }
        }

        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(ds.findUltPar(i) == i) cnt++;
        }

        // Answer = Total stones - Number of connected components
        return n - cnt;
    }
};