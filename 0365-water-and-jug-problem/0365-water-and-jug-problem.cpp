class Solution {
public:
    bool canMeasureWater(int x, int y, int target) {

        // Use Bézout's Identity
        // return ((target <= x + y) && (target % gcd(x, y) == 0));

        return bfs(x, y, target);
    }

    bool bfs(int x, int y, int target) {
        vector<int> vis(x+y+1, 0);
        vis[0] = 1;

        queue<int> q;
        q.push(0);

        int steps[] = {x, -x, y, -y};

        while(!q.empty()) {
            int node = q.front();
            q.pop();

            if(node == target) return true;

            // check for all steps
            for(int i = 0; i < 4; i++) {
                int newN = node + steps[i];

                if(0 <= newN && newN <= x+y && !vis[newN]) {
                    vis[newN] = 1;
                    q.push(newN);
                }
            }
        }

        return false;
    }
};