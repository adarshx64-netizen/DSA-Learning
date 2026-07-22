class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        // stack<int> st;
        vector<int> ans;

        for(int i = 0; i < a.size(); i++) {
            /* Push the asteroid in stack if a right moving asteroid is seen */
            // if(a[i] > 0) st.push(a[i]);
            if(a[i] > 0) ans.push_back(a[i]);

            /* Else if the asteroid is moving right, perform the collisions */
            else {
                /* Until the right moving asteroids are smaller in size, keep on destroying them */ 
                // while((!st.empty()) && (st.top() < abs(a[i]))) st.pop();
                while(!ans.empty() && ans.back() > 0 && ans.back() < abs(a[i])) ans.pop_back();
                // if(!st.empty() && st.top() == abs(a[i])) {
                //     st.pop();
                // }
                // else if(st.empty() || st.top() < 0){
                //     st.push(a[i]);
                // }
                /* If there is right moving asteroid which is of same size */
                if(!ans.empty() && ans.back() == abs(a[i])) {
                    ans.pop_back();  // Destroy both Asteroids
                }
                /* Otherwise, if there is no left moving asteroid, the right moving asteroid will not be destroyed */
                else if(ans.empty() || ans.back() < 0){
                    ans.push_back(a[i]);
                }
            }
        }

        // while(!st.empty()) {
        //     ans.push_back(st.top());
        //     st.pop();
        // }

        // reverse(ans.begin(), ans.end());
        return ans;
    }
};