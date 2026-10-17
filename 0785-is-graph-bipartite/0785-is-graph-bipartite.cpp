class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> vis(n, -1);

        for(int i = 0; i < n; i++) {
            if(vis[i] == -1) {
                if(bfs(i, graph, vis) == false) return false;
            }
        }

        return true;
    }

    bool bfs(int start, vector<vector<int>>& graph, vector<int>& vis) {
        queue<int> q;
        q.push(start);
        vis[start] = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            // visit nbrs
            for(auto nbr : graph[node]) {
                // if nbr is not visited
                if(vis[nbr] == -1) {
                    q.push(nbr);
                    vis[nbr] = !vis[node];
                }
                // if already visited
                // else {
                    if(vis[nbr] == vis[node]) {
                        return false;
                    }
                // }
            }
        }

        return true;
    }
};