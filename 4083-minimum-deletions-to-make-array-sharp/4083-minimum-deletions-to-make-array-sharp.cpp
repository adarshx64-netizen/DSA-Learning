class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int cnt = 0;
        int n = nums.size();

        for(int i = 1; i < n; i++) {
            if(nums[i-1] == nums[i]) cnt++;
        }

        return cnt;
    }
};