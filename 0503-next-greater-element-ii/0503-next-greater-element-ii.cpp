class Solution {
public:

    void BF(vector<int>& nums, vector<int>& ans, int n) {
        // Using Circular Array concept
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < n; j++) {
                int ind = (i+j)%n;

                if(nums[i] < nums[ind]) {
                    ans[i] = nums[ind];
                    break;
                }
            }
        }
    }

    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);

        BF(nums, ans, n);

        return ans;
    }
};