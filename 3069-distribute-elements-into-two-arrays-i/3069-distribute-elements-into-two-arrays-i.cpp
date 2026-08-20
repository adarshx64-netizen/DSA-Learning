class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> v1, v2;
        v1 = {nums[0]};
        v2 = {nums[1]};

        for(int i = 2; i < n; i++) {

            int x = nums[i];

            if(v1.back() > v2.back()) v1.push_back(x);
            else v2.push_back(x);
            // if(i&1) v2.push_back(nums[i]);
            // else v1.push_back(nums[i]);
        }

        // if(v1.back() > v2.back()) {
        //     int x = v2.back();
        //     v1.push_back(x);
        //     v2.pop_back();
        // }

        vector<int> res;
        for(int i = 0; i < v1.size(); i++) {
            res.push_back(v1[i]);
        }
        for(int i = 0; i < v2.size(); i++) {
            res.push_back(v2[i]);
        }

        return res;
    }
};