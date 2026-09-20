class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& arr) {
        
        int n = arr.size();
        sort(arr.begin(), arr.end());

        long long cnt = 0;

        for(int i = 0; i < n; i++) {

            int s = i + 1;
            int e = n - 1;

            int valid = 0;

            while(s <= e) {

                int mid = s + (e - s) / 2;

                if(arr[mid][0] <= arr[i][1]) {
                    valid = mid - i;
                    s = mid + 1;
                }

                else {
                    e = mid - 1;
                }
            }

            cnt += valid;
        }

        return cnt;
    }
};