class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        return solveUsingFloydWarshallAlgorithm(n, edges, distanceThreshold);
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
        int minCnt = n;
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
            if(cnt <= minCnt) {
                minCnt = cnt;
                city = i;
            }
        }

        // Return the city with the fewest reachable cities.
        return city;
    }
};