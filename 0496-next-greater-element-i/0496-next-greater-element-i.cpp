class Solution {
public:

    void better(vector<int>& nums1, vector<int>& nums2, vector<int>& ans) {
        unordered_map<int, int> mpp;
        stack<int> st;

        for(int i = nums2.size() - 1; i >= 0; i--) {
            while(!st.empty() && st.top() <= nums2[i]) st.pop();

            if(st.empty()) mpp[nums2[i]] = -1;
            else mpp[nums2[i]] = st.top();

            st.push(nums2[i]);
        }

        for(int x : nums1) ans.push_back(mpp[x]);
    }



    void BF(vector<int>& nums1, vector<int>& nums2, vector<int>& ans) {
        for(int x : nums1) {

            for(int i = 0; i < nums2.size(); i++) {
                if(nums2[i] == x){
                    bool ok = false;

                    while(i < nums2.size()) {
                        if(nums2[i] > x) {
                            ans.push_back(nums2[i]);
                            ok = true;
                            break;
                        }
                        i++;
                    }
                    if(!ok) ans.push_back(-1);
                }
            }
        }
    }

    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        // BF(nums1, nums2, ans);
        better(nums1, nums2, ans);
        return ans;
    }
};