class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;

        for(int i = 0; i < n; i++) {
            nums[i] = abs(nums[i]);
        }

        sort(nums.begin(), nums.end());

        int m = n/2;
        for(int i = 0; i < m; i++) {
            long long p = nums[i]*nums[i]*1LL;
            ans -= p;
        }

        for(int i = m; i < n; i++) {
            long long p = nums[i]*nums[i]*1LL;
            ans += p;
        }

        return ans;
    }
};