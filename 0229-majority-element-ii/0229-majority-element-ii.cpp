class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        // return BF(nums);
        // return better(nums);
        return optimal(nums);
    }

    // TC -> O(2*n)  SC -> O(1)
    vector<int> optimal(vector<int>& nums) {

        int n = nums.size();

        int cnt1 = 0, cnt2 = 0;
        int ele1 = INT_MIN, ele2 = INT_MIN;

        // Boyer-Moore Voting Algorithm for finding top 2 majority elements
        for(int i = 0; i < n; i++) {

            // If cnt1 is 0, pick current element as ele1 (but only if it's not ele2)
            if(cnt1 == 0 && ele2 != nums[i]) {
                cnt1 = 1;
                ele1 = nums[i];
            }

            // If cnt2 is 0, pick current element as ele2 (but only if it's not ele1)
            // Use "else if" to prevent same element from being picked for both ele1 and ele2
            else if(cnt2 == 0 && ele1 != nums[i]) {
                cnt2 = 1;
                ele2 = nums[i];
            }

            // If current element matches ele1, increment its count
            else if(ele1 == nums[i]) cnt1++;
            // If current element matches ele2, increment its count
            else if(ele2 == nums[i]) cnt2++;
            // If current element matches neither, cancel out one occurrence of each
            else {cnt1--; cnt2--;}
        }

        // IMPORTANT: After finding candidates, we must verify them because
        // ele1 and ele2 are just candidates from the voting phase, not confirmed majority elements.
        // An element might have survived voting but still not have count > n/3 in the actual array.
        cnt1 = 0; cnt2 = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] == ele1) cnt1++;
            if(nums[i] == ele2) cnt2++;
        }

        vector<int> res;

        // Only add if count actually exceeds n/3 threshold
        if(cnt1 > n/3) res.push_back(ele1);
        if(cnt2 > n/3) res.push_back(ele2);
    
        return res;
    }


    // TC -> O(N), SC -> O(N)
    vector<int> better(vector<int>& nums) {
        // for better solution we can sort or count freq also

        unordered_map<int, int> mpp;   
        for(int i = 0; i < nums.size(); i++) mpp[nums[i]]++;

        vector<int> res;
        for(auto it : mpp) {
            if(it.second > nums.size()/3) res.push_back(it.first);
        }

        return res;
    }


    // TC -> O(n^2)  SC -> O(1) 
    vector<int> BF(vector<int>& nums) {

        int n = nums.size();
        vector<int> res;

        for(int i = 0; i < n; i++) {

            if(res.size() == 0 || res[0] != nums[i]) {
                int cnt = 0;
                for(int j = i; j < n; j++) {

                    if(nums[i] == nums[j]) cnt++;
                }
                if(cnt > n/3) res.push_back(nums[i]);
            }

            // because for n/3 atmost only two ele possible
            if(res.size() == 2) break;
        }

        return res;
    }
};