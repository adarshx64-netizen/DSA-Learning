class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int> suff(n);
        suff[n-1] = nums[n-1];

        for(int i = n-2; i >= 0; i--) {

            suff[i] = min(nums[i], suff[i+1]);
        }

        for(int i = 0; i < n; i++) cout << suff[i] << " ";

        int mx = nums[0];
        for(int i = 0; i < n; i++) {

            mx = max(mx, nums[i]);
            if(mx - suff[i] <= k) return i;
        }

        return -1;
    }
};