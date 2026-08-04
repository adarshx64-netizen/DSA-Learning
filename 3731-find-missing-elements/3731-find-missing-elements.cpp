class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        if (n == 0) return ans;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 1; i++) {
            int first = nums[i];
            int last = nums[i + 1];
            
            for (int j = first + 1; j < last; j++) {
                ans.push_back(j);
            }
        }

        return ans;
    }
};

