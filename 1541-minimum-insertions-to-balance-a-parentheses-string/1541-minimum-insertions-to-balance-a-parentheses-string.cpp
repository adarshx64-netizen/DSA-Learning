class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        stack<int> st;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            if(s[i] == '(') st.push('(');

            else {
                if(i+1 < n && s[i+1] == ')') i++;
                else ans++;

                if(!st.empty()) st.pop();
                else ans++;
            }
        }

        return ans + 2*st.size();
    }
};