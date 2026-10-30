class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<vector<int>> dist(n, vector<int>(k+1, INT_MAX));
        dist[0][1] = 0;     // {min dist to reach at this node, streak len}

        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 1}});   // {cost, node, streak_len}

        while(!pq.empty()) {
            int dis = pq.top().first;
            int node = pq.top().second.first;
            int r = pq.top().second.second;
            pq.pop();

            if(dis > dist[node][r]) continue;

            for(auto it : adj[node]) {
                int adjNode = it.first;
                int wt = it.second;

                int new_r = 1;

                if(labels[node] == labels[adjNode]) new_r = r+1;
                if(new_r > k) continue;

                if(dis + wt < dist[adjNode][new_r]) {
                    dist[adjNode][new_r] = dis + wt;
                    pq.push({dis+wt, {adjNode, new_r}});
                }
            }
        }

        int ans = INT_MAX;
        for(int i = 0; i <= k; i++) {
            ans = min(ans, dist[n-1][i]);
        }

        return ans == INT_MAX ? -1 : ans;
    }
};