// TC -> O(n! * n)
// Explanation:
// There are n! permutations.
// For each permutation, copying ds into ans takes O(n).

// SC -> O(n) + O(n)
// O(n) -> recursion stack depth
// O(n) -> freq array

// Auxiliary Space -> O(n)
// (Only recursion stack is counted as auxiliary space.)

class Solution {
public:

    // TC -> O(n! * n)
    // SC -> O(n)
    // O(n) recursion stack.
    // Auxiliary Space -> O(n)
    // Only recursion stack is used.
    // (Ignoring the output array.)
    void optimal(vector<int>& arr, vector<vector<int>>& ans, int ind) {

        // Base Case 
        if(ind == arr.size()) {

            ans.push_back(arr);
            return;
        }

        for(int i = ind; i < arr.size(); i++) {

            swap(arr[ind], arr[i]);
            optimal(arr, ans, ind + 1);

            swap(arr[ind], arr[i]);
        }
    }



    void func(vector<int>& arr, vector<int>& ds, vector<vector<int>>& ans, vector<int>& freq) {

        // Base Case:
        // A complete permutation of size n has been formed.
        if(ds.size() == arr.size()) {
            ans.push_back(ds);   // Copy current permutation into answer.
            return;
        }

        for(int i = 0; i < arr.size(); i++) {

            // Important Observation:
            // freq[i] tells whether arr[i] has already been used
            // in the current permutation. This ensures every element
            // appears exactly once in each permutation.
            if(!freq[i]) {

                freq[i] = 1;          // Mark current element as used.
                ds.push_back(arr[i]); // Choose the current element.

                func(arr, ds, ans, freq); // Explore further choices.

                // Backtracking:
                // Undo the choice so other permutations can be generated.
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& arr) {
        int n = arr.size();

        vector<int> freq(n, 0);   // Tracks which indices are already used.
        vector<vector<int>> ans;
        vector<int> ds;           // Stores the current permutation.

        // func(arr, ds, ans, freq);

        // optimal solution (without using extra space)
        optimal(arr, ans, 0);

        return ans;
    }
};