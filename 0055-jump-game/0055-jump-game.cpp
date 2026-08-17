class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        // Initialise a variable maxIndex to keep track of the farthest index we can reach from the start
        // Iterate through each index of the array and at each interaction check if the current index is 
        // greater than the maximum index we can reach so far.

        int n = nums.size();
        int maxIndex = 0;

        // Edge Case
        if(n == 1) return true;

        for(int i = 0; i < n; i++) {

            maxIndex = max(maxIndex, i + nums[i]);

            if(maxIndex >= n-1) return true;
            if(maxIndex <= i) return false;
        }

        return false;
    }
};