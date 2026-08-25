class Solution {
public:
    void nextPermutation(vector<int>& arr) {

        // next_permutation(arr.begin(), arr.end());

        int n = arr.size();
        int idx = -1;

        // Find rightmost position where arr[i] < arr[i+1]
        for(int i = n - 2; i >= 0; i--) {
            if(arr[i] < arr[i+1]) {
                idx = i;
                break;
            }
        }

        // Edge case: last permutation
        if(idx == -1) {
            reverse(arr.begin(), arr.end());
        }
        
        else {
            // Find smallest element > arr[idx] from right
            for(int i = n - 1; i > idx; i--) {
                if(arr[i] > arr[idx]) {
                    swap(arr[i], arr[idx]);
                    break;
                }
            }
            // Reverse everything after idx
            reverse(arr.begin() + idx + 1, arr.end());
        }
    }
};