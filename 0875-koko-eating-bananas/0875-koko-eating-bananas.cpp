class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int totalTime) {
        
        int n = piles.size();
        sort(piles.begin(), piles.end());
        int l = 1, h = piles[n-1];

        while(l < h) {

            int mid = l + (h - l) / 2;
            int time = 0;

            for(int i = 0; i < n; i++) {
                time += ((piles[i] + mid - 1) / mid);
            }

            if(time > totalTime) l = mid + 1;
            else h = mid;
        }

        return h;
    }
};