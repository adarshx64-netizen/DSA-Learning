class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {

        // Brute Force
        // long long ans = 0;
        // BF(nums, ans);
        // return ans;

        // Optimal
        // We use the identity:
        // Sum of Subarray Ranges = Sum of Subarray Maximums − Sum of Subarray Minimums
        return sumOfSubarrayMaximums(nums) - sumOfSubarrayMinimums(nums);
    }

    // Sum of Minimums
    // TC -> O(5*N)
    // SC -> O(4*N)
    long long sumOfSubarrayMinimums(vector<int>& nums) {

        int n = nums.size();

        vector<int> nse(n);
        vector<int> psee(n);

        findNSE(nums, n, nse);
        findPSEE(nums, n, psee);

        long long sum = 0;

        for(int i = 0; i < n; i++) {

            long long left = i - psee[i];
            long long right = nse[i] - i;

            sum += left * right * 1LL * nums[i];
        }

        return sum;
    }

    // Sum of Maximums
    // TC -> O(5*N)
    // SC -> O(4*N)
    long long sumOfSubarrayMaximums(vector<int>& nums) {

        int n = nums.size();

        vector<int> nge(n);
        vector<int> pgee(n);

        findNGE(nums, n, nge);
        findPGEE(nums, n, pgee);

        long long sum = 0;

        for(int i = 0; i < n; i++) {

            long long left = i - pgee[i];
            long long right = nge[i] - i;

            sum += left * right * 1LL * nums[i];
        }

        return sum;
    }

    // Next Smaller Element
    // TC -> O(2*N)
    // SC -> O(2*N)
    void findNSE(vector<int>& nums, int n, vector<int>& nse) {

        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() && nums[st.top()] >= nums[i])
                st.pop();

            nse[i] = st.empty() ? n : st.top();

            st.push(i);
        }
    }

    // Previous Smaller or Equal Element
    // TC -> O(2*N)
    // SC -> O(2*N)
    void findPSEE(vector<int>& nums, int n, vector<int>& psee) {

        stack<int> st;

        for(int i = 0; i < n; i++) {

            while(!st.empty() && nums[st.top()] > nums[i])
                st.pop();

            psee[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }
    }

    // Next Greater Element
    // TC -> O(2*N)
    // SC -> O(2*N)
    void findNGE(vector<int>& nums, int n, vector<int>& nge) {

        stack<int> st;

        for(int i = n - 1; i >= 0; i--) {

            while(!st.empty() && nums[st.top()] <= nums[i])
                st.pop();

            nge[i] = st.empty() ? n : st.top();

            st.push(i);
        }
    }

    // Previous Greater or Equal Element
    // TC -> O(2*N)
    // SC -> O(2*N)
    void findPGEE(vector<int>& nums, int n, vector<int>& pgee) {

        stack<int> st;

        for(int i = 0; i < n; i++) {

            while(!st.empty() && nums[st.top()] < nums[i])
                st.pop();

            pgee[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }
    }


    // Brute Force
    // TC -> O(N^2)
    // SC -> O(1)
    void BF(vector<int>& nums, long long &ans) {

        int n = nums.size();

        for(int i = 0; i < n; i++) {

            int mx = nums[i];
            int mn = nums[i];

            for(int j = i; j < n; j++) {

                mx = max(mx, nums[j]);
                mn = min(mn, nums[j]);

                ans += (mx - mn);
            }
        }
    }
};