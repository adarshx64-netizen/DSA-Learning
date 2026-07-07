class Solution {
public:


    // int optimal(vector<int>& nums, int n) {


    // }

    // TC -> O(n logn + n/3)
    // SC -> O(1)
    int better2(vector<int>& nums, int n) {
        sort(nums.begin(), nums.end());

        for(int i = 1; i < n; i += 3) {
            if(nums[i] != nums[i - 1]) return nums[i - 1];
        }
         
        return nums[n - 1];
    }


    // TC -> O(32 * n) (always)
    // SC -> O(1)
    int better(vector<int>& nums, int n) {

        int ans = 0;
        for(int bitIndex = 0; bitIndex <= 31; bitIndex++){

            int cnt = 0;
            for(int i = 0; i < n; i++) {

                // Check bitIndex is set or not
                if(nums[i] & (1 << bitIndex)) cnt++;
            }

            // If cnt is not multiple of 3 then set bitIndex bit
            if(cnt % 3) {
                ans |= (1 << bitIndex);
            }
        }

        return ans;
    }


    

    int singleNumber(vector<int>& nums) {
        int n = nums.size();

        
        // return better(nums, n);
        return better2(nums, n);
    }
};