// TC: O(n + m), where m = prerequisites.size()
// SC: O(n + m), including the adjacency list
// Auxiliary Space: O(n), for indegree, queue, and result
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<vector<int>> adj(n);

        // Build adjacency list: prerequisite -> course
        for(auto it : prerequisites) {
            adj[it[0]].push_back(it[1]);
        }

        vector<int> inorder(n, 0);

        // Calculate indegree of every node
        for(int i = 0; i < n; i++) {
            for(auto it : adj[i]) {
                inorder[it]++;
            }
        }

        queue<int> q;

        // Add nodes with indegree 0 to the queue
        for(int i = 0; i < n; i++) {
            if(inorder[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;

        // Perform BFS using Kahn's Algorithm
        while(!q.empty()) {
            int node = q.front();
            q.pop();

            topo.push_back(node); // Add the current node to the order

            // Reduce indegree of neighbouring nodes
            for(auto it : adj[node]) {
                inorder[it]--;

                // Add the neighbour when its indegree becomes 0
                if(inorder[it] == 0) {
                    q.push(it);
                }
            }
        }

        // Reverse to get the required order for the current edge direction
        reverse(topo.begin(), topo.end());

        // If all courses are included, return the order
        // Otherwise, a cycle exists
        if(topo.size() == n) return topo;

        return {};
    }
};