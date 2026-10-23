// TC -> O(k*N)
// SC -> O(V + E)
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Create adjacency list: {neighbor, flight cost}
        vector<vector<pair<int, int>>> adj(n);
        for(auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        // Queue stores: {stops, {node, total cost}}
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}}); // Start with 0 stops and 0 cost

        // dist[node] stores the minimum cost found so far to reach that node
        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;

            // Do not explore paths exceeding k stops
            if(stops > k) continue;

            // Explore all outgoing flights from the current node
            for(auto itr : adj[node]) {
                int adjNode = itr.first;
                int edWt = itr.second;

                // Relax the edge if it gives a cheaper cost
                if(cost + edWt < dist[adjNode] && stops <= k) {
                    dist[adjNode] = cost + edWt;

                    // Taking one more flight increases the stop count by 1
                    q.push({stops + 1, {adjNode, cost + edWt}});
                }
            }
        }

        // Return -1 if destination is unreachable
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};