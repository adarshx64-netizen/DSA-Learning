class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {

        return BF(nums);

        int n = nums.size();
        vector<int> ans;


        // TC -> O(2*n)  SC -> O(1)
        int cnt1=0, cnt2=0;
        int ele1 = INT_MIN, ele2 = INT_MIN;

        for(int i=0; i<n; i++){
            if(cnt1 == 0 && nums[i] != ele2){
                cnt1=1;
                ele1 =nums[i];
            }
            else if(cnt2 == 0 && ele1 != nums[i]){
                cnt2=1;
                ele2=nums[i];
            }
            else if(ele1 == nums[i]) cnt1++;
            else if(ele2 == nums[i]) cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }

        // check
        cnt1=0, cnt2=0;
        for(int i=0; i<n; i++){
            if(ele1 == nums[i]) cnt1++;
            if(ele2 == nums[i]) cnt2++;
        }
        int mini = (int)(n/3) + 1;
        if(cnt1 >= mini) ans.push_back(ele1);
        if(cnt2 >= mini) ans.push_back(ele2);




        // unordered_map<int, int> mp;

        // for(int i=0; i<n; i++){
        //     mp[nums[i]]++;
        // }

        // for(auto it : mp){
        //     if(it.second > (n/3)) ans.push_back(it.first);
        // }




        // TC -> O(n^2)  SC -> O(1) 
        // for(int i=0; i<n; i++){
        //     if(ans.size() == 0 || ans[0] != nums[i]){
        //         int cnt = 0;
        //         for(int j=0; j<n; j++){
        //             if(nums[i] == nums[j]){
        //                 cnt++;
        //             }
        //         }
        //         if(cnt > n/3) ans.push_back(nums[i]);
        //     }
        //     if(ans.size() == 2) break;
        // }

        return ans;
    }

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

            if(res.size() == 2) break;
        }

        return res;
    }
};