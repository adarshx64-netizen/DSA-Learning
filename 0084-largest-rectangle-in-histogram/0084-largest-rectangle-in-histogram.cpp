class Solution {
public:
    // Time Complexity: O(N) + O(N). For loop used along with a while loop
    // Space Complexity: O(N). Used for stack
    int optimal(vector<int>& arr) {
        stack<int> st;
        int maxArea = 0;
        for(int i = 0; i < arr.size(); i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) {
                int ele = arr[st.top()];
                st.pop();

                int nse = i;
                int pse = st.empty() ? -1 : st.top();

                maxArea = max(maxArea, ele * (nse - pse - 1));
            }
            st.push(i);
        }

        while(!st.empty()) {
            int ele = arr[st.top()];
            st.pop();

            int nse = arr.size();
            int pse = st.empty() ? -1 : st.top();

            maxArea = max(maxArea, ele * (nse - pse - 1));
        }

        return maxArea;
    }

    // TC -> O(5*N)
    // SC -> O(4*N)
    int better(vector<int>& arr) {
        int n = arr.size();
        int maxArea = 0;
        vector<int> pse = findPSE(arr, n);  // TC -> O(2*N), SC -> O(2*N)
        vector<int> nse = findNSE(arr, n);  // TC -> O(2*N), SC -> O(2*N)
        for(int i = 0; i < arr.size(); i++) { // TC -> O(N)
            int area = arr[i] * (nse[i] - pse[i] - 1);
            maxArea = max(maxArea, area);
        } 
        return maxArea;
    }

    int largestRectangleArea(vector<int>& heights) {
        // return better(heights);
        return optimal(heights);
    }

    vector<int> findNSE(vector<int>& arr, int n) {
        stack<int> st;
        vector<int> nse(n);
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            nse[i] = (st.empty()) ? n : st.top();
            st.push(i);
        }
        return nse;
    }

    vector<int> findPSE(vector<int>& arr, int n) {
        stack<int> st;
        vector<int> pse(n);
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return pse;
    }
};