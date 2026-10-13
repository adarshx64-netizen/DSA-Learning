class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        // Convert it into adj list
        vector<vector<int>> adj(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i != j && isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                }
            }
        }
        vector<int> vis(n);

        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                ans++;
                bfs(i, adj, vis);
            }
        }

        return ans;
    }

    void bfs(int start, vector<vector<int>> &adj, vector<int> &vis) {
        queue<int> q;
        q.push(start);

        vis[start] = 1;
        while(!q.empty()) {
            int curr = q.front();
            q.pop();

            for(auto x : adj[curr]) {
                if(!vis[x]) {
                    vis[x] = 1;
                    q.push(x);
                }
            }
        }
    }
};