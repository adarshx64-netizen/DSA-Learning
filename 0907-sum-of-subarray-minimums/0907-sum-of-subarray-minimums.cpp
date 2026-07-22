class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;

        // BF(arr, sum, n);
        // return sum;

        vector<int> nse(n);
        findNSE(arr, n, nse); // TC -> O(2*N) SC -> 2*N
        vector<int> psee(n);
        findPSEE(arr, n, psee); // TC -> O(2*N) SC -> 2*N
        int total = 0;
        int mod = 1e9 + 7;

        for(int i = 0; i < n; i++) {  // TC -> O(N)
            int left = i - psee[i];
            int right = nse[i] - i;

            total = (total + (1LL*left*right*arr[i]) % mod) % mod ;
        }

        return total;
    }

    void findNSE(vector<int>& arr, int n, vector<int>& nse) {
        stack<int> st;

        for(int i = n-1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }
    }

    // Function for finding Previous Smaller or Equal Element
    // Equal Element for Edge Case handle
    void findPSEE(vector<int>& arr, int n, vector<int>& psee) {
        stack<int> st;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            psee[i] = st.empty() ? -1  : st.top();
            st.push(i);
        }
    }

    // TC -> O(N^2)
    // SC -> O(1)
    void BF(vector<int>& arr, int& sum, int& n) {
        int mod = 1e9 + 7;
        for(int i = 0; i < n; i++) {
            int mini = arr[i];
            for(int j = i; j < n; j++) {
                mini = min(mini, arr[j]);
                sum = (sum + mini) % mod;
            }
        }
    }
};