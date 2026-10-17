class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        // -1 means unvisited, 0 and 1 represent two different colors
        vector<int> vis(n, -1);

        // Check every component, including disconnected components
        for(int i = 0; i < n; i++) {
            if(vis[i] == -1) {

                // If BFS/DFS finds a conflict, the graph is not bipartite
                // if(bfs(i, graph, vis) == false) return false;
                if(dfs(i, graph, vis, 0) == false) return false;
            }
        }

        // All components can be colored using two colors
        return true;
    }

    bool dfs(int node, vector<vector<int>>& graph, vector<int>& vis, int color) {
        vis[node] = color;

        for(auto nbr : graph[node]) {

            if(vis[nbr] == -1) {
                if(dfs(nbr, graph, vis, !color) == false) {
                    return false;
                }
            }

            else {
                if(vis[nbr] == vis[node]) {
                    return false;
                }
            }
        }

        return true;
    }

    bool bfs(int start, vector<vector<int>>& graph, vector<int>& vis) {
        queue<int> q;

        // Start BFS from the given node and assign color 0
        q.push(start);
        vis[start] = 0;

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            // Visit all neighbors of the current node
            for(auto nbr : graph[node]) {

                // If the neighbor is unvisited, assign the opposite color
                if(vis[nbr] == -1) {
                    q.push(nbr);
                    vis[nbr] = !vis[node];
                }

                // If already visited, check whether both have the same color
                else {
                    if(vis[nbr] == vis[node]) {
                        return false;  // Same-colored adjacent nodes
                    }
                }
            }
        }

        // No coloring conflict was found in this component
        return true;
    }
};