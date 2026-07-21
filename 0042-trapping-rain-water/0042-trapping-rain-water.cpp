class Solution {
public:
    int trap(vector<int>& h) {
        int n = h.size();
        int ans = 0;
        
        // BF(h, n, ans);
        // BF2(h, n, ans);
        optimal(h, n, ans);


        return ans;
    }


    // TC -> O(N)
    // SC -> O(1)
    void optimal(vector<int>& h, int n, int& ans) {
        int l = 0, r = n-1;
        int lMax = 0, rMax = 0;

        while(l <= r) {

            // If left bar is smaller or equal to right bar
            if(h[l] <= h[r]) {
                // If current left bar is higher than maxLeft, update maxLeft
                if(h[l] >= lMax) lMax = h[l];
                // Water trapped on left is difference between maxLeft and current height
                else ans += lMax - h[l];
                l++; // Move left pointer to the right
            }

            else {
                // If current right bar is higher than maxRight, update maxRight
                if(h[r] >= rMax) rMax = h[r];
                // Water trapped on right is difference between maxRight and current height
                else ans += rMax - h[r];
                r--; // Move right pointer to the left
            }
        }
    }


    // TC -> O(3*N) ≈ O(n)
    // SC -> O(2*N) ≈ O(n)
    void BF(vector<int>& h, int n, int& ans) {
        vector<int> r(n);
        vector<int> l(n);

        for(int i = 0; i < n; i++) {
            if(i == 0) l[i] = h[i];
            else l[i] = max(l[i-1], h[i]);
        }

        for(int i = n-1; i >= 0; i--) {
            if(i == n-1) r[i] = h[i];
            else r[i] = max(r[i+1], h[i]);
        }

        for(int i = 0; i < n; i++) {
            if(h[i] > l[i] || h[i] > r[i]) continue;
            else ans += (min(r[i], l[i]) - h[i]);
        }
    }


    // TC -> O(N^2)
    // SC -> O(1)
    void BF2(vector<int>& h, int n, int& ans) {
        
        for(int i = 0; i < n; i++) {
            int currH = h[i];

            int leftMax = 0;
            for(int j = 0; j <= i; j++) leftMax = max(leftMax, h[j]);

            int rightMax = 0;
            for(int j = i; j < n; j++) rightMax = max(rightMax, h[j]);

            ans += min(leftMax, rightMax) - currH;
        }
    }
};