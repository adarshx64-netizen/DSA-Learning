class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        int n = arr.size();
        int last = arr[n-1];

        unordered_set<int> st(arr.begin(), arr.end());

        int i;
        for(i = 1; i <= last; i++) {
            if(st.find(i) == st.end()) k--;
            if(k == 0) break;
        }

        if(k) {
            while(--k) i++;
        }

        return i;
    }
};