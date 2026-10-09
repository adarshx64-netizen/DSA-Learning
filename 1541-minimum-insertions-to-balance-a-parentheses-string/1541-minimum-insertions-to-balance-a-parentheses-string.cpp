class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        // stack<int> st;
        int open = 0;
        int ans = 0;

        for(int i = 0; i < n; i++) {
            // if(s[i] == '(') st.push('(');
            if(s[i] == '(') open++;

            else {
                if(i+1 < n && s[i+1] == ')') i++;   // check wather '))' form or not
                else ans++; // if not then add one ')'

                // if(!st.empty()) st.pop();  // remove '('
                if(open > 0) open--;
                else ans++;     // else and one '('
            }
        }

        return ans + 2*open;
    }
};