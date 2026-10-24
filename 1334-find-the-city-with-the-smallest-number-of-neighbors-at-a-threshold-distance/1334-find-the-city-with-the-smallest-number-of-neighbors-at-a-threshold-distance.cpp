class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        // return solveUsingFloydWarshallAlgorithm(n, edges, distanceThreshold);
        return solveUsingDijsktraAlgorithm(n, edges, distanceThreshold);
    }

    int solveUsingFloydWarshallAlgorithm(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Create a cost matrix.
        // cost[i][j] stores the shortest distance from city i to city j.
        // INT_MAX means there is no direct path between the cities.
        vector<vector<int>> cost(n, vector<int>(n, INT_MAX));

        // Store the given edges in the cost matrix.
        // The graph is undirected, so add edges in both directions.
        for(auto it : edges) {
            cost[it[0]][it[1]] = it[2];
            cost[it[1]][it[0]] = it[2];
        }

        // Distance from a city to itself is always 0.
        for(int i = 0; i < n; i++)
            cost[i][i] = 0;

        // Floyd-Warshall Algorithm:
        // Find the shortest distance between every pair of cities.
        // 'via' is the intermediate city used to reach city j from city i.
        for(int via = 0; via < n; via++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {

                    // Check whether both parts of the path exist.
                    // This prevents adding INT_MAX to another distance.
                    if(cost[i][via] != INT_MAX &&
                       cost[via][j] != INT_MAX) {

                        // Update the distance if going through 'via'
                        // gives a shorter path from i to j.
                        cost[i][j] = min(cost[i][j],
                                         cost[i][via] + cost[via][j]);
                    }
                }
            }
        }

        // Find the city that can reach the fewest other cities
        // within the given distance threshold.
        int cntCity = n;
        int city = -1;

        for(int i = 0; i < n; i++) {
            int cnt = 0;

            // Count cities reachable from city i within the threshold.
            for(int j = 0; j < n; j++) {
                if(cost[i][j] <= distanceThreshold)
                    cnt++;
            }

            // Update the answer when the count is smaller.
            // Use <= because ties must select the city with the
            // greatest city number.
            if(cnt <= cntCity) {
                cntCity = cnt;
                city = i;
            }
        }

        // Return the city with the fewest reachable cities.
        return city;
    }

    int solveUsingDijsktraAlgorithm(int n, vector<vector<int>>& edges, int distanceThreshold) {

        int cntCity = n;
        int cityNo = -1;

        // Run Dijsktra's for every city
        for(int city = 0; city < n; city++) {
            vector<int> dist(n, INT_MAX);
            dijsktra(n, city, edges, distanceThreshold, dist);

            int cnt = 0;
            for(int city = 0; city < n; city++) {
                if(dist[city] <= distanceThreshold) cnt++;
            }

            if(cnt <= cntCity) {
                cntCity = cnt;
                cityNo = city;
            }
        }

        return cityNo;
    }

    void dijsktra(int n, int city, vector<vector<int>>& edges, int distanceThreshold, vector<int> &dist) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto it : edges) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, city});     // {dist, node}
        dist[city] = 0;

        while(!pq.empty()) {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            if(dis > dist[node]) continue;

            for(auto it : adj[node]) {
                int adjNode = it.first;
                int wt = it.second;

                if(dis + wt < dist[adjNode]) {
                    dist[adjNode] = dis + wt;
                    pq.push({dis + wt, adjNode});
                }
            }
        }
    }
};