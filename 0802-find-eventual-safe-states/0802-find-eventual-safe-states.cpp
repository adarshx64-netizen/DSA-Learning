class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V = graph.size();

        vector<int> vis(V, 0);
        vector<int> pathVis(V, 0);

        // Check every node because the graph may be disconnected
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs(i, graph, vis, pathVis);
            }
        }

        vector<int> res;

        // Nodes not involved in a cycle are considered safe
        for(int i = 0; i < V; i++) {
            if(!pathVis[i]) {
                res.push_back(i);
            }
        }

        return res;
    }

    bool dfs(int node, vector<vector<int>> &adj,
             vector<int> &vis, vector<int> &pathVis) {

        vis[node] = 1;      // Mark the node as visited
        pathVis[node] = 1;  // Mark the node in the current DFS path

        for(auto it : adj[node]) {

            // Visit an unvisited neighbour
            if(!vis[it]) {
                if(dfs(it, adj, vis, pathVis)) {
                    return true; // Cycle found
                }
            }

            // Neighbour is already in the current DFS path
            else if(pathVis[it]) {
                return true;
            }
        }

        // Remove the node from the current DFS path
        pathVis[node] = 0;

        return false; // No cycle found from this node
    }
};