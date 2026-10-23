class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int, int>> adj[n+1];
        for(auto it : times) {
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});

        vector<int> dist(n + 1, 1e9);
        dist[k] = 0;

        while(!pq.empty()) {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            for(auto it : adj[node]) {
                int adjNode = it.first;
                int edWt = it.second;

                if(dis + edWt < dist[adjNode]) {
                    dist[adjNode] = dis + edWt;
                    pq.push({dis + edWt, adjNode});
                }
            }
        }

        int maxTime = 0;
        for(int i = 1; i <= n; i++) {
            if(dist[i] == 1e9) return -1;
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;
    }
};