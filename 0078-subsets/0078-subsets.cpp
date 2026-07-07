class Solution {
public:

    void func(vector<vector<int>>& ans, vector<int>& ds, vector<int>& arr, int ind) {

        if(ind == arr.size()) {

            ans.push_back(ds);
            return;
        }

        ds.push_back(arr[ind]);

        // pick 
        func(ans, ds, arr, ind + 1);

        ds.pop_back();

        // not pick
        func(ans, ds, arr, ind + 1);
    }

    // TC -> O(2^n * n)
    // SC -> O(2^n * n)
    void powerSet(vector<vector<int>>& ans, vector<int>& arr) {
        int n = arr.size();
        int no_of_subsets = 1 << n;

        for(int num = 0; num < no_of_subsets; num++) {

            vector<int> temp;
            for(int i = 0; i < n; i++) {

                // Check wether i-th bit is set or not, if set then include else exclude
                if(num & (1 << i)) temp.push_back(arr[i]);
            }

            ans.push_back(temp);
        }
    }





    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;

        // func(ans, ds, nums, 0);
        powerSet(ans, nums);

        return ans;
    }
};