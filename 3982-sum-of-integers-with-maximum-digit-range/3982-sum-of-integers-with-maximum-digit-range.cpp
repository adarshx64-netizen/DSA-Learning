// TC -> O(n)
// SC -> O(1)
class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        vector<int> ans(40);
        
        for(int i = 0; i < nums.size(); i++) {

            string s = to_string(nums[i]);
            sort(s.begin(), s.end());

            int x = s[s.size() - 1] - s[0];

            ans[x] += nums[i];
        }

        for(int i = 39; i >= 0; i--) {

            if(ans[i]) return ans[i];
        }

        return ans[0];
    }
};