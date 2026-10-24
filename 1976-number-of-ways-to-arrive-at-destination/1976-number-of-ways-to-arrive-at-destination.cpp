class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long mod = 1e9 + 7;
        vector<vector<pair<long long, long long>>> adj(n);
        for(auto it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<long long> dist(n, LLONG_MAX);
        dist[0] = 0;

        vector<long long> ways(n, 0);
        ways[0] = 1;

        priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;
        pq.push({0, 0});

        while(!pq.empty()) {
            long long node = pq.top().second;
            long long dis = pq.top().first;
            pq.pop();

            for(auto it : adj[node]) {
                long long adjNode = it.first;
                long long edWt = it.second;

                if(edWt + dis < dist[adjNode]) {
                    dist[adjNode] = dis + edWt;
                    pq.push({dis + edWt, adjNode});
                    ways[adjNode] = ways[node]%mod;
                }

                else if(dist[adjNode] == dis + edWt) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }

        return ways[n-1]%mod;
    }
};