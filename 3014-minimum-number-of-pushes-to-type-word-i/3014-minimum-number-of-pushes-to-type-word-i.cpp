class Solution {
public:
    int minimumPushes(string w) {
        int n = w.size();
        int blocks = n / 8;
        int rem = n % 8;

        return (4 * blocks * (blocks + 1)) + (rem * (blocks + 1));


        // int ans = 0;
        // int cnt = 1;

        // while(n / 8) {
        //     int x = n / 8;
        //     ans += (8 * cnt);
        //     cnt++;
        //     n -= 8;
        // }
        // ans += n*cnt;
        // return ans;
    }
};


