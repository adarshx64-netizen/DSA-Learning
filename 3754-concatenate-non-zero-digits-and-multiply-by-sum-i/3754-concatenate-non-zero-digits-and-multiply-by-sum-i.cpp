class Solution {
public:

// TC -> O(d), d is number of digits
// SC -> O(1)
    long long sumAndMultiply(int n) {
        int sum = 0;
        int cnt1 = 0, cnt2 = 0;
        int c = n;

        while(c) {
            cnt1++;

            if(c%10) {cnt2++; sum += c%10;}
            c /= 10;
        }

        long long pow1 = pow(10, cnt1 - 1), pow2 = pow(10, cnt2 - 1);
        long long ans = 0;

        while(pow1) {
            int d = n / pow1;

            if(d) ans = ans * 10 + d;

            n %= pow1;
            pow1 /= 10;
        }

    return ans * 1LL * sum;

// Brute Force:-
        // vector<int> v;
        // int copy = n;

        // while(copy) {
        //     int rem = copy % 10;
        //     if(rem) v.push_back(rem);
        //     copy /= 10;
        // }

        // int sum = 0;
        // long long ans = 0;
        // for(int i = v.size() - 1; i >= 0; i--) {

        //     ans = (ans * 10) + v[i];
        //     sum += v[i];
        // }

        // return 1LL * ans * sum;
    }
};












