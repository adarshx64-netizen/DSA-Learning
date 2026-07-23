class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        BF(nums, ans, n);
        return ans;
    }

    void BF(vector<int>& nums, long long& ans, int n) {

        for(int i = 0; i < n; i++) {
            int mx = INT_MIN;
            int mn = INT_MAX;
            for(int j = i; j < n; j++) {
                mx = max(mx, nums[j]);
                mn = min(mn, nums[j]);

                ans += (mx - mn);
            }
            cout << mx << " " << mn << endl;
            // ans += (mx - mn);
        }
    }
};