class Solution {
public:

    // TC ->  O(2*N)
    // SC -> O(1)
    vector<int> optimal(vector<int>& nums, int n) {

        long long XOR = 0;  // store XOR of all number in nums Array
        for(int i = 0; i < n; i++) XOR ^= nums[i];

        // Variable to get the rightmost set bit in overall XOR 
        long long rightmost = (XOR & (XOR - 1)) ^ XOR;

        // Variables to stores XOR of elements in bucket 1 and 2
        int bucket1 = 0, bucket2 = 0;
        for(int i = 0; i < n; i++) {

            // Divide the numbers among bucket 1 and 2 based on rightmost set bit
            if(nums[i] & rightmost) bucket1 ^= nums[i];
            else bucket2 ^= nums[i];
        }        

        // Return the result in sorted order
        if(bucket1 < bucket2) return {bucket1, bucket2};
        return {bucket2, bucket1};
    }

    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        // sort(nums.begin(), nums.end());

        // vector<int> v;
        // for(int i = 1; i < n; i += 2) {

        //     if(nums[i] != nums[i - 1]) {v.push_back(nums[i - 1]); i--;}
        // }

        // if(nums[n - 2] != nums[n - 1] && nums[n - 1] != v.back()) v.push_back(nums[n - 1]);

        // return v;

        return optimal(nums, n);
    }
};