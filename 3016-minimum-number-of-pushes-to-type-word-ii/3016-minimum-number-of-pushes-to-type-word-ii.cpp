class Solution {
public:
    int minimumPushes(string w) {
        int n = w.size();
        vector<int> f(27);

        for(int i = 0; i < n; i++) f[w[i] - 'a']++;

        sort(f.rbegin(), f.rend());

        int ans = 0, cnt = 1;

        for(int i = 0; i < 26; i++) {
            ans += f[i]*cnt;
            if((i + 1) % 8 == 0) cnt++;
        }

        return ans;
    }
};