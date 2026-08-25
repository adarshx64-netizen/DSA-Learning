class Solution {
public:
    bool check(vector<int>& nums) {
        
        int n = nums.size();

        int cnt = 0;

        for(int i = 1; i < n; i++) {

            if(nums[i] < nums[i-1]) cnt++;

            if(cnt >= 2) break;
        }

        if(nums[n-1] > nums[0] && cnt == 0) return true;
        if(nums[n-1] > nums[0] || cnt >= 2) return false;
        return true;
    }
};